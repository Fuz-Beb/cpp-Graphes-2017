#include "CException.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CException::CException()
{
	uiEXCCode = 0;
	psEXCMessage = nullptr;
}

/*****************************
Constructeur � deux arguments
******************************
Entr�e : unsigned int uiCodeErreur, char * psMessageErreur
Necessit� : n�ant
Sortie : n�ant
Entraine : le param�tre est recopi� et ainsi l'objet en cours est initialis�
*****************************/
CException::CException(unsigned int uiCodeErreur, char * psMessageErreur)
{
	uiEXCCode = uiCodeErreur;

	psEXCMessage = (char*) malloc(sizeof(char) * strlen(psMessageErreur) + 1);
	if (psEXCMessage == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psEXCMessage, psMessageErreur, strlen(psMessageErreur) + 1);
}

/*****************************
Constructeur de recopie
******************************
Entr�e : CException & EXCObjet
Necessit� : n�ant
Sortie : n�ant
Entraine : l'object en cours en initialis� avec les m�me attributs que l'objet pass� en param�tre
*****************************/
CException::CException(CException & EXCObjet)
{
	uiEXCCode = EXCObjet.uiEXCCode;

	psEXCMessage = (char*) malloc(sizeof(char) * strlen(EXCObjet.psEXCMessage) + 1);
	if (psEXCMessage == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psEXCMessage, EXCObjet.psEXCMessage, strlen(EXCObjet.psEXCMessage) + 1);
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est d�truit
*****************************/
CException::~CException()
{
	if (psEXCMessage != nullptr)
		delete psEXCMessage;
}

/*****************************
Methode : Lecture du code d'erreur
*****************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int
Entraine : retourne le code d'erreur
*****************************/
unsigned int CException::EXCLectureCode()
{
	return uiEXCCode;
}

/*****************************
Methode : Modification du code d'erreur
******************************
Entr�e : unsigned int uiCodeErreur
Necessit� : n�ant
Sortie : n�ant
Entraine : modification du code d'erreur
*****************************/
void CException::EXCEcritureCode(unsigned int uiCodeErreur)
{
	uiEXCCode = uiCodeErreur;
}

/*****************************
Methode : Lecture du message d'erreur
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : affiche le message d'erreur
*****************************/
char * CException::EXCLectureMessage()
{
	return psEXCMessage;
}

/*****************************
Methode : Modification du message d'erreur
******************************
Entr�e : char * psMessage
Necessit� : n�ant
Sortie : n�ant
Entraine : modification du message d'erreur
*****************************/
void CException::EXCEcritureMessage(char * psMessage)
{
	if (psEXCMessage == nullptr)
		delete psEXCMessage;

	psEXCMessage = (char*) malloc(sizeof(char) * strlen(psMessage) + 1);
	if (psEXCMessage == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	
	strncpy(psEXCMessage, psMessage, strlen(psMessage) + 1);
}