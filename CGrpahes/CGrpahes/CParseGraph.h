#ifndef C_PARSEMATRICE_H
#define C_PARSEMATRICE_H

#include "CParse.h"
#include "CMatrice.h"
#include <string>

class CParseMatrice : private CParse
{
private:
	// Attributs
	unsigned int uiPAMNbLignes;
	unsigned int uiPAMNbColonnes;
	CMatrice<double> matPAMMatrice;
	
	// Accesseurs

	/*****************************
	Methode : Lire Nombre Lignes
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : Retourne le nombre de lignes pr�c�demment lu
	*****************************/
	unsigned int PAMLireNbLignes();

	/*****************************
	Methode : Assigner Nombre Lignes
	******************************
	Entr�e : n�ant
	Necessit� : M�thode Traiter fichier / Ouvrir fichier
	Sortie : n�ant
	Entraine : Assigner le nombre de colonnes lu
	*****************************/
	void PAMAssignerNbLignes();

	/*****************************
	Methode : Lire Nombre Colonnes
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : Retourne le nombre de colonnes qui a �t� pr�c�demment lu
	*****************************/
	unsigned int PAMLireNbColonnes();

	/*****************************
	Methode : Assigner nombre colonnes
	******************************
	Entr�e : n�ant
	Necessit� : M�thode Traiter fichier / Ouvrir fichier
	Sortie : n�ant
	Entraine : Assigner le nombre de colonne lu
	*****************************/
	void PAMAssignerNbColonnes();
	
	// Methodes

	/*****************************
	Methode : V�rifier le type
	******************************
	Entr�e : n�ant
	Necessit� : M�thode Traiter fichier / Ouvrir fichier
	Sortie : n�ant
	Entraine : La v�rification du type double sur la lecture du fichier
	*****************************/
	void PAMVerifierType();
	
public:
	// Constructeur

	/*****************************
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CParseMatrice();

	// Methodes

	/*****************************
	Methode : Retourner Matrice
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : Retourne un pointeur sur l'attribut de matPAMMatrice
	Entraine : Cr�ation d'un objet/pointeur en appellant le constructeur de recopie de CMatrice
	*****************************/
	CMatrice<double> * PAMRetournerMatrice();

	/*****************************
	Methode : Traiter fichier
	******************************
	Entr�e : char * sChemin
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : La lecture du fichier et cr�ation de la matrice associ�e
	*****************************/
	void PAMTraiterFichier(char * sChemin);
};

#endif