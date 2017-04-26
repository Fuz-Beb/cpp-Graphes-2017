#include "CParse.h"
#include "CException.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParse::CParse()
{
	psPARChemin = nullptr;
	pPARFichier = nullptr;
}

/*****************************
Constructeur de confort
******************************
Entr�e : char * psChemin
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CParse::CParse(char * psChemin)
{
	CParse();
	PARModifierChemin(psChemin);
}

/*****************************
Destructeur par d�faut
*****************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet est d�truit
*****************************/
CParse::~CParse()
{
	delete(psPARChemin);
	PARFermerFicher();
}

/*****************************
Methode : Lire Chemin
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : char *
Entraine : retourne le chemin de l'attribut
*****************************/
char * CParse::PARLireChemin()
{
	return psPARChemin;
}

/*****************************
Methode : Modifier Chemin
******************************
Entr�e : char * sParam
Necessit� : n�ant
Sortie : n�ant
Entraine : modification de l'attribut sPARChemin
*****************************/
void CParse::PARModifierChemin(char * psParam)
{
	try {
		unsigned int uiTaille = strlen(psParam);

		if(psPARChemin != NULL)
			delete(psPARChemin);

		psPARChemin = (char*) calloc(uiTaille + 1, sizeof(char));

		if(psPARChemin == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		strncpy(psPARChemin, psParam, uiTaille);
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return;
	}
}

/*****************************
Methode : Ouvrir Fichier
*****************************
Entr�e : char * sChaine
Necessit� : Fichier
Sortie : n�ant
Entraine : ouverture un fichier
*****************************/
void CParse::PAROuvrirFichier(char * psParam)
{
	try {
		pPARFichier = fopen(psParam, "r");

		if(pPARFichier == nullptr)
			throw CException(ECHECOUVERTUREFICHIER, "Echec d'ouverture du fichier");

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);
	}
}

/*****************************
Methode : Fermer Fichier
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : Fermeture du fichier
*****************************/
void CParse::PARFermerFicher()
{
	if(pPARFichier != NULL)
		fclose(pPARFichier);
}

