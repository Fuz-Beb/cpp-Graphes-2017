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
	ppqGRAArcs = nullptr;
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
	if(ppqGRASommets != nullptr)
		delete(ppqGRASommets);

	// Allocation de la liste sommet
	ppqGRASommets = (CSommet **)malloc(sizeof(CSommet*) * graphe.uiGRANbSommets);
	
	if(ppqGRASommets == nullptr)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	if(ppqGRAArcs != nullptr)
		delete(ppqGRAArcs);

	// Allocation de la liste arc
	ppqGRAArcs = (CArc **)malloc(sizeof(CArc*) * graphe.uiGRANbArcs);
		
	if(ppqGRAArcs == nullptr)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqGRASommets = graphe.ppqGRASommets;
	ppqGRAArcs = graphe.ppqGRAArcs;
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
CGraphe::CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets, CArc ** arcs)
{
	if(ppqGRASommets != nullptr)
		delete(ppqGRASommets);

	// Allocation de la liste sommet
	ppqGRASommets = (CSommet **)malloc(sizeof(CSommet*) * uiNbSommets);
	
	if(ppqGRASommets == nullptr)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	if(ppqGRAArcs != nullptr)
		delete(ppqGRAArcs);

	// Allocation de la liste arc
	ppqGRAArcs = (CArc **)malloc(sizeof(CArc*) * uiNbArcs);
		
	if(ppqGRAArcs == nullptr)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	ppqGRASommets = sommets;
	ppqGRAArcs = arcs;
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
		delete(ppqGRASommets[uiBoucle]);
		uiBoucle++;
	}

	uiBoucle = 0;

	// Boucle pour liberer la liste des arcs
	while(uiBoucle != uiGRANbArcs) {
		ppqGRAArcs[uiBoucle] = nullptr;
		delete(ppqGRAArcs[uiBoucle]);
		uiBoucle++;
	}

	ppqGRASommets = nullptr;
	delete(ppqGRASommets);
	ppqGRAArcs = nullptr;
	delete(ppqGRAArcs);
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

}

/*****************************
Methode : Supprimer Sommet
******************************
Entrée : CSommet * sommet
Necessité : néant
Sortie : néant
Entraine : supprime un sommet au graphe
*****************************/
void CGraphe::GRASupprimerSommet(CSommet * sommet)
{

}

/*****************************
Methode : Modifier Sommet
******************************
Entrée : unsigned int uiNum
Necessité : néant
Sortie : néant
Entraine : modifie un sommet au graphe
*****************************/
void CGraphe::GRAModifierSommet(unsigned int uiNum)
{

}

/*****************************
Methode : Récupérer Sommet
******************************
Entrée : unsigned int uiSommet
Necessité : néant
Sortie : néant
Entraine : récupère un sommet du graphe
*****************************/
CSommet * CGraphe::GRAGetSommet(unsigned int uiSommet)
{

}

/*****************************
Methode : Ajouter Arc
******************************
Entrée : unsigned int uiDestination, CSommet * sommet
Necessité : néant
Sortie : néant
Entraine : ajoute un nouvel arc au graphe
*****************************/
void CGraphe::GRAAjoutArc(unsigned int uiDestination, CSommet * sommet)
{

}

/*****************************
Methode : Supprimer Arc
******************************
Entrée : CArc * arc
Necessité : néant
Sortie : néant
Entraine : supprime un arc au graphe
*****************************/
void CGraphe::GRASupprimerArc(CArc * arc)
{

}

/*****************************
Methode : Modifier Arc
******************************
Entrée : unsigned int uiDestination, CSommet * sommet
Necessité : néant
Sortie : néant
Entraine : modifie un arc au graphe
*****************************/
void CGraphe::GRAModifierArc(unsigned int uiDestination, CSommet * sommet)
{

}

/*****************************
Methode : Récupérer Arc
******************************
Entrée : unsigned int uiDestination
Necessité : néant
Sortie : néant
Entraine : récupère un arc du graphe
*****************************/
CSommet * CGraphe::GRAGetArc(unsigned int uiDestination)
{

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
Entrée : néant
Necessité : néant
Sortie : liste de sommets trouvés
Entraine : cherche et renvoi la liste des sommets trouvés
*****************************/
CSommet ** CGraphe::GRATrouverSommet(unsigned int uiSommet)
{

}

/*****************************
Methode : Trouver Arc
******************************
Entrée : néant
Necessité : néant
Sortie : liste d'arcs trouvés
Entraine : cherche et renvoi la liste des arcs trouvés
*****************************/
CArc ** CGraphe::GRATrouverArc(unsigned int uiDestination)
{

}