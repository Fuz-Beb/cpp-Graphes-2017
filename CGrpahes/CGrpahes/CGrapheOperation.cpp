#include "CGrapheOperation.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGrapheOperation::CGrapheOperation()
{
	__super::CGraphe();
}

/*****************************
Constructeur de recopie
******************************
Entrée : CGrapheOperation & graGraphe);
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
*****************************/
CGrapheOperation::CGrapheOperation(CGrapheOperation & graGrapheOperation)
{
	__super::CGraphe(graGrapheOperation);
}


/*****************************
Constructeur de confort
******************************
Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGrapheOperation::CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs)
{
	__super::CGraphe(uiNbSommets, uiNbArcs);
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet est détruit
*****************************/
CGrapheOperation::~CGrapheOperation()
{
	__super::~CGraphe();
}

/*****************************
Methode : Inverser un graphe
******************************
Entrée : neant
Necessité : neant
Sortie : neant
Entraine : le graphe de sortie est inverse
*****************************/
void inverserGraphe()
{
	// To do
}