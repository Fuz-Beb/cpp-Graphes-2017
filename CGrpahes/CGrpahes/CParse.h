#ifndef C_PARSE_H
#define C_PARSE_H
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>

using namespace std;

class CParse
{
private:
	// Attributs
	char * psPARChemin;
	FILE * pPARFichier;

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
	explicit CParse();

	/*****************************
	Constructeur de confort
	******************************
	Entr�e : char * psChemin
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CParse(char * psChemin);

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet est d�truit
	*****************************/
	~CParse();

	// Accesseurs

	/*****************************
	Methode : Lire Chemin
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : char *
	Entraine : retourne le chemin de l'attribut
	*****************************/
	char * PARLireChemin();

	/*****************************
	Methode : Modifier Chemin
	******************************
	Entr�e : char * sParam
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification de l'attribut sPARChemin
	*****************************/
	void PARModifierChemin(char * psParam);

	/*****************************
	Methode : Ouvrir Fichier
	******************************
	Entr�e : char * sChaine
	Necessit� : Fichier
	Sortie : n�ant
	Entraine : ouverture un fichier
	*****************************/
	void PAROuvrirFichier(char * psParam);

	/*****************************
	Methode : Fermer Fichier
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : Fermeture du fichier
	*****************************/
	void PARFermerFicher();

	// M�thodes

	/*****************************
	Methode : Lire Ligne
	******************************
	Entr�e : n�ant
	Necessit� : M�thode Traiter fichier / Ouvrir fichier
	Sortie : char *
	Entraine : lecture d'une ligne du fichier et retourne sur le tas une cha�ne
	*****************************/
	char * PARLireLigne();

	/*****************************
	Methode : SubString
	******************************
	Entr�e : char * sParam, unsigned int uiDebut, unsigned int uiTaille
	Necessit� : n�ant
	Sortie : char *
	Entraine : permet d'extraire une cha�ne d'une position � une autre
	*****************************/
	char * PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille);

	/*****************************
	Methode : Concatener deux chaines
	******************************
	Entr�e : const char * sStr1, const char * sStr2
	Necessit� : n�ant
	Sortie : char *
	Entraine : retourne sur le tas la concatenation des deux cha�nes
	*****************************/
	char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2);

	/*****************************
	Methode : Convertir Chaine Minuscule
	******************************
	Entr�e : char * sChaine
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : convertir la chaine en param�tre en minuscule
	*****************************/
	void PARConvertirStrMinusc(char * psParam);

	/*****************************
	Methode : Convertir un char en minuscule
	******************************
	Entr�e : char cParam
	Necessit� : M�thode Ouvrir fichier
	Sortie : char
	Entraine : Conversion d'un char en char minuscule
	*****************************/
	char PARConvertirCharMinusc(char cParam);
};
#endif