/*****************************
Methode : Lire Ligne
******************************
Entr�e : n�ant
Necessit� : M�thode Traiter fichier / Ouvrir fichier
Sortie : char *
Entraine : lecture d'une ligne du fichier et retourne sur le tas une cha�ne
*****************************/
char * CParse::PARLireLigne()
{
	try {
		// Position de d�part
		unsigned int uiCurseurInitial = ftell(pPARFichier);
		unsigned int uiSizeMaxBuffer = 0;

		// Mise du curseur � la fin du fichier pour le calcul de la taille de la chaine
		fseek(pPARFichier, 0, SEEK_END);

		// R�cup�ration de la taille maximum du buffer
		uiSizeMaxBuffer = ftell(pPARFichier) - uiCurseurInitial + 1;
	
		// Allocation de la chaine avec la "bonne taille"
		char * psBuffer = (char*) malloc (sizeof(char) * uiSizeMaxBuffer);
		if(psBuffer == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		fseek(pPARFichier, uiCurseurInitial, SEEK_SET);

		// R�cup�ration de la ligne
		psBuffer = fgets(psBuffer, uiSizeMaxBuffer, pPARFichier);
	
		if (psBuffer == nullptr)
			throw CException(ECHECLECTURELIGNEFICHIER, "Erreur lors de la lecture d'une ligne du fichier");

		// Mise � l'�chelle de la chaine retourn�e
		psBuffer = (char*) realloc(psBuffer, sizeof(char) * (strlen(psBuffer) + 1));
		if (psBuffer == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		return psBuffer;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}

/*****************************
Methode : SubString
******************************
Entr�e : char * sParam, unsigned int uiDebut, unsigned int uiTaille
Necessit� : n�ant
Sortie : char *
Entraine : permet d'extraire une cha�ne d'une position � une autre
*****************************/
char * CParse::PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille)
{
	try {
		char * psRetour = (char *) malloc(sizeof(char) * uiTaille + 1);
		if(psRetour == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		memcpy(psRetour, &psParam[uiDebut], uiTaille);
		psRetour[uiTaille] = '\0';

		PARConvertirStrMinusc(psRetour);

		return psRetour;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}

/*****************************
Methode : Concatener deux chaines
******************************
Entr�e : const char * sStr1, const char * sStr2
Necessit� : n�ant
Sortie : char *
Entraine : retourne sur le tas la concatenation des deux cha�nes
*****************************/
char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2) 
{
	try {
		size_t lengthStr1 = strlen(psStr1);
		size_t lengthStr2 = strlen(psStr2);
		char * psConcatenate = (char*)malloc(strlen(psStr1) + strlen(psStr2) + 1);

		if(psConcatenate == NULL) {
			free(psConcatenate);
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		strncpy(psConcatenate, psStr1, lengthStr1);
		strncpy(psConcatenate + lengthStr1, psStr2, lengthStr2);

		return psConcatenate;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}

/*****************************
Methode : Convertir Chaine Minuscule
******************************
Entr�e : char * sChaine
Necessit� : n�ant
Sortie : n�ant
Entraine : convertir la chaine en param�tre en minuscule
*****************************/
void CParse::PARConvertirStrMinusc(char * psParam)
{
    int uiBoucle = 0;

    while(psParam[uiBoucle] != '\0') {
        psParam[uiBoucle] = PARConvertirCharMinusc(psParam[uiBoucle]);
		uiBoucle++;
	}
}

/*****************************
Methode : Convertir un char en minuscule
******************************
Entr�e : char cParam
Necessit� : M�thode Ouvrir fichier
Sortie : char
Entraine : Conversion d'un char en char minuscule
*****************************/
char CParse::PARConvertirCharMinusc(char cParam) 
{
    int iTemp = (int)cParam;

    if(iTemp >= 'A' && iTemp <= 'Z') {
		iTemp = iTemp + ('a' - 'A');
        return (char)iTemp;
	}
    else
        return cParam;
}

/*****************************
Methode : Rechercher un caract�re dans une chaine
******************************
Entr�e : char sCaractere, char * psChaine
Necessit� : M�thode Ouvrir fichier
Sortie : int
Entraine : retourne la position du caractere
*****************************/
int CParse::PARRechercheCaractere(char sCaractere, char * psChaine)
{
	unsigned int uiBoucle = 0;

	while (uiBoucle < strlen(psChaine) && psChaine[uiBoucle] != '\0')
	{
		if (psChaine[uiBoucle] == sCaractere)
			return uiBoucle;
		uiBoucle++;
	}
	return -1;
}

/*****************************
Methode : Recuperer la chaine presente apres le premier caractere '=' rencontre
******************************
Entr�e : char * psChaineAvantEgal, char * sBuffer
Necessit� : M�thode Ouvrir fichier
Sortie : int
Entraine : retourne le int apres le caractere '='
*****************************/
int CParse::PARValeurApresSigneEgal(char * psChaineAvantEgal, char * sBuffer) {

	// D�clarations des variables
	char * sRetour = nullptr;

	// R�cup�ration du pr�fixe a gauche du signe '='
	sRetour = PARSubString(sBuffer, 0, strlen(psChaineAvantEgal));

	// Comparaison du pr�fixe avec celui donn� en param�tre
	if(strcmp(sRetour, psChaineAvantEgal) == 1) {
		delete(sBuffer);
		delete(sRetour);
		throw CException(FORMATFICHIERINCORRECTE, "Erreur : Balise incorrecte dans le fichier");
	}

	delete(sRetour);

	// R�cup�ration de la valeur situ�e � droite du signe '='
	sRetour = PARSubString(sBuffer, PARRechercheCaractere('=', sBuffer) + 1, strlen(sBuffer) - strlen(psChaineAvantEgal));

	if(sRetour == NULL) {
		delete(sBuffer);
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Retourne la conversion du string vers un int
	return atoi(sRetour);
}

/*****************************
Methode : Compare deux chaines de caract�res
******************************
Entr�e : char * psChaineUn, char * psChaineDeux
Necessit� : M�thode Ouvrir fichier
Sortie : boolean
Entraine : retourne true si les deux chaines sont identiques et faux sinon
*****************************/
int CParse::PARCompareChaine(char * psChaineUn, char * psChaineDeux)
{
	if (psChaineUn == nullptr || psChaineDeux == nullptr)
		throw CException(ERREURARGS, "Les deux chaines pass�es en param�tre ne peuvent pas �tre null");

	PARConvertirStrMinusc(psChaineUn);
	PARConvertirStrMinusc(psChaineDeux);

	if (strcmp(psChaineUn, psChaineDeux) == 1) {
		delete(psChaineUn);
		delete(psChaineDeux);
		return false;
	}
	else {
		delete(psChaineUn);
		delete(psChaineDeux);
		return true;
	}
}