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

	uiSOMNbrArcArrivant = 0;
	uiSOMNbrArcPartant = 0;
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

	uiSOMNbrArcArrivant = sommet.uiSOMNbrArcArrivant;
	uiSOMNbrArcPartant = sommet.uiSOMNbrArcPartant;

	// Affectation du num�ro
	uiSOMNum = sommet.uiSOMNum;
}

/*****************************
Constructeur de confort
******************************
Entr�e : unsigned int uiNumSommet, CArc * ppqSommetArcArrivant, CArc * ppqSommetArcPartant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CSommet::CSommet(unsigned int uiNumSommet, CArc * ppqSommetArcArrivant, CArc * ppqSommetArcPartant)
{	
	// Mise � 0 des arcs partant
	uiSOMNbrArcArrivant = 0;
	uiSOMNbrArcPartant = 0;

	// Affectation du num�ro
	uiSOMNum = uiNumSommet;

	// Initialisation
	ppqSOMArcArrivant = nullptr;
	ppqSOMArcPartant = nullptr;

	// Allocation des arcs arrivant
	if (ppqSommetArcArrivant != nullptr) {
		ppqSOMArcArrivant = (CArc **)malloc(sizeof(CSommet *));
		if(ppqSOMArcArrivant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	
		ppqSOMArcArrivant[0] = ppqSommetArcPartant;
		uiSOMNbrArcArrivant++;
	}
	
	// Allocation des arcs partant
	if (ppqSommetArcPartant != nullptr) {
		ppqSOMArcPartant = (CArc **)malloc(sizeof(CSommet *));
		if(ppqSOMArcPartant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		
		ppqSOMArcPartant[0] = ppqSommetArcPartant;
		uiSOMNbrArcPartant++;
	}
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
	for(unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNbrArcArrivant ; uiBoucle++) {
		if(ppqSOMArcArrivant[uiBoucle] != nullptr)
			delete ppqSOMArcArrivant[uiBoucle];
	}

	for(unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNbrArcPartant; uiBoucle++) {
		if(ppqSOMArcPartant[uiBoucle] != nullptr)
			delete ppqSOMArcPartant[uiBoucle];
	}

	if(ppqSOMArcArrivant != nullptr)
		free(ppqSOMArcArrivant);

	if(ppqSOMArcPartant != nullptr)
		free(ppqSOMArcPartant);

	/*
	unsigned int uiBoucle = 0;
	// Boucle pour liberer la liste des arcs arrivant
	while(uiBoucle != uiSOMNbrArcArrivant) {
		if(ppqSOMArcArrivant != nullptr && ppqSOMArcArrivant[uiBoucle])
			free(ppqSOMArcArrivant[uiBoucle]);
		ppqSOMArcArrivant[uiBoucle] = nullptr;
		uiBoucle++;
	}
	uiBoucle = 0;
	// Boucle pour liberer la liste des arcs partant
	while(uiBoucle != uiSOMNbrArcPartant) {
		if(ppqSOMArcPartant != nullptr && ppqSOMArcArrivant[uiBoucle] != nullptr)
			free(ppqSOMArcPartant[uiBoucle]); // Ne pas modifier le free
		ppqSOMArcPartant[uiBoucle] = nullptr;
		uiBoucle++;
	}
	if(ppqSOMArcArrivant != nullptr) {
		delete[] ppqSOMArcArrivant;
		ppqSOMArcArrivant = nullptr;
	}
	
	if(ppqSOMArcPartant != nullptr) {
		delete[] ppqSOMArcPartant;
		ppqSOMArcPartant = nullptr;
	}
	*/
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
Methode : Lire Nombre Arc
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : unsigned int uiNbr
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetNbrArcArrivant(unsigned int uiNbr)
{
	uiSOMNbrArcArrivant = uiNbr;
}

/*****************************
Methode : Lire Nombre Arc
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : unsigned int uiNbr
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetNbrArcPartant(unsigned int uiNbr)
{
	uiSOMNbrArcPartant = uiNbr;
}

/*****************************
Methode : Lire Arc Arrivant
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : CArc ** arc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetListArcArrivant(CArc ** arc)
{
	ppqSOMArcArrivant = arc;
	SOMCompterArc(ppqSOMArcArrivant);
}

/*****************************
Methode : Lire Arc Partant
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : CArc ** arc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetListArcPartant(CArc ** arc)
{
	ppqSOMArcPartant = arc;
	SOMCompterArc(ppqSOMArcPartant);
}

/*****************************
Methode : Ajouter Arc Arrivant
******************************
Entr�e : CArc * arc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre arc � la liste des arcs
*****************************/
void CSommet::SOMAddArcArrivant(CArc * arc)
{
	if (arc == nullptr)
		throw new CException(ERREURARGS, "L'argument arc ne peut pas �tre nul");

	// Allocation pour la premi�re fois
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
		ppqSOMArcArrivant = (CArc **)realloc(ppqSOMArcArrivant, sizeof(CArc *) * (uiSOMNbrArcArrivant + 1));
		if(ppqSOMArcArrivant == nullptr) {
			delete(arc);
			arc = nullptr;
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}
		ppqSOMArcArrivant[uiSOMNbrArcArrivant] = arc;
	}
	uiSOMNbrArcArrivant++;
}

/*****************************
Methode : Ajouter Arc Parant
******************************
Entr�e : CArc * arc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre arc � la liste des arcs
*****************************/
void CSommet::SOMAddArcPartant(CArc * arc)
{
	if (arc == nullptr)
		throw new CException(ERREURARGS, "L'argument arc ne peut pas �tre nul");

	// Allocation pour la premi�re fois
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
		ppqSOMArcPartant = (CArc **)realloc(ppqSOMArcPartant, sizeof(CArc *) * (uiSOMNbrArcPartant + 1));
		if(ppqSOMArcPartant == nullptr) {
			delete(arc);
			arc = nullptr;
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		ppqSOMArcPartant[uiSOMNbrArcPartant] = arc;
	}
	uiSOMNbrArcPartant++;
}

/*****************************
Methode : Compter le nombre d'arc dans la liste
******************************
Entr�e : CArc ** ARCListArc
Necessit� : n�ant
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
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