#ifndef C_SOMMET_H
#define C_SOMMET_H

#include "CArc.h"

class CSommet
{
private:
	// Attributs
	unsigned int uiSOMNum;
	CArc ** ppqSOMArcArrivant;
	CArc ** ppqSOMArcPartant;

public:
	// Constructeurs / Destructeurs

	/*****************************
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CSommet();

	/*****************************
	Constructeur de recopie
	******************************
	Entr�e : CSommet & sommet);
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
	*****************************/
	CSommet(CSommet & sommet);

	/*****************************
	Constructeur de confort
	******************************
	Entr�e : unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CSommet(unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant);

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet est d�truit
	*****************************/
	~CSommet();

	// Accesseurs

	/*****************************
	Methode : Lire Numero
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int uiDestination
	Entraine : retourne l'attribut
	*****************************/
	unsigned int SOMGetNum();

	/*****************************
	Methode : Modifier Numero
	******************************
	Entr�e : unsigned int uiNum
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void SOMSetNum(unsigned int uiNum);

	/*****************************
	Methode : Lire Arc Arrivant
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetArcArrivant();

	/*****************************
	Methode : Modifier Arc Arrivant
	******************************
	Entr�e : CArc ** arc
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	unsigned int SOMSetArcArrivant(CArc ** arc);

	/*****************************
	Methode : Lire Arc Partant
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetArcPartant();

	/*****************************
	Methode : Modifier Arc Partant
	******************************
	Entr�e : CArc ** arc
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	unsigned int SOMSetArcPartant(CArc ** arc);
};
#endif