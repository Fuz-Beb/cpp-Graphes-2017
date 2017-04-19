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
	Constructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CSommet();

	/*****************************
	Constructeur de recopie
	******************************
	Entrée : CSommet & sommet);
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
	*****************************/
	CSommet(CSommet & sommet);

	/*****************************
	Constructeur de confort
	******************************
	Entrée : unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CSommet(unsigned int uiNumSommet, CArc ** ppqSommetArcArrivant, CArc ** ppqSommetArcPartant);

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet est détruit
	*****************************/
	~CSommet();

	// Accesseurs

	/*****************************
	Methode : Lire Numero
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int uiDestination
	Entraine : retourne l'attribut
	*****************************/
	unsigned int SOMGetNum();

	/*****************************
	Methode : Modifier Numero
	******************************
	Entrée : unsigned int uiNum
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void SOMSetNum(unsigned int uiNum);

	/*****************************
	Methode : Lire Arc Arrivant
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetArcArrivant();

	/*****************************
	Methode : Modifier Arc Arrivant
	******************************
	Entrée : CArc ** arc
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	unsigned int SOMSetArcArrivant(CArc ** arc);

	/*****************************
	Methode : Lire Arc Partant
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetArcPartant();

	/*****************************
	Methode : Modifier Arc Partant
	******************************
	Entrée : CArc ** arc
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	unsigned int SOMSetArcPartant(CArc ** arc);
};
#endif