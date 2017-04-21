#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


// Utilis� en cas d'exception
#define ECHECALLOCATION 1
#define FORMATFICHIERINCORRECTE 2
#define MAUVAISTYPE 3
#define ERREURTAILLE 4
#define DIVISIONPARZERO 5
#define ECHECOUVERTUREFICHIER 6
#define ECHECLECTURELIGNEFICHIER 7
#define ECHECADDARC 8
#define ECHECNEWSOMMET 9
#define ECHECNONTROUVE 10
#define ECHECDOUBLONARC 11
#define ERREURARGS 12

class CException
{
private: 
	// Attributs
	unsigned int uiEXCCode;
	char * psEXCMessage;

public:
	// Constructeurs et destructeur

	/*****************************
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CException();

	/*****************************
	Constructeur � deux arguments
	******************************
	Entr�e : unsigned int uiCodeErreur, char * psMessageErreur
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : le param�tre est recopi� et ainsi l'objet en cours est initialis�
	*****************************/
	explicit CException(unsigned int uiCodeErreur, char * psMessageErreur);

	/*****************************
	Constructeur de recopie
	******************************
	Entr�e : CException & EXCObjet
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'object en cours en initialis� avec les m�me attributs que l'objet pass� en param�tre
	*****************************/
	CException(CException & EXCObjet);

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est d�truit
	*****************************/
	~CException();

	// Accesseurs

	/*****************************
	Methode : Lecture du code d'erreur
	*****************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : retourne le code d'erreur
	*****************************/
	unsigned int EXCLectureCode();

	/*****************************
	Methode : Modification du code d'erreur
	******************************
	Entr�e : unsigned int uiCodeErreur
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification du code d'erreur
	*****************************/
	void EXCEcritureCode(unsigned int uiCodeErreur);

	/*****************************
	Methode : Lecture du message d'erreur
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affiche le message d'erreur
	*****************************/
	char * EXCLectureMessage();

	/*****************************
	Methode : Modification du message d'erreur
	******************************
	Entr�e : char * psMessage
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modification du message d'erreur
	*****************************/
	void EXCEcritureMessage(char * psMessage);
};
#endif