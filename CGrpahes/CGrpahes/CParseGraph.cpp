#include "CParseMatrice.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParseMatrice::CParseMatrice()
{
	matPAMMatrice = CMatrice<double>();
}

/*****************************
Methode : Retourner Matrice
******************************
Entrée : néant
Necessité : néant
Sortie : Retourne un pointeur sur l'attribut de matPAMMatrice
Entraine : Création d'un objet/pointeur en appellant le constructeur de recopie de CMatrice
*****************************/
CMatrice<double> * CParseMatrice::PAMRetournerMatrice()
{
	CMatrice<double> * pMatriceRetourner = new CMatrice<double>(matPAMMatrice);
	return pMatriceRetourner;
}

/*****************************
Methode : Lire Nombre Lignes
*****************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : Retourne le nombre de lignes précédemment lu
*****************************/
unsigned int CParseMatrice::PAMLireNbLignes()
{
	return uiPAMNbLignes;
}

/*****************************
Methode : Assigner Nombre Lignes
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : Assigner le nombre de colonnes lu
*****************************/
void CParseMatrice::PAMAssignerNbLignes()
{
	try {
		char * sBuffer = nullptr, * sRetour = nullptr;

		sBuffer = CParse::PARLireLigne();

		// Verification du préfixe avant le =
		sRetour = PARSubString(sBuffer, 0, 9);

		if(strcmp(sRetour, "nblignes=") == 1) {
			delete(sBuffer);
			delete(sRetour);

			CException * CEXObject = new CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBLignes=");
			throw *CEXObject;
		}

		delete(sRetour);

		// Vérification de la valeur et conversion string vers int
		sRetour = PARSubString(sBuffer, 9, strlen(sBuffer) - 9);

		if(sRetour == NULL) {
			delete(sBuffer);

			CException * CEXObject = new CException(ECHECALLOCATION, "Echec de l'allocation");
			throw *CEXObject;
		}

		uiPAMNbLignes = atoi(sRetour);

		delete(sBuffer);
		delete(sRetour);

		if(uiPAMNbLignes < 1) {
			CException * CEXObject = new CException(ERREURTAILLE, "Erreur de la taille");
			throw *CEXObject;
		}
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);

	}
}

/*****************************
Methode : Lire Nombre Colonnes
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : Retourne le nombre de colonnes qui a été précédemment lu
*****************************/
unsigned int CParseMatrice::PAMLireNbColonnes()
{
	return uiPAMNbColonnes;
}

/*****************************
Methode : Assigner nombre colonnes
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : Assigner le nombre de colonne lu
*****************************/
void CParseMatrice::PAMAssignerNbColonnes()
{
	try {
		char *sBuffer = nullptr, * sRetour = nullptr;
	
		sBuffer = CParse::PARLireLigne();

		// Verification du préfixe nbcolonnes
		sRetour = PARSubString(sBuffer, 0, 11);

		if(strcmp(sRetour, "nbcolonnes=") == 1) {
			delete(sBuffer);
			delete(sRetour);

				CException * CEXObject = new CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBColonnes=");
				throw *CEXObject;
		}

		delete(sRetour);

		// Vérification de la valeur et conversion string vers int
		sRetour = PARSubString(sBuffer, 11, strlen(sBuffer) - 11);

		if(sRetour == NULL) {
			delete(sBuffer);
				CException * CEXObject = new CException(ECHECALLOCATION, "Echec de l'allocation");
				throw *CEXObject;
		}

		uiPAMNbColonnes = atoi(sRetour);

		delete(sBuffer);
		delete(sRetour);

		if(uiPAMNbColonnes < 1){
			CException * CEXObject = new CException(ERREURTAILLE, "Erreur de la taille");
			throw *CEXObject;
		}
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);
	}
}

