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
	ppqGRAArcs = nullptr;
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
Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiGRANbSommets
Entraine : retourne l'attribut
*****************************/
unsigned int CGraphe::GRAGetNbSommets()
{

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

}

/*****************************
Methode : Supprimer Sommet
******************************
Entr�e : CSommet * sommet
Necessit� : n�ant
Sortie : n�ant
Entraine : supprime un sommet au graphe
*****************************/
void CGraphe::GRASupprimerSommet(CSommet * sommet)
{

}

/*****************************
Methode : Modifier Sommet
******************************
Entr�e : unsigned int uiNum
Necessit� : n�ant
Sortie : n�ant
Entraine : modifie un sommet au graphe
*****************************/
void CGraphe::GRAModifierSommet(unsigned int uiNum)
{

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