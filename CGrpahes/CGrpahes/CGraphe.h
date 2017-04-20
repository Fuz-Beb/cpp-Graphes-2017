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
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
explicit CGraphe();

/*****************************
Constructeur de recopie
******************************
Entrée : CSommet & sommet);
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
*****************************/
explicit CGraphe(CGraphe & graphe);

/*****************************
Constructeur de confort
******************************
Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
explicit CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets);

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
Methode : Lire Nombre Sommets
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiGRANbSommets
Entraine : retourne l'attribut
*****************************/
unsigned int GRAGetNbSommets();

/*****************************
Methode : Modifier Nombre Sommets
******************************
Entrée : unsigned int uiNbSommets
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void GRASetNbSommets(unsigned int uiNbSommets);

/*****************************
Methode : Lire Nombre Arcs
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiGRANbArcs
Entraine : retourne l'attribut
*****************************/
unsigned int GRAGetNbArcs();

/*****************************
Methode : Modifier Nombre Arcs
******************************
Entrée : unsigned int uiNbArcs
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void GRASetNbArcs(unsigned int uiNbArcs);

/*****************************
Methode : Ajouter Sommet
******************************
Entrée : unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant
Necessité : néant
Sortie : néant
Entraine : ajoute un nouveau sommet au graphe
*****************************/
void GRAAjoutSommet(unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant);

/*****************************
Methode : Supprimer Sommet
******************************
Entrée : CSommet * sommet
Necessité : néant
Sortie : néant
Entraine : supprime un sommet au graphe
*****************************/
void GRASupprimerSommet(CSommet * sommet);

/*****************************
Methode : Modifier Sommet
******************************
Entrée : unsigned int uiNum
Necessité : néant
Sortie : néant
Entraine : Modifie un sommet au graphe
*****************************/
void GRAModifierSommet(unsigned int uiNum);

}
#endif