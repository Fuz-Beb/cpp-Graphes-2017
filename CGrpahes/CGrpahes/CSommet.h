#ifndef C_SOMMET_H
#define C_SOMMET_H

#include "CArc.h"

class CSommet
{
private:
	// Attributs
	unsigned int uiSOMNum;
	unsigned int uiSOMNbrArcArrivant;
	unsigned int uiSOMNbrArcPartant;
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
	explicit CSommet(CSommet & sommet);

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
	Constructeur de confort
	******************************
	Entr�e : unsigned int uiNumSommet, CArc * ppqSommetArcArrivant, CArc * ppqSommetArcPartant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CSommet(unsigned int uiNumSommet, CArc * ppqSommetArcArrivant, CArc * ppqSommetArcPartant);

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
	Methode : Lire Nombre Arc
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int uiNbr
	Entraine : retourne l'attribut
	*****************************/
	unsigned int SOMGetNbrArcArrivant();

	/*****************************
	Methode : Modifier Nombre Arc
	******************************
	Entr�e : unsigned int uiNbr
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void SOMSetNbrArcArrivant(unsigned int uiNbr);

	/*****************************
	Methode : Lire Nombre Arc
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int uiNbr
	Entraine : retourne l'attribut
	*****************************/
	unsigned int SOMGetNbrArcPartant();

	/*****************************
	Methode : Modifier Nombre Arc
	******************************
	Entr�e : unsigned int uiNbr
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void SOMSetNbrArcPartant(unsigned int uiNbr);

	/*****************************
	Methode : Lire Arc Arrivant
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetListArcArrivant();

	/*****************************
	Methode : Modifier Arc Arrivant
	******************************
	Entr�e : CArc ** arc
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void SOMSetListArcArrivant(CArc ** arc);

	/*****************************
	Methode : Lire Arc Partant
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetListArcPartant();

	/*****************************
	Methode : Modifier Arc Partant
	******************************
	Entr�e : CArc ** arc
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void SOMSetListArcPartant(CArc ** arc);

	/*****************************
	Methode : Ajouter Arc Arrivant
	******************************
	Entr�e : CArc * arc
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre arc � la liste des arcs
	*****************************/
	void SOMAddArcArrivant(CArc * arc);

	/*****************************
	Methode : Ajouter Arc Partant
	******************************
	Entr�e : CArc * arc
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre arc � la liste des arcs
	*****************************/
	void  SOMAddArcPartant(CArc * arc);

	/*****************************
	Methode : Compter le nombre d'arc dans la liste
	******************************
	Entr�e : CArc ** listArc
	Necessit� : n�ant
	Sortie : uiCompteur
	Entraine : compte le nombre d'arcs dans la liste et retourne le nombre
	*****************************/
	unsigned int SOMCompterArc(CArc ** listArc);

	/*****************************
	Methode : Vider Sommet
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : vide un sommet de ses arcs
	*****************************/
	void SOMViderSommet();
};
#endif