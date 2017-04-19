#include "CSommet.h"
#include "CException.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CSommet::CSommet()
{
	uiSOMNum = 0;
	ppqSOMArcArrivant = nullptr;
	ppqSOMArcPartant = nullptr;
}

/*****************************
Constructeur de recopie
******************************
Entr�e : CSommet & sommet);
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
*****************************/
CSommet::CSommet(CSommet & sommet)
{
	uiSOMNum = sommet.uiSOMNum;
	ppqSOMArcArrivant = sommet.ppqSOMArcArrivant;
	ppqSOMArcPartant = sommet.ppqSOMArcPartant;
}

/*****************************
Constructeur de confort
******************************
Entr�e : unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CSommet::CSommet(unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant)
{
	uiSOMNum = uiNumSommet;
	ppqSOMArcArrivant = ppqSommetArcArrivant;
	ppqSOMArcPartant = ppqSommetArcPartant;
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet est d�truit
*****************************/
CSommet::~CSommet()
{
	ppqSOMArcArrivant = nullptr;
	delete(ppqSOMArcArrivant);
	ppqSOMArcPartant = nullptr;
	delete(ppqSOMArcPartant);
}

/*****************************
Methode : Lire Numero
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiDestination
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNum()
{
	return uiSOMNum;
}

/*****************************
Methode : Modifier Numero
******************************
Entr�e : unsigned int uiNum
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetNum(unsigned int uiNum)
{
	uiSOMNum = uiNum;
}

/*****************************
Methode : Lire Arc Arrivant
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : CArc **
Entraine : retourne l'attribut
*****************************/
CArc ** CSommet::SOMGetArcArrivant()
{
	return ppqSOMArcArrivant;
}

/*****************************
Methode : Modifier Arc Arrivant
******************************
Entr�e : CArc ** arc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
unsigned int CSommet::SOMSetArcArrivant(CArc ** arc)
{
	ppqSOMArcArrivant = arc;
}

/*****************************
Methode : Lire Arc Partant
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : CArc **
Entraine : retourne l'attribut
*****************************/
CArc ** CSommet::SOMGetArcPartant()
{
	return ppqSOMArcPartant;
}

/*****************************
Methode : Modifier Arc Partant
******************************
Entr�e : CArc ** arc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
unsigned int CSommet::SOMSetArcPartant(CArc ** arc)
{
	ppqSOMArcPartant = arc;
}