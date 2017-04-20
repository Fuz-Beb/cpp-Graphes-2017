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
	explicit CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs, CSommet ** sommets, CArc ** arcs);

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet est détruit
	*****************************/
	~CGraphe();

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
	Entraine : modifie un sommet au graphe
	*****************************/
	void GRAModifierSommet(unsigned int uiNum);

	/*****************************
	Methode : Récupérer Sommet
	******************************
	Entrée : unsigned int uiSommet
	Necessité : néant
	Sortie : néant
	Entraine : récupère un sommet du graphe
	*****************************/
	CSommet * GRAGetSommet(unsigned int uiSommet);

	/*****************************
	Methode : Ajouter Arc
	******************************
	Entrée : unsigned int uiDestination, CSommet * sommet
	Necessité : néant
	Sortie : néant
	Entraine : ajoute un nouvel arc au graphe
	*****************************/
	void GRAAjoutArc(unsigned int uiDestination, CSommet * sommet);

	/*****************************
	Methode : Supprimer Arc
	******************************
	Entrée : CArc * arc
	Necessité : néant
	Sortie : néant
	Entraine : supprime un arc au graphe
	*****************************/
	void GRASupprimerArc(CArc * arc);

	/*****************************
	Methode : Modifier Arc
	******************************
	Entrée : unsigned int uiDestination, CSommet * sommet
	Necessité : néant
	Sortie : néant
	Entraine : modifie un arc au graphe
	*****************************/
	void GRAModifierArc(unsigned int uiDestination, CSommet * sommet);

	/*****************************
	Methode : Récupérer Arc
	******************************
	Entrée : unsigned int uiDestination
	Necessité : néant
	Sortie : néant
	Entraine : récupère un arc du graphe
	*****************************/
	CSommet * GRAGetArc(unsigned int uiDestination);

	/*****************************
	Methode : Afficher Arc
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : affichage du graphe
	Entraine : affichage du graphe dans la console
	*****************************/
	void GRAAfficherGraphe();

	/*****************************
	Methode : Trouver Sommet
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : liste de sommets trouvés
	Entraine : cherche et renvoi la liste des sommets trouvés
	*****************************/
	CSommet ** GRATrouverSommet(unsigned int uiSommet);

	/*****************************
	Methode : Trouver Arc
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : liste d'arcs trouvés
	Entraine : cherche et renvoi la liste des arcs trouvés
	*****************************/
	CArc ** GRATrouverArc(unsigned int uiDestination);
}
#endif