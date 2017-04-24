#include "CParseGraphe.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParseGraphe::CParseGraphe()
{
	graGraphe = CGraphe();
}

/*****************************
Methode : Retourner Graphe
******************************
Entrée : néant
Necessité : néant
Sortie : Retourne un pointeur sur l'attribut de graGraphe
Entraine : Création d'un objet/pointeur en appellant le constructeur de recopie de CGraphe
*****************************/
CGraphe * CParseGraphe::PAGRetournerGraphe()
{
	return new CGraphe(graGraphe);
}

/*****************************
Methode : Lire Nombre Sommets
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : Retourne le nombre de sommets précédemment lu
*****************************/
unsigned int CParseGraphe::PAGLireNbSommets()
{
	return uiNbSommets;
}

/*****************************
Methode : Assigner Nombre Sommets
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : Assigner le nombre de sommets lu
*****************************/
void CParseGraphe::PAGAssignerNbSommets()
{
	try {
		char * sBuffer = nullptr, * sRetour = nullptr;

		sBuffer = CParse::PARLireLigne();

		// Verification du préfixe de la valeur du nombre de sommets
		sRetour = PARSubString(sBuffer, 0, 10);

		if(strcmp(sRetour, "nbsommets=") == 1) {
			delete(sBuffer);
			delete(sRetour);
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBSommets=");
		}

		delete(sRetour);

		// Vérification de la valeur
		sRetour = PARSubString(sBuffer, 10, strlen(sBuffer) - 10);

		if(sRetour == NULL) {
			delete(sBuffer);
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		// Conversion string vers int
		uiNbSommets = atoi(sRetour);

		delete(sBuffer);
		delete(sRetour);

		if(uiNbSommets < 0)
			throw CException(ERREURTAILLE, "Erreur de la taille");

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);
	}
}

/*****************************
Methode : Lire Nombre Arcs
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : Retourne le nombre d'arcs qui a été précédemment lu
*****************************/
unsigned int CParseGraphe::PAGLireNbArcs()
{
	return uiNbArcs;
}

/*****************************
Methode : Assigner Nombre Arcs
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : Assigner le nombre d'arcs lu
*****************************/
void CParseGraphe::PAGAssignerNbArcs()
{
	try {
		char *sBuffer = nullptr, * sRetour = nullptr;
	
		sBuffer = PARLireLigne();

		// Verification du préfixe de la valeur du nombre d'arcs
		sRetour = PARSubString(sBuffer, 0, 7);

		if(strcmp(sRetour, "nbarcs=") == 1) {
			delete(sBuffer);
			delete(sRetour);
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBArcs=");
		}

		delete(sRetour);

		// Vérification de la valeur
		sRetour = PARSubString(sBuffer, 7, strlen(sBuffer) - 7);

		if(sRetour == NULL) {
			delete(sBuffer);
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		// Conversion string vers int
		uiNbArcs = atoi(sRetour);

		delete(sBuffer);
		delete(sRetour);

		if(uiNbArcs < 0)
			throw CException(ERREURTAILLE, "Erreur de la taille");

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);
	}
}

/*****************************
Methode : Traiter Sommets
******************************
Entrée : néant
Necessité :  Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : La lecture du fichier et création des sommets du graphe
*****************************/
void CParseGraphe::PAGTraiterSommets()
{
	try {
		// Initialisation du buffer ligne par ligne
		char *sBuffer = nullptr, * sRetour = nullptr;

		// Initialisation Variables d'indice de boucles
		unsigned int uiBoucleSommets = 1;

		while (uiBoucleSommets <= uiNbSommets)
		{
			sBuffer = PARLireLigne();

			// Verification du préfixe de la valeur du sommet
			sRetour = PARSubString(sBuffer, 0, 7);

			if(strcmp(sRetour, "numero=") == 1) {
				delete(sBuffer);
				delete(sRetour);
				graGraphe.GRASetNbSommets(uiBoucleSommets - 1);
				throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect d'un Numero=");
			}

			delete(sRetour);

			// Vérification de la valeur
			sRetour = PARSubString(sBuffer, 7, strlen(sBuffer) - 7);

			if(sRetour == NULL) {
				delete(sBuffer);
				throw CException(ECHECALLOCATION, "Echec de l'allocation");
			}

			// Ajouter le sommet au graphe
			graGraphe.GRAAjoutSommet(atoi(sRetour), nullptr, nullptr);

			delete(sBuffer);
			delete(sRetour);
			uiBoucleSommets++;
		}
		sBuffer = PARLireLigne();

		// Verification que nous sommes bien à la fin de la section Sommets
		sRetour = PARSubString(sBuffer, 0, 1);

		if(strcmp(sRetour, "]") == 1) {
			delete(sBuffer);
			delete(sRetour);
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin de la section Sommets");
		}

		delete(sBuffer);
		delete(sRetour);

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}
}

