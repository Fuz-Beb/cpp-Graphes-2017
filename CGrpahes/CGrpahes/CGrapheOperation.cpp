#include "CGrapheOperation.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CGrapheOperation::CGrapheOperation()
{
	__super::CGraphe();
}

/*****************************
Constructeur de recopie
******************************
Entr�e : CGrapheOperation & graGraphe);
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
*****************************/
CGrapheOperation::CGrapheOperation(CGrapheOperation & graGrapheOperation)
{
	__super::CGraphe(graGrapheOperation);
}


/*****************************
Constructeur de confort
******************************
Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CGrapheOperation::CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs)
{
	__super::CGraphe(uiNbSommets, uiNbArcs);
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet est d�truit
*****************************/
CGrapheOperation::~CGrapheOperation()
{
	__super::~CGraphe();
}

/*****************************
Methode : Inverser un graphe
******************************
Entr�e : neant
Necessit� : neant
Sortie : neant
Entraine : le graphe de sortie est inverse
*****************************/
void inverserGraphe()
{
	// To do
}