#include "CGraphe.h"
#include "CException.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGraphe::CGraphe()
{
	ppqGRASommets = nullptr;
	uiGRANbSommets = 0;
	uiGRANbArcs = 0;
}

/*****************************
Constructeur de recopie
******************************
Entrée : CSommet & sommet);
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
*****************************/
CGraphe::CGraphe(CGraphe & graphe)
{
	if(ppqGRASommets != nullptr) {
		ppqGRASommets = nullptr;
		delete(ppqGRASommets);
	}

	// Allocation de la liste sommet
	ppqGRASommets = (CSommet **)malloc(sizeof(CSommet*) * graphe.uiGRANbSommets);
	
	if(ppqGRASommets == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqGRASommets = graphe.ppqGRASommets;
	uiGRANbSommets = graphe.uiGRANbSommets;
	uiGRANbArcs = graphe.uiGRANbArcs;
}

/*****************************
Constructeur de confort
******************************
Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGraphe::CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets)
{
	if(ppqGRASommets != nullptr) {
		ppqGRASommets = nullptr;
		delete(ppqGRASommets);
	}

	// Allocation de la liste sommet
	ppqGRASommets = (CSommet **)malloc(sizeof(CSommet*) * uiNbSommets);
	
	if(ppqGRASommets == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqGRASommets = sommets;
	uiGRANbSommets = uiNbSommets;
	uiGRANbArcs = uiNbArcs;
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet est détruit
*****************************/
CGraphe::~CGraphe()
{
	unsigned int uiBoucle = 0;

	// Boucle pour liberer la liste des sommets
	while(uiBoucle != uiGRANbSommets) {
		ppqGRASommets[uiBoucle] = nullptr;
		delete[] ppqGRASommets[uiBoucle];
		uiBoucle++;
	}

	ppqGRASommets = nullptr;
	delete[] ppqGRASommets;
}

// Accesseurs

/*****************************
Methode : Lire Nombre Sommets
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiGRANbSommets
Entraine : retourne l'attribut
*****************************/
unsigned int CGraphe::GRAGetNbSommets()
{
	return uiGRANbSommets;
}

/*****************************
Methode : Modifier Nombre Sommets
******************************
Entrée : unsigned int uiNbSommets
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CGraphe::GRASetNbSommets(unsigned int uiNbSommets)
{
	uiGRANbSommets = uiNbSommets;
}

/*****************************
Methode : Lire Nombre Arcs
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiGRANbArcs
Entraine : retourne l'attribut
*****************************/
unsigned int CGraphe::GRAGetNbArcs()
{
	return uiGRANbArcs;
}

/*****************************
Methode : Modifier Nombre Arcs
******************************
Entrée : unsigned int uiNbArcs
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CGraphe::GRASetNbArcs(unsigned int uiNbArcs)
{
	uiGRANbArcs = uiNbArcs;
}

/*****************************
Methode : Ajouter Sommet
******************************
Entrée : unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant
Necessité : néant
Sortie : néant
Entraine : ajoute un nouveau sommet au graphe
*****************************/
void CGraphe::GRAAjoutSommet(unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant)
{
	// Unicité avant création d'un sommet
	CSommet * SOMlistSommets = GRATrouverSommet(uiSommet);
	if(SOMlistSommets != nullptr)
		throw CException(ECHECNEWSOMMET, "Echec il existe deja un sommet avec ce numero");

	// Création d'un nouveau sommet
	CSommet * SOMnewSommet = new CSommet(uiSommet, ppqArrivant, ppqPartant);

	// Vérification de la bonne création
	if(SOMnewSommet == nullptr)
		throw CException(ECHECNEWSOMMET, "Echec de la création d'un nouveau sommet");

	// Vérification d'une présence de liste
	if(ppqGRASommets == nullptr) {
		// Création d'une liste avec comme taille 1 sommet
		ppqGRASommets = (CSommet **)malloc(sizeof(CSommet *));
		// Vérification de la bonne création
		if(ppqGRASommets == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}
	// Dans le cas où la liste est déjà existante
	else {
		// Réallocation + 1 sommet
		(CSommet **)realloc(ppqGRASommets, sizeof(ppqGRASommets) + sizeof(CSommet *));
		// Vérification de la bonne réallocation
		if(ppqGRASommets == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Ajout à la liste du graphe le sommet et incrément son nombre
	ppqGRASommets[uiGRANbSommets] = SOMnewSommet;
	uiGRANbSommets++;

	if(ppqArrivant != nullptr && ppqPartant != nullptr)
		uiGRANbArcs++;
}

/*****************************
Methode : Supprimer Sommet
******************************
Entrée : CSommet * sommet
Necessité / Préconditions : fournir un objet en paramètre non nul
Sortie : néant
Entraine : supprime un sommet au graphe
*****************************/
void CGraphe::GRASupprimerSommet(CSommet * sommet)
{
	unsigned int uiBoucle = 0;

	// Permet de supprimer les arcs liés à ce sommet
	sommet->SOMViderSommet();

	// Vérification de la présence d'une liste non nul
	if(ppqGRASommets == nullptr)
		throw CException(ECHECNONTROUVE, "Echec la liste des sommets est nul");

	// Realloc de la bonne taille - 1 sommet
	(CSommet **)realloc(ppqGRASommets, sizeof(ppqGRASommets) - sizeof(CSommet *));
	if(ppqGRASommets == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	// Suppression à la liste du graphe le sommet et décrémentant son nombre
	delete(ppqGRASommets[uiGRANbSommets]);
	uiGRANbSommets--;
}

/*****************************
Methode : Modifier Sommet
******************************
Entrée : unsigned int uiNum, CSommet * SOMSommet
Necessité / Préconditions : fournir un objet en paramètre non nul
Sortie : néant
Entraine : modifie un sommet au graphe
*****************************/
void CGraphe::GRAModifierSommet(unsigned int uiNum, CSommet * SOMSommet)
{
	// Unicité avant modification d'un sommet
	CSommet * SOMlistSommets = GRATrouverSommet(uiNum);
	if(SOMlistSommets != nullptr)
		throw CException(ECHECNEWSOMMET, "Echec il existe deja un sommet avec ce numero");

	// FAIRE ICI UNE MODIF DE TOUT LES ARCS EN RELATION AVEC SOMSommet num actuel avant chang
	unsigned int uiBoucle = 0;

	// Permet d'actualiser le nouveau numéro du sommet aux arcs précédant
	while(uiBoucle != SOMSommet->SOMGetNbrArcArrivant) {
		SOMSommet->SOMGetListArcArrivant[uiBoucle]->ARCSetDestination(uiNum);
		uiBoucle++;
	}
	// Permet de changer le numéro du sommet
	SOMSommet->SOMSetNum(uiNum);
}

/*****************************
Methode : Récupérer Sommet
******************************
Entrée : unsigned int uiSommet
Necessité : GRATrouverSommet
Sortie : néant
Entraine : récupère un sommet du graphe
*****************************/
CSommet * CGraphe::GRAGetSommet(unsigned int uiSommet)
{
	return GRATrouverSommet(uiSommet);
}

/*****************************
Methode : Ajouter Arc
******************************
Entrée : unsigned int uiDestination, CSommet * sommet
Necessité : néant
Sortie : néant
Entraine : ajoute un nouvel arc au graphe
*****************************/
void CGraphe::GRAAjoutArc(unsigned int uiDestination, CSommet * SOMSommet)
{

	CSommet * SOMDestination = GRATrouverSommet(uiDestination);
	CArc * ARCNewArc = nullptr;

	if(SOMDestination == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur la uiDestination n'a pas été trouvée");
	else {
		// Verification d'unicite dans le lien / Impossible d'avoir 1 -> 2 et 1 -> 2
		if(GRATrouverArc(SOMSommet, SOMDestination) != nullptr)
			throw CException(ECHECDOUBLONARC, "Erreur doublon d'arc");

		// Creation d'un nouvel arc et affectation
		ARCNewArc = new CArc(uiDestination);
		SOMSommet->SOMAddArcPartant(ARCNewArc);
		SOMDestination->SOMAddArcArrivant(ARCNewArc);
	}
}

/*****************************
Methode : Supprimer Arc
******************************
Entrée : CArc ** ARCarc
Necessité : néant
Sortie : néant
Entraine : supprime un arc au graphe
*****************************/
void CGraphe::GRASupprimerArc(CArc ** ARCarc)
{
	unsigned int uiNumSource = 0, uiNumDestination = 0;
	CSommet * SOMSource = nullptr, * SOMDestination = nullptr;
	CArc * ARCarc = nullptr;

	if(ARCarc == nullptr && ARCarc[0] == nullptr && ARCarc[1] == nullptr)
		throw CException(ERREURARGS, "Erreur l'argument n'est pas correcte");

	uiNumSource = ARCarc[0]->ARCGetDestination;
	uiNumDestination = ARCarc[1]->ARCGetDestination;


	// Rercherche et affectation des sommets
	SOMSource = GRATrouverSommet(uiNumSource);
	if(SOMSource == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur sommet non trouvé");

	SOMDestination = GRATrouverSommet(uiNumDestination);
	if(SOMDestination == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur sommet non trouvé");

	// Suppression des informations de l'arc dans le sommet source en question
	ARCarc = GRATrouverArc(SOMSource->SOMGetListArcPartant, SOMDestination);
	if(ARCarc == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur arc non trouvé");

	delete[] ARCarc;

	// Suppression des informations de l'arc dans le sommet destination en question
	ARCarc = GRATrouverArc(SOMDestination->SOMGetListArcPartant, SOMDestination);
	if(ARCarc == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur arc non trouvé");

	delete[] ARCarc;
}

/*****************************
Methode : Afficher Arc
******************************
Entrée : néant
Necessité : néant
Sortie : affichage du graphe
Entraine : affichage du graphe dans la console
*****************************/
void CGraphe::GRAAfficherGraphe()
{

}

/*****************************
Methode : Trouver Sommet
******************************
Entrée : unsigned int uiSommet
Necessité : néant
Sortie : CSommet * 
Entraine : cherche et renvoi le sommet
*****************************/
CSommet * CGraphe::GRATrouverSommet(unsigned int uiSommet)
{
	for(unsigned int uiBoucleSommet = 0 ; uiBoucleSommet < uiGRANbSommets ; uiBoucleSommet++) {
		if(ppqGRASommets[uiBoucleSommet]->SOMGetNum == uiSommet)
			return ppqGRASommets[uiBoucleSommet];

		uiBoucleSommet++;
	}

	return nullptr;
}

/*****************************
Methode : Trouver Arc
******************************
Entrée : CSommet * SOMSource, CSommet * SOMDestination
Necessité : néant
Sortie : CArc **
Entraine : cherche et renvoi l'arc
*****************************/
CArc ** CGraphe::GRATrouverArc(CSommet * SOMSource, CSommet * SOMDestination)
{
	CArc * ARCArcActuelArrivant = nullptr, * ARCArcActuelPartant = nullptr;
	CArc ** ARCSourceDestination = nullptr;

	for(unsigned int uiBoucleSommet = 0 ; uiBoucleSommet < uiGRANbSommets ; uiBoucleSommet++) {
		for(unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < uiGRANbArcs ; uiBoucleArcs++) {
			
			ARCArcActuelArrivant = ppqGRASommets[uiBoucleSommet]->SOMGetListArcArrivant[uiBoucleArcs];
			ARCArcActuelPartant = ppqGRASommets[uiBoucleSommet]->SOMGetListArcPartant[uiBoucleArcs];
			
			if(ARCArcActuelArrivant->ARCGetDestination ==  SOMSource->SOMGetNum && ARCArcActuelPartant->ARCGetDestination == SOMDestination->SOMGetNum) {
				ARCSourceDestination = (CArc **)malloc(sizeof(CArc *) * 2);
				
				if(ARCSourceDestination == nullptr)
					throw CException(ECHECALLOCATION, "Echec de l'allocation");

				ARCSourceDestination[0] = ARCArcActuelArrivant;
				ARCSourceDestination[1]= ARCArcActuelPartant;

				return ARCSourceDestination;
			}

			uiBoucleArcs++;
		}

		uiBoucleSommet++;
	}
	
	return ARCSourceDestination;
}