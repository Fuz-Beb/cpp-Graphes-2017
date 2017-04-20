#ifndef C_GRAPHE_H
#define C_GRAPHE_H

#include "CSommet.h"

class CGraphe
{
private:
	// Attributs
	CSommet ** ppqGRASommets;
	CArc ** ppqGRAArcs;
	unsigned int uiGRANbSommets;
	unsigned int uiGRANbArcs;

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
explicit CGraphe();

/*****************************
Constructeur de recopie
******************************
Entr�e : CSommet & sommet);
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
*****************************/
explicit CGraphe(CGraphe & graphe);

/*****************************
Constructeur de confort
******************************
Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
explicit CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets);

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
Methode : Lire Nombre Sommets
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiGRANbSommets
Entraine : retourne l'attribut
*****************************/
unsigned int GRAGetNbSommets();

/*****************************
Methode : Modifier Nombre Sommets
******************************
Entr�e : unsigned int uiNbSommets
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void GRASetNbSommets(unsigned int uiNbSommets);

/*****************************
Methode : Lire Nombre Arcs
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiGRANbArcs
Entraine : retourne l'attribut
*****************************/
unsigned int GRAGetNbArcs();

/*****************************
Methode : Modifier Nombre Arcs
******************************
Entr�e : unsigned int uiNbArcs
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void GRASetNbArcs(unsigned int uiNbArcs);

/*****************************
Methode : Ajouter Sommet
******************************
Entr�e : unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant
Necessit� : n�ant
Sortie : n�ant
Entraine : ajoute un nouveau sommet au graphe
*****************************/
void GRAAjoutSommet(unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant);

/*****************************
Methode : Supprimer Sommet
******************************
Entr�e : CSommet * sommet
Necessit� : n�ant
Sortie : n�ant
Entraine : supprime un sommet au graphe
*****************************/
void GRASupprimerSommet(CSommet * sommet);

/*****************************
Methode : Modifier Sommet
******************************
Entr�e : unsigned int uiNum
Necessit� : n�ant
Sortie : n�ant
Entraine : Modifie un sommet au graphe
*****************************/
void GRAModifierSommet(unsigned int uiNum);

}
#endif