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
	if(ppqSOMArcArrivant == nullptr) {
		// Allocation des arcs arrivant
		ppqSOMArcArrivant = (CArc **)malloc(sizeof(sommet.ppqSOMArcArrivant));
		if(ppqSOMArcArrivant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	if(ppqSOMArcPartant == nullptr) {
		// Allocation des arcs arrivant
		ppqSOMArcPartant = (CArc **)malloc(sizeof(sommet.ppqSOMArcPartant));
		if(ppqSOMArcPartant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Affectation de la liste des arcs Arrivant et Partant
	ppqSOMArcArrivant = sommet.ppqSOMArcArrivant;
	ppqSOMArcPartant = sommet.ppqSOMArcPartant;

	// Affectation du numéro
	uiSOMNum = sommet.uiSOMNum;
	SOMCompterArc(ppqSOMArcArrivant);
	SOMCompterArc(ppqSOMArcPartant);
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
	if(ppqSOMArcArrivant != nullptr) {
		delete(ppqSOMArcArrivant);
		ppqSOMArcArrivant = nullptr;
	}
	
	// Allocation des arcs arrivant
	if(ppqSOMArcArrivant != nullptr) {
		ppqSOMArcArrivant = (CArc **)malloc(sizeof(ppqSommetArcArrivant));
		if(ppqSOMArcArrivant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	if(ppqSOMArcPartant != nullptr) {
		free(ppqSOMArcPartant);
		ppqSOMArcPartant = nullptr;
	}
	
	// Allocation des arcs arrivant
	if(ppqSOMArcPartant != nullptr) {
		ppqSommetArcPartant = (CArc **)malloc(sizeof(ppqSommetArcPartant));
		if(ppqSOMArcPartant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Affectation de la liste des arcs Arrivant et Partant
	ppqSOMArcArrivant = ppqSommetArcArrivant;
	ppqSOMArcPartant = ppqSommetArcPartant;

	// Affectation du numéro
	uiSOMNum = uiNumSommet;
	uiSOMNbrArcArrivant = SOMCompterArc(ppqSOMArcArrivant);
	uiSOMNbrArcPartant = SOMCompterArc(ppqSOMArcPartant);
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
	unsigned int uiBoucle = 0;

	// Boucle pour liberer la liste des arcs arrivant
	while(uiBoucle != uiSOMNbrArcArrivant) {
		free(ppqSOMArcArrivant[uiBoucle]);
		ppqSOMArcArrivant[uiBoucle] = nullptr;
		uiBoucle++;
	}

	uiBoucle = 0;
	// Boucle pour liberer la liste des arcs partant
	while(uiBoucle != uiSOMNbrArcPartant) {
		free(ppqSOMArcPartant[uiBoucle]);
		ppqSOMArcPartant[uiBoucle] = nullptr;
		uiBoucle++;
	}

	delete[] ppqSOMArcArrivant;
	ppqSOMArcArrivant = nullptr;
	delete[] ppqSOMArcPartant;
	ppqSOMArcPartant = nullptr;
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
Methode : Lire Nombre Arc
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiNbr
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNbrArcArrivant()
{
	return uiSOMNbrArcArrivant;
}

/*****************************
Methode : Modifier Nombre Arc
******************************
Entrée : unsigned int uiNbr
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetNbrArcArrivant(unsigned int uiNbr)
{
	uiSOMNbrArcArrivant = uiNbr;
}

/*****************************
Methode : Lire Nombre Arc
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiNbr
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNbrArcPartant()
{
	return uiSOMNbrArcPartant;
}

/*****************************
Methode : Modifier Nombre Arc
******************************
Entrée : unsigned int uiNbr
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetNbrArcPartant(unsigned int uiNbr)
{
	uiSOMNbrArcPartant = uiNbr;
}

/*****************************
Methode : Lire Arc Arrivant
******************************
Entrée : néant
Necessité : néant
Sortie : CArc **
Entraine : retourne l'attribut
*****************************/
CArc ** CSommet::SOMGetListArcArrivant()
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
void CSommet::SOMSetListArcArrivant(CArc ** arc)
{
	ppqSOMArcArrivant = arc;
	SOMCompterArc(ppqSOMArcArrivant);
}

/*****************************
Methode : Lire Arc Partant
******************************
Entrée : néant
Necessité : néant
Sortie : CArc **
Entraine : retourne l'attribut
*****************************/
CArc ** CSommet::SOMGetListArcPartant()
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
void CSommet::SOMSetListArcPartant(CArc ** arc)
{
	ppqSOMArcPartant = arc;
	SOMCompterArc(ppqSOMArcPartant);
}

/*****************************
Methode : Ajouter Arc Arrivant
******************************
Entrée : CArc * arc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre arc à la liste des arcs
*****************************/
void CSommet::SOMAddArcArrivant(CArc * arc)
{	
	// Allocation pour la première fois
	if(ppqSOMArcArrivant == nullptr) {
		// Allocation des arcs arrivant
		ppqSOMArcArrivant = (CArc **)malloc(sizeof(CArc *));
		if(ppqSOMArcArrivant == nullptr) {
			delete(arc);
			arc = nullptr;
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}
		ppqSOMArcArrivant[0] = arc;
	}
	// Sinon reallocation
	else {
		// Reallocation des arcs arrivant
		(CArc **)realloc(ppqSOMArcArrivant, sizeof(ppqSOMArcArrivant) + sizeof(CArc *));
		if(ppqSOMArcArrivant == nullptr) {
			delete(arc);
			arc = nullptr;
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		ppqSOMArcArrivant[uiSOMNbrArcArrivant] = arc;

		if(ppqSOMArcArrivant[uiSOMNbrArcArrivant] != nullptr)
			uiSOMNbrArcArrivant++;
		else {
			delete(arc);
			arc = nullptr;
			delete[] ppqSOMArcArrivant;
			ppqSOMArcArrivant = nullptr;
			throw new CException(ECHECADDARC, "Echec lors de l'ajout d'un arc dans SOMAddArcArrivant");
		}
	}
}

/*****************************
Methode : Ajouter Arc Parant
******************************
Entrée : CArc * arc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre arc à la liste des arcs
*****************************/
void CSommet::SOMAddArcPartant(CArc * arc)
{	
	// Allocation pour la première fois
	if(ppqSOMArcPartant == nullptr) {
		// Allocation des arcs arrivant
		ppqSOMArcPartant = (CArc **)malloc(sizeof(CArc *));
		if(ppqSOMArcPartant == nullptr) {
			delete(arc);
			arc = nullptr;
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}
		ppqSOMArcPartant[0] = arc;
	}
	// Sinon reallocation
	else {
		// Reallocation des arcs arrivant
		(CArc **)realloc(ppqSOMArcPartant, sizeof(ppqSOMArcPartant) + sizeof(CArc *));
		if(ppqSOMArcPartant == nullptr) {
			delete(arc);
			arc = nullptr;
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		ppqSOMArcPartant[uiSOMNbrArcPartant] = arc;

		if(ppqSOMArcPartant[uiSOMNbrArcPartant] != nullptr)
			uiSOMNbrArcArrivant++;
		else {
			delete(arc);
			arc = nullptr;
			delete[] ppqSOMArcPartant;
			ppqSOMArcPartant = nullptr;
			throw new CException(ECHECADDARC, "Echec lors de l'ajout d'un arc dans SOMAddArcArrivant");
		}
	}
}

/*****************************
Methode : Compter le nombre d'arc dans la liste
******************************
Entrée : CArc ** ARCListArc
Necessité : néant
Sortie : uiCompteur
Entraine : compte le nombre d'arcs dans la liste et retourne le nombre
*****************************/
unsigned int CSommet::SOMCompterArc(CArc ** ARCListArc) 
{
	unsigned int uiCompteur = 0;

	if(ARCListArc == nullptr)
		return 0;

	if(ARCListArc[0] != nullptr)
		uiCompteur = 1;

	while(ARCListArc[uiCompteur + 1] != nullptr) {
		uiCompteur++;
	}

	return uiCompteur;
}

/*****************************
Methode : Vider Sommet
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : vide un sommet de ses arcs
*****************************/
void CSommet::SOMViderSommet()
{
	unsigned int uiBoucle = 0;

	// Boucle de suppression des arcs arrivant
	while(uiBoucle != uiSOMNbrArcArrivant) {
		delete(ppqSOMArcArrivant[uiBoucle]);
		ppqSOMArcArrivant[uiBoucle] = nullptr;
		uiBoucle++;
	}

	uiSOMNbrArcArrivant = 0;

	uiBoucle = 0;

	// Boucle de suppression des arcs partant
	while(uiBoucle != uiSOMNbrArcPartant) {
		delete(ppqSOMArcPartant[uiBoucle]);
		ppqSOMArcPartant[uiBoucle] = nullptr;
		uiBoucle++;
	}

	uiSOMNbrArcPartant = 0;
}