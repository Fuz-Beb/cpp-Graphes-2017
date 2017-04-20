#include "CGraphe.h"
#include "CException.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
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
Entr�e : CSommet & sommet);
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
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
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqGRASommets = graphe.ppqGRASommets;
	uiGRANbSommets = graphe.uiGRANbSommets;
	uiGRANbArcs = graphe.uiGRANbArcs;
}

/*****************************
Constructeur de confort
******************************
Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
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
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqGRASommets = sommets;
	uiGRANbSommets = uiNbSommets;
	uiGRANbArcs = uiNbArcs;
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet est d�truit
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
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : unsigned int uiNbSommets
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CGraphe::GRASetNbSommets(unsigned int uiNbSommets)
{
	uiGRANbSommets = uiNbSommets;
}

/*****************************
Methode : Lire Nombre Arcs
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : unsigned int uiNbArcs
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CGraphe::GRASetNbArcs(unsigned int uiNbArcs)
{
	uiGRANbArcs = uiNbArcs;
}

/*****************************
Methode : Ajouter Sommet
******************************
Entr�e : unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant
Necessit� : n�ant
Sortie : n�ant
Entraine : ajoute un nouveau sommet au graphe
*****************************/
void CGraphe::GRAAjoutSommet(unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant)
{
	// Unicit� avant cr�ation d'un sommet
	CSommet * SOMlistSommets = GRATrouverSommet(uiSommet);
	if(SOMlistSommets != nullptr)
		throw new CException(ECHECNEWSOMMET, "Echec il existe deja un sommet avec ce numero");

	// Cr�ation d'un nouveau sommet
	CSommet * SOMnewSommet = new CSommet(uiSommet, ppqArrivant, ppqPartant);

	// V�rification de la bonne cr�ation
	if(SOMnewSommet == nullptr)
		throw new CException(ECHECNEWSOMMET, "Echec de la cr�ation d'un nouveau sommet");

	// V�rification d'une pr�sence de liste
	if(ppqGRASommets == nullptr) {
		// Cr�ation d'une liste avec comme taille 1 sommet
		ppqGRASommets = (CSommet **)malloc(sizeof(CSommet *));
		// V�rification de la bonne cr�ation
		if(ppqGRASommets == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	}
	// Dans le cas o� la liste est d�j� existante
	else {
		// R�allocation + 1 sommet
		(CSommet **)realloc(ppqGRASommets, sizeof(ppqGRASommets) + sizeof(CSommet *));
		// V�rification de la bonne r�allocation
		if(ppqGRASommets == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Ajout � la liste du graphe le sommet et incr�ment son nombre
	ppqGRASommets[uiGRANbSommets] = SOMnewSommet;
	uiGRANbSommets++;

	if(ppqArrivant != nullptr && ppqPartant != nullptr)
		uiGRANbArcs++;
}

/*****************************
Methode : Supprimer Sommet
******************************
Entr�e : CSommet & sommet
Necessit� / Pr�conditions : fournir un objet en param�tre non nul
Sortie : n�ant
Entraine : supprime un sommet au graphe
*****************************/
void CGraphe::GRASupprimerSommet(CSommet & sommet)
{
	unsigned int uiBoucle = 0;

	// Permet de supprimer les arcs li�s � ce sommet
	sommet.SOMViderSommet();

	// V�rification de la pr�sence d'une liste non nul
	if(ppqGRASommets == nullptr)
		throw new CException(ECHECNONTROUVE, "Echec la liste des sommets est nul");

	// Realloc de la bonne taille - 1 sommet
	(CSommet **)realloc(ppqGRASommets, sizeof(ppqGRASommets) - sizeof(CSommet *));
	if(ppqGRASommets == nullptr)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	// Suppression � la liste du graphe le sommet et d�cr�mentant son nombre
	delete(ppqGRASommets[uiGRANbSommets]);
	uiGRANbSommets--;
}

/*****************************
Methode : Modifier Sommet
******************************
Entr�e : unsigned int uiNum, CSommet & SOMSommet
Necessit� / Pr�conditions : fournir un objet en param�tre non nul
Sortie : n�ant
Entraine : modifie un sommet au graphe
*****************************/
void CGraphe::GRAModifierSommet(unsigned int uiNum, CSommet & SOMSommet)
{
	/*
	// Unicit� avant modification d'un sommet
	CSommet * SOMlistSommets = GRATrouverSommet(uiNum);
	if(SOMlistSommets != nullptr)
		throw new CException(ECHECNEWSOMMET, "Echec il existe deja un sommet avec ce numero");

	// FAIRE ICI UNE MODIF DE TOUT LES ARCS EN RELATION AVEC SOMSommet num actuel avant chang
	unsigned int uiBoucle = 0, uiAncienNum = SOMSommet.SOMGetNum;

	GRAAjoutArc(SOMSommet.SOMGetListArcArrivant



	CSommet * SOMSommet = nullptr, *SOMSommetBoucle = 0;


	while(uiBoucle != uiGRANbSommets) {
		SOMSommetBoucle = new CSommet(ppqGRASommets[uiBoucle]);
		
		if(SOMSommetBoucle == 

		SOMSommetBoucle = GRAGetSommet(SOMSommet.SOMGetNum);
		SOMSommet =
		uiBoucle ++;
	}

	SOMSommet.SOMSetNum(uiNum);
	*/
}

/*****************************
Methode : R�cup�rer Sommet
******************************
Entr�e : unsigned int uiSommet
Necessit� : n�ant
Sortie : n�ant
Entraine : r�cup�re un sommet du graphe
*****************************/
CSommet * CGraphe::GRAGetSommet(unsigned int uiSommet)
{

}

/*****************************
Methode : Ajouter Arc
******************************
Entr�e : unsigned int uiDestination, CSommet * sommet
Necessit� : n�ant
Sortie : n�ant
Entraine : ajoute un nouvel arc au graphe
*****************************/
void CGraphe::GRAAjoutArc(unsigned int uiDestination, CSommet * sommet)
{

}

/*****************************
Methode : Supprimer Arc
******************************
Entr�e : CArc * arc
Necessit� : n�ant
Sortie : n�ant
Entraine : supprime un arc au graphe
*****************************/
void CGraphe::GRASupprimerArc(CArc * arc)
{

}

/*****************************
Methode : Modifier Arc
******************************
Entr�e : unsigned int uiDestination, CSommet * sommet
Necessit� : n�ant
Sortie : n�ant
Entraine : modifie un arc au graphe
*****************************/
void CGraphe::GRAModifierArc(unsigned int uiDestination, CSommet * sommet)
{

}

/*****************************
Methode : R�cup�rer Arc
******************************
Entr�e : unsigned int uiDestination
Necessit� : n�ant
Sortie : n�ant
Entraine : r�cup�re un arc du graphe
*****************************/
CSommet * CGraphe::GRAGetArc(unsigned int uiDestination)
{

}

/*****************************
Methode : Afficher Arc
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : affichage du graphe
Entraine : affichage du graphe dans la console
*****************************/
void CGraphe::GRAAfficherGraphe()
{

}

/*****************************
Methode : Trouver Sommet
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : liste de sommets trouv�s
Entraine : cherche et renvoi la liste des sommets trouv�s
*****************************/
CSommet ** CGraphe::GRATrouverSommet(unsigned int uiSommet)
{

}

/*****************************
Methode : Trouver Arc
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : liste d'arcs trouv�s
Entraine : cherche et renvoi la liste des arcs trouv�s
*****************************/
CArc ** CGraphe::GRATrouverArc(unsigned int uiDestination)
{

}