/*****************************
Methode : Traiter Arcs
******************************
Entrée : néant
Necessité :  Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : La lecture du fichier et création des arcs du graphe
*****************************/
void CParseGraphe::PAGTraiterArcs()
{
	try {
		// Initialisation du buffer ligne par ligne
		char *sBuffer = nullptr, * sRetour = nullptr;

		// Initialisation Variables d'indice de boucles
		unsigned int uiBoucleArcs = 1, uiBufferDebut;

		while (uiBoucleArcs <= uiNbArcs)
		{
			sBuffer = PARLireLigne();

			// Verification du préfixe de la valeur du sommet de depart
			sRetour = PARSubString(sBuffer, 0, 6);

			if(strcmp(sRetour, "debut=") == 1 && PARRechercheCaractere(',', sBuffer) == -1) {
				delete(sBuffer);
				delete(sRetour);
				graGraphe.GRASetNbSommets(uiBoucleArcs - 1);
				throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect du sommet de depart apres Debut=");
			}

			delete(sRetour);

			// Vérification de la valeur
			sRetour = PARSubString(sBuffer, 6, PARRechercheCaractere(',', sBuffer) - 6);

			if(sRetour == NULL) {
				delete(sBuffer);
				throw CException(ECHECALLOCATION, "Echec de l'allocation");
			}
			// Mémorisation de l'arc de debut
			uiBufferDebut = atoi(sRetour);

			delete(sRetour);

			// Verification du préfixe de la valeur du sommet de d'arrive
			sRetour = PARSubString(sBuffer, PARRechercheCaractere(',', sBuffer) + 1, 4);

			if(strcmp(sRetour, "fin=") == 1) {
				delete(sBuffer);
				delete(sRetour);
				graGraphe.GRASetNbSommets(uiBoucleArcs - 1);
				throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect du sommet de depart apres Fin=");
			}

			delete(sRetour);

			// Vérification de la valeur
			sRetour = PARSubString(sBuffer, PARRechercheCaractere(',', sBuffer) + 5, strlen(sBuffer) - PARRechercheCaractere(',', sBuffer) + 5);

			if(sRetour == NULL) {
				delete(sBuffer);
				throw CException(ECHECALLOCATION, "Echec de l'allocation");
			}

			graGraphe.GRATrouverSommet(uiBufferDebut)->SOMAddArcPartant(new CArc(atoi(sBuffer)));
			graGraphe.GRATrouverSommet(atoi(sRetour))->SOMAddArcArrivant(new CArc(atoi(sBuffer)));

			delete(sBuffer);
			delete(sRetour);
			uiBoucleArcs++;
		}
		sBuffer = PARLireLigne();

		// Verification que nous sommes bien à la fin de la section Sommets
		sRetour = PARSubString(sBuffer, 0, 1);

		if(strcmp(sRetour, "]") == 1) {
			delete(sBuffer);
			delete(sRetour);
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin de la section Sommets");
		}

		delete(sBuffer);
		delete(sRetour);

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}
}

/*****************************
Methode : Traiter fichier
******************************
Entrée : char * sChemin
Necessité : néant
Sortie : néant
Entraine : La lecture du fichier et création de la matrice associée
*****************************/
void CParseGraphe::PAGTraiterFichier(char * sChemin)
{
	try {
		// Initialisation du buffer ligne par ligne
		char * sBuffer = nullptr, * sChaineBuffer = nullptr, * sBufferDoubleTemp = nullptr, * sBufferDouble = nullptr;

		// Initialisation Variables d'indice de boucles
		unsigned int uiMaxColonne = 0, uiBoucleBuffer = 0, uiIndiceLigne = 1, uiIndiceColonne = 1, uiBoucleBufferDouble = 0;

		// Mise en place de l'ouverture du fichier
		PARModifierChemin(sChemin);
		PAROuvrirFichier(sChemin);

		// Lecture et écriture attribut du nombre de sommets
		PAGAssignerNbSommets();

		// Lecture et écriture attribut du nombre d'arcs
		PAGAssignerNbArcs();
	
		// Lire une ligne dans le vide (ligne inutile Sommets=[)
		sBuffer = PARLireLigne();

		PARConvertirStrMinusc(sBuffer);

		if(strcmp(sBuffer, "sommets=[\n") == 1) {
			delete sBuffer;
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Sommets=[");
		}

		delete sBuffer;

		// Création du graphe selon sa taille lu
		graGraphe = CGraphe(uiNbSommets, uiNbArcs, nullptr);

		// Initialisation des sommets du graphe
		PAGTraiterSommets();

		// Lire une ligne dans le vide (ligne inutile Arcs=[)
		sBuffer = PARLireLigne();

		PARConvertirStrMinusc(sBuffer);

		if(strcmp(sBuffer, "arcs=[\n") == 1) {
			delete sBuffer;
			throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Arcs=[");
		}

		delete sBuffer;

		// Initialisation des arcs du graphe
		PAGTraiterArcs();
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}
}