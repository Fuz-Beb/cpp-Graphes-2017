#include "CParseMatrice.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParseMatrice::CParseMatrice()
{
	matPAMMatrice = CMatrice<double>();
}

/*****************************
Methode : Retourner Matrice
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : Retourne un pointeur sur l'attribut de matPAMMatrice
Entraine : Cr�ation d'un objet/pointeur en appellant le constructeur de recopie de CMatrice
*****************************/
CMatrice<double> * CParseMatrice::PAMRetournerMatrice()
{
	CMatrice<double> * pMatriceRetourner = new CMatrice<double>(matPAMMatrice);
	return pMatriceRetourner;
}

/*****************************
Methode : Lire Nombre Lignes
*****************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int
Entraine : Retourne le nombre de lignes pr�c�demment lu
*****************************/
unsigned int CParseMatrice::PAMLireNbLignes()
{
	return uiPAMNbLignes;
}

/*****************************
Methode : Assigner Nombre Lignes
******************************
Entr�e : n�ant
Necessit� : M�thode Traiter fichier / Ouvrir fichier
Sortie : n�ant
Entraine : Assigner le nombre de colonnes lu
*****************************/
void CParseMatrice::PAMAssignerNbLignes()
{
	try {
		char * sBuffer = nullptr, * sRetour = nullptr;

		sBuffer = CParse::PARLireLigne();

		// Verification du pr�fixe avant le =
		sRetour = PARSubString(sBuffer, 0, 9);

		if(strcmp(sRetour, "nblignes=") == 1) {
			delete(sBuffer);
			delete(sRetour);

			CException * CEXObject = new CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBLignes=");
			throw *CEXObject;
		}

		delete(sRetour);

		// V�rification de la valeur et conversion string vers int
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int
Entraine : Retourne le nombre de colonnes qui a �t� pr�c�demment lu
*****************************/
unsigned int CParseMatrice::PAMLireNbColonnes()
{
	return uiPAMNbColonnes;
}

/*****************************
Methode : Assigner nombre colonnes
******************************
Entr�e : n�ant
Necessit� : M�thode Traiter fichier / Ouvrir fichier
Sortie : n�ant
Entraine : Assigner le nombre de colonne lu
*****************************/
void CParseMatrice::PAMAssignerNbColonnes()
{
	try {
		char *sBuffer = nullptr, * sRetour = nullptr;
	
		sBuffer = CParse::PARLireLigne();

		// Verification du pr�fixe nbcolonnes
		sRetour = PARSubString(sBuffer, 0, 11);

		if(strcmp(sRetour, "nbcolonnes=") == 1) {
			delete(sBuffer);
			delete(sRetour);

				CException * CEXObject = new CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de NBColonnes=");
				throw *CEXObject;
		}

		delete(sRetour);

		// V�rification de la valeur et conversion string vers int
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
Methode : V�rifier le type
******************************
Entr�e : n�ant
Necessit� : M�thode Traiter fichier / Ouvrir fichier
Sortie : n�ant
Entraine : La v�rification du type double sur la lecture du fichier
*****************************/
void CParseMatrice::PAMVerifierType() 
{
	try {
		char * sBuffer = nullptr, * sRetour = nullptr;

		sBuffer = CParse::PARLireLigne();

		// Verification du pr�fixe typematrice
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

		// V�rifier que le fichier lu est bien une matrice double
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
Entr�e : char * sChemin
Necessit� : n�ant
Sortie : n�ant
Entraine : La lecture du fichier et cr�ation de la matrice associ�e
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

		// V�rification qu'on va bien lire une matrice double
		PAMVerifierType();

		// Lecture et �criture attribut du nombre de ligne
		PAMAssignerNbLignes();

		// Lecture et �criture attribut du nombre de colonne
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

		// Cr�ation d'une CMatrice selon sa taille lu
		matPAMMatrice = CMatrice<double>(uiPAMNbLignes, uiPAMNbColonnes);
		
		// Boucle TQ concernant le nombre de ligne � lire
		while(uiIndiceLigne <= uiPAMNbLignes) {

			uiMaxColonne = uiPAMNbColonnes; // Remise du compteur de colonne � la taille par souhait� (utile dans le cas d'espace)

			sBuffer = PARLireLigne(); // Remplissage du buffer par rapport � la ligne actuel

			// Verification du fichier
			if(strcmp(sBuffer, "]") == 0) {
				PARFermerFicher();
				CException * CEXObject = new CException(ERREURTAILLE, "Il manque des lignes dans la matrice du fichier");
				throw *CEXObject;
			}

			// Boucle TQ concernant le nombre de colonne � lire (g�re les espaces en trop)
			while(uiBoucleBuffer < uiMaxColonne) {
			
				// Permet de v�rifier si il y a des espaces entre les �l�ments
				if(sBuffer[uiBoucleBuffer] != ' ') { 

					// Permet de g�rer le cas o� l'�lement � une dizaine, centaine...
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

					// Dans le cas o� le second buffer d'�l�ment est vide, alors j'en cr�er un.
					else {
						sBufferDouble = PARSubString(sBuffer, uiBoucleBuffer, 1);
					}
				
					// Incr�mentation de l'indice du second buffer (dans le cas o� dizaine, centaine...)
					uiBoucleBufferDouble++;

					// On v�rifie s'il y a une dizaine, centaine... o� si on s'arrete et on modifie l'�lement dans la CMatrice
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

				// En cas d'espace en trop ex : 2    4 5 ; Je continue � parcourir en ignorant
				else {
					uiMaxColonne++;
				}

				// Permet de naviguer dans les colonnes du buffer
				uiBoucleBuffer++;
			
			}

			// Lib�rer le buffer g�n�ral pour �viter les fuites
			delete sBuffer;

			// Remise par d�faut des variables pour recommencer une boucle
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