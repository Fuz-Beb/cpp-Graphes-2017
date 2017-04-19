#include "CSommet.h"
#include "CException.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
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
Entrée : CSommet & sommet);
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
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
Entrée : unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CSommet::CSommet(unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant)
{
	uiSOMNum = uiNumSommet;
	ppqSOMArcArrivant = ppqSommetArcArrivant;
	ppqSOMArcPartant = ppqSommetArcPartant;
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet est détruit
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
Entrée : néant
Necessité : néant
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
Entrée : unsigned int uiNum
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetNum(unsigned int uiNum)
{
	uiSOMNum = uiNum;
}

/*****************************
Methode : Lire Arc Arrivant
******************************
Entrée : néant
Necessité : néant
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
Entrée : CArc ** arc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
unsigned int CSommet::SOMSetArcArrivant(CArc ** arc)
{
	ppqSOMArcArrivant = arc;
}

/*****************************
Methode : Lire Arc Partant
******************************
Entrée : néant
Necessité : néant
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
Entrée : CArc ** arc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
unsigned int CSommet::SOMSetArcPartant(CArc ** arc)
{
	ppqSOMArcPartant = arc;
}