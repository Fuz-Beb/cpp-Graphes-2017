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
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int
	Entraine : Retourne le nombre de lignes précédemment lu
	*****************************/
	unsigned int PAMLireNbLignes();

	/*****************************
	Methode : Assigner Nombre Lignes
	******************************
	Entrée : néant
	Necessité : Méthode Traiter fichier / Ouvrir fichier
	Sortie : néant
	Entraine : Assigner le nombre de colonnes lu
	*****************************/
	void PAMAssignerNbLignes();

	/*****************************
	Methode : Lire Nombre Colonnes
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int
	Entraine : Retourne le nombre de colonnes qui a été précédemment lu
	*****************************/
	unsigned int PAMLireNbColonnes();

	/*****************************
	Methode : Assigner nombre colonnes
	******************************
	Entrée : néant
	Necessité : Méthode Traiter fichier / Ouvrir fichier
	Sortie : néant
	Entraine : Assigner le nombre de colonne lu
	*****************************/
	void PAMAssignerNbColonnes();
	
	// Methodes

	/*****************************
	Methode : Vérifier le type
	******************************
	Entrée : néant
	Necessité : Méthode Traiter fichier / Ouvrir fichier
	Sortie : néant
	Entraine : La vérification du type double sur la lecture du fichier
	*****************************/
	void PAMVerifierType();
	
public:
	// Constructeur

	/*****************************
	Constructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CParseMatrice();

	// Methodes

	/*****************************
	Methode : Retourner Matrice
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : Retourne un pointeur sur l'attribut de matPAMMatrice
	Entraine : Création d'un objet/pointeur en appellant le constructeur de recopie de CMatrice
	*****************************/
	CMatrice<double> * PAMRetournerMatrice();

	/*****************************
	Methode : Traiter fichier
	******************************
	Entrée : char * sChemin
	Necessité : néant
	Sortie : néant
	Entraine : La lecture du fichier et création de la matrice associée
	*****************************/
	void PAMTraiterFichier(char * sChemin);
};

#endif