/*****************************
Methode : Vérifier le type
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : néant
Entraine : La vérification du type double sur la lecture du fichier
*****************************/
void CParseMatrice::PAMVerifierType() 
{
	try {
		char * sBuffer = nullptr, * sRetour = nullptr;

		sBuffer = CParse::PARLireLigne();

		// Verification du préfixe typematrice
		sRetour = PARSubString(sBuffer, 0, 11);

		if(strcmp(sRetour, "typematrice") != 0) {
			delete(sBuffer);
			delete(sRetour);
	
				CException * CEXObject = new CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de TypeMatrice=");
				throw *CEXObject;
		}

		delete(sRetour);

		// Extraction et allocation sur le tas 
		sRetour = PARSubString(sBuffer, 12, 6);
		delete(sBuffer);

		// Vérifier que le fichier lu est bien une matrice double
		if(strcmp(sRetour, "double") != 0) {
			delete(sRetour);

				CException * CEXObject = new CException(MAUVAISTYPE, "La matrice lue n'est pas de type double");
				throw *CEXObject;
		}

		delete(sRetour);
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);	
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
void CParseMatrice::PAMTraiterFichier(char * sChemin)
{
	try {
		// Initialisation du buffer ligne par ligne
		char * sBuffer = nullptr, * sChaineBuffer = nullptr, * sBufferDoubleTemp = nullptr, * sBufferDouble = nullptr;

		// Initialisation Variables d'indice de boucles
		unsigned int uiMaxColonne = 0, uiBoucleBuffer = 0, uiIndiceLigne = 1, uiIndiceColonne = 1, uiBoucleBufferDouble = 0;
	

		// Mise en place de l'ouverture du fichier
		PARModifierChemin(sChemin);
		PAROuvrirFichier(sChemin);

		// Vérification qu'on va bien lire une matrice double
		PAMVerifierType();

		// Lecture et écriture attribut du nombre de ligne
		PAMAssignerNbLignes();

		// Lecture et écriture attribut du nombre de colonne
		PAMAssignerNbColonnes();
	
		// Lire une ligne dans le vide (ligne inutile Matrice=[)
		sBuffer = CParse::PARLireLigne();

		PARConvertirStrMinusc(sBuffer);

		if(strcmp(sBuffer, "matrice=[\n") == 1) {
			delete sBuffer;
			CException * CEXObject = new CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Matrice=[");
			throw *CEXObject;
		}

		delete sBuffer;

		// Création d'une CMatrice selon sa taille lu
		matPAMMatrice = CMatrice<double>(uiPAMNbLignes, uiPAMNbColonnes);
		
		// Boucle TQ concernant le nombre de ligne à lire
		while(uiIndiceLigne <= uiPAMNbLignes) {

			uiMaxColonne = uiPAMNbColonnes; // Remise du compteur de colonne à la taille par souhaité (utile dans le cas d'espace)

			sBuffer = PARLireLigne(); // Remplissage du buffer par rapport à la ligne actuel

			// Verification du fichier
			if(strcmp(sBuffer, "]") == 0) {
				PARFermerFicher();
				CException * CEXObject = new CException(ERREURTAILLE, "Il manque des lignes dans la matrice du fichier");
				throw *CEXObject;
			}

			// Boucle TQ concernant le nombre de colonne à lire (gère les espaces en trop)
			while(uiBoucleBuffer < uiMaxColonne) {
			
				// Permet de vérifier si il y a des espaces entre les éléments
				if(sBuffer[uiBoucleBuffer] != ' ') { 

					// Permet de gérer le cas où l'élement à une dizaine, centaine...
					if(sBufferDouble != nullptr) {
						sBufferDoubleTemp = PARSubString(sBufferDouble, 0, strlen(sBufferDouble));
						sChaineBuffer = PARSubString(sBuffer, uiBoucleBuffer, 1);
						delete(sBufferDouble);
						sBufferDouble = nullptr;
						sBufferDouble = PARConcatenateString(sBufferDoubleTemp, sChaineBuffer); // Verifier si il y a quelques choses dans le buffer, si oui alors concatenate et agrandir buffer
						delete(sChaineBuffer);
						sChaineBuffer = nullptr;
						delete(sBufferDoubleTemp);
						sBufferDoubleTemp = nullptr;
					}

					// Dans le cas où le second buffer d'élèment est vide, alors j'en créer un.
					else {
						sBufferDouble = PARSubString(sBuffer, uiBoucleBuffer, 1);
					}
				
					// Incrémentation de l'indice du second buffer (dans le cas où dizaine, centaine...)
					uiBoucleBufferDouble++;

					// On vérifie s'il y a une dizaine, centaine... où si on s'arrete et on modifie l'élement dans la CMatrice
					if(sBuffer[uiBoucleBuffer + 1] == ' ' || sBuffer[uiBoucleBuffer + 1] == '\0' || sBuffer[uiBoucleBuffer + 1] == '\n' || sBuffer[uiBoucleBuffer + 1] == '\t') {
					
						// Verification du fichier
						if(sBuffer[0] == '\n') {
							CException * CEXObject = new CException(ERREURTAILLE, "Il manque des lignes dans la matrice du fichier");
							throw *CEXObject;
						}
					
						matPAMMatrice.MATModifierElement(uiIndiceLigne, uiIndiceColonne, stof(sBufferDouble));

						delete(sBufferDouble);
						sBufferDouble = nullptr;
						uiIndiceColonne++;
					}

					// Sinon on recommence une boucle pour aller concatener la dizaine, centaine...
					else {
						uiMaxColonne++;
					}
				}

				// En cas d'espace en trop ex : 2    4 5 ; Je continue à parcourir en ignorant
				else {
					uiMaxColonne++;
				}

				// Permet de naviguer dans les colonnes du buffer
				uiBoucleBuffer++;
			
			}

			// Libérer le buffer général pour éviter les fuites
			delete sBuffer;

			// Remise par défaut des variables pour recommencer une boucle
			uiIndiceColonne = 1;
			uiBoucleBuffer = 0;
			uiIndiceLigne++;
		}

		// Fermer le fichier
		PARFermerFicher();
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);
	}
}