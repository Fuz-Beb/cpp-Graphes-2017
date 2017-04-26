#ifndef C_GRAPHEOPERATION_H
#define C_GRAPHEOPERATION_H

#include "CGraphe.h"
#include "CSommet.h"

class CGrapheOperation : public CGraphe
{
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
	CGrapheOperation();

	/*****************************
	Constructeur de recopie
	******************************
	Entr�e : CGrapheOperation & graGraphe);
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
	*****************************/
	explicit CGrapheOperation(CGrapheOperation & graGrapheOperation);

	/*****************************
	Constructeur de confort
	******************************
	Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs);

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet est d�truit
	*****************************/
	~CGrapheOperation();

	// Methodes

	/*****************************
	Methode : Inverser un graphe
	******************************
	Entr�e : neant
	Necessit� : neant
	Sortie : neant
	Entraine : le graphe de sortie est inverse
	*****************************/
	void inverserGraphe();
};
#endif