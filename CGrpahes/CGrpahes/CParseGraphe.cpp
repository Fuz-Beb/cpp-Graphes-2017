#include "CParseGraphe.h"
#include "CException.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParseGraphe::CParseGraphe()
{
	graGraphe = CGraphe();
}

/*****************************
Methode : Retourner Graphe
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : Retourne un pointeur sur l'attribut de graGraphe
Entraine : Cr�ation d'un objet/pointeur en appellant le constructeur de recopie de CGraphe
*****************************/
CGraphe * CParseGraphe::PAGRetournerGraphe()
{
	return new CGraphe(graGraphe);
}

/*****************************
Methode : Lire Nombre Sommets
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int
Entraine : Retourne le nombre de sommets pr�c�demment lu
*****************************/
unsigned int CParseGraphe::PAGLireNbSommets()
{
	return uiNbSommets;
}

/*****************************
Methode : Lire Nombre Arcs
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int
Entraine : Retourne le nombre d'arcs qui a �t� pr�c�demment lu
*****************************/
unsigned int CParseGraphe::PAGLireNbArcs()
{
	return uiNbArcs;
}

/*****************************
Methode : Traiter Sommets
******************************
Entr�e : n�ant
Necessit� :  M�thode Traiter fichier / Ouvrir fichier
Sortie : n�ant
Entraine : La lecture du fichier et cr�ation des sommets du graphe
*****************************/
void CParseGraphe::PAGTraiterSommets()
{
	// Initialisation du buffer ligne par ligne
	char * sBuffer = nullptr;

	// V�rification que la d�claration des sommets est bien � la suite du fichier
	if (!PARCompareChaine(PARLireLigne(), "sommets=[\n"))
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Sommets=[");

	// D�but de la r�cup�ration de la valeur de chaque sommets
	for (unsigned int uiBoucleSommets = 1 ; uiBoucleSommets <= uiNbSommets ; uiBoucleSommets++)
	{
		// Ajouter le sommet au graphe
		graGraphe.GRAAjoutSommet(PARValeurApresSigneEgal("numero", PARLireLigne()), nullptr, nullptr);
		uiBoucleSommets++;
	}

	// V�rification de la fin de la d�claration des sommets
	sBuffer = PARLireLigne();

	// V�rification que c'est bien la fin de la d�claration des sommets
	if (!PARCompareChaine(PARSubString(sBuffer, 0, 1), "]"))
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin des sommets [");

	delete(sBuffer);
}

/*****************************
Methode : Traiter Arcs
******************************
Entr�e : n�ant
Necessit� :  M�thode Traiter fichier / Ouvrir fichier
Sortie : n�ant
Entraine : La lecture du fichier et cr�ation des arcs du graphe
*****************************/
void CParseGraphe::PAGTraiterArcs()
{
	// Initialisation du buffer ligne par ligne
	char * sBuffer = nullptr;

	// Initialisation Variables d'indice de boucles
	unsigned int uiBufferDebut, uiBufferFin;

	// V�rification que la d�claration des arcs est bien � la suite du fichier
	if (!PARCompareChaine(PARLireLigne(), "arcs=[\n"))
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Arcs=[");

	// Lecture d'une ligne contenant la mention debut et fin
	sBuffer = PARLireLigne();

	// D�but de la r�cup�ration de la valeur de chaque sommets
	for (unsigned int uiBoucleArcs = 1 ; uiBoucleArcs <= uiNbSommets ; uiBoucleArcs++)
	{
		// M�morisation de l'arc de debut puis de fin
		uiBufferDebut = PARValeurApresSigneEgal("debut", PARSubString(sBuffer, 0, PARRechercheCaractere(',', sBuffer)));
		uiBufferFin = PARValeurApresSigneEgal("fin", PARSubString(sBuffer, PARRechercheCaractere('f', sBuffer + 5), strlen(sBuffer)));

		// Ajout des arcs au graphe
		graGraphe.GRATrouverSommet(uiBufferDebut)->SOMAddArcPartant(new CArc(uiBufferFin));
		graGraphe.GRATrouverSommet(uiBufferFin)->SOMAddArcArrivant(new CArc(uiBufferFin));
	}

	// V�rification que c'est bien la fin de la d�claration des sommets
	if (!PARCompareChaine(PARSubString(sBuffer, 0, 1), "]"))
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin des arcs [");

	delete(sBuffer);
}

/*****************************
Methode : Traiter fichier
******************************
Entr�e : char * sChemin
Necessit� : n�ant
Sortie : n�ant
Entraine : La lecture du fichier et cr�ation de la matrice associ�e
*****************************/
void CParseGraphe::PAGTraiterFichier(char * sChemin)
{
	// Mise en place de l'ouverture du fichier
	PARModifierChemin(sChemin);
	PAROuvrirFichier(sChemin);

	// Lecture et �criture attribut du nombre de sommets
	uiNbSommets = PARValeurApresSigneEgal("nbsommets", PARLireLigne());

	// Lecture et �criture attribut du nombre d'arcs
	uiNbArcs = PARValeurApresSigneEgal("nbarcs", PARLireLigne());
	
	// Cr�ation du graphe selon sa taille lu
	graGraphe = CGraphe(uiNbSommets, uiNbArcs);

	// Initialisation des sommets du graphe
	PAGTraiterSommets();

	// Initialisation des arcs du graphe
	PAGTraiterArcs();
}