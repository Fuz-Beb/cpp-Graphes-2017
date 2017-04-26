#include "CException.h"
#include "CGraphe.h"
#include "CParse.h"

#include <vld.h>

void testMethodesGraphe();
void testMethodesSommet();

// Ne pas garder ce main pour le rendu c'est sale car par .h pour les protos fonctions...
void main() {
	//testMethodesGraphe();
	//testMethodesSommet();
}

// Il reste les m�thodes comme modifier...
void testMethodesGraphe() {
	// Declaration des graphes
	CGraphe * GRANewGraphe1 = new CGraphe();
	CGraphe * GRANewGraphe2 = new CGraphe();

	try {
		GRANewGraphe1 = new CGraphe();
		GRANewGraphe2 = new CGraphe();
	}
	catch (CException e) {
		cout << e.EXCLectureMessage();
	}

	try {
		// TEST 1 - Constructeur par d�faut
		cout << "--- Test du graphe 1 -> Vide : " << endl;
			// Configuration
				// Test du graphe initialise
					// Test si le graphe existe et si NbSommets et NbArcs du graphe = 0
		if(GRANewGraphe1 != nullptr && GRANewGraphe1->GRAGetNbSommets() != 0 || GRANewGraphe1->GRAGetNbArcs() != 0)
			throw CException(ECHECNONTROUVE, "Erreur du test");

				// Affichage du graphe
		GRANewGraphe1->GRAAfficherGraphe();

		// TEST 2 - Constructeur de confort
		cout << "--- Test du graphe 2 -> Non vide : " << endl;
			// Affectation des 3 sommets au graphe
		GRANewGraphe2->GRAAjoutSommet(4, nullptr, nullptr);
		GRANewGraphe2->GRAAjoutSommet(1, nullptr, nullptr);
		GRANewGraphe2->GRAAjoutSommet(3, nullptr, nullptr);
		GRANewGraphe2->GRAAjoutSommet(2, nullptr, nullptr);
			// V�rification du compteur g�n�ral du nombre de sommet dans le graphe
		if(GRANewGraphe2->GRAGetNbSommets() != 4)
			throw CException(ERREURTEST, "Erreur du test, il n'y a pas 3 sommets");
				// Ajouter des arcs
					// 1 vers 1
		GRANewGraphe2->GRAAjoutArc(1, GRANewGraphe2->GRATrouverSommet(1));
					// 1 vers 3
		GRANewGraphe2->GRAAjoutArc(3, GRANewGraphe2->GRATrouverSommet(1));
					// 1 vers 2
		GRANewGraphe2->GRAAjoutArc(2, GRANewGraphe2->GRATrouverSommet(1));
					// 1 vers 4
		GRANewGraphe2->GRAAjoutArc(4, GRANewGraphe2->GRATrouverSommet(1));
					// 2 vers 1
		GRANewGraphe2->GRAAjoutArc(1, GRANewGraphe2->GRATrouverSommet(2));
				// Affichage du graphe
		GRANewGraphe2->GRAAfficherGraphe();
	}
	catch (CException e) {
		cout << e.EXCLectureMessage() << endl;
	}

	// Test d'exception : Si on creer deux fois le meme arc
		cout << "--- Test du graphe 2 Exception -> Affichage Doublon d'arc : " << endl;
	try {
		GRANewGraphe2->GRAAjoutArc(3, GRANewGraphe2->GRATrouverSommet(1));
	}
	catch (CException e) {
		cout << e.EXCLectureMessage() << endl;
	}
	// Lib�ration memoire du graphe
	delete(GRANewGraphe1);
	// Liberation memoire du graphe
	delete(GRANewGraphe2);
}

void testMethodesSommet() {
	// Declaration des attributs
	CSommet * SOMNewSommetDefaut = nullptr;
	CSommet * SOMNewSommetConfort = nullptr;
	CSommet * SOMNewSommetRecopie = nullptr;
	
	try {
		SOMNewSommetDefaut = new CSommet();
		SOMNewSommetConfort = new CSommet(2, nullptr, nullptr);	
		SOMNewSommetRecopie = new CSommet(*SOMNewSommetConfort);
	}
	catch (CException e) {
		cout << e.EXCLectureMessage();
	}

	try {
		// TEST 1 - Constructeur par defaut
		cout << "--- Test du sommet 1 -> Vide : " << endl;
			// Configuration
				// Test du graphe initialise
					// Test si le graphe existe et si NbSommets et NbArcs du graphe = 0
		if(SOMNewSommetDefaut == nullptr || SOMNewSommetDefaut->SOMGetNum() != 0 || SOMNewSommetDefaut->SOMGetNbrArcArrivant() != 0 || SOMNewSommetDefaut->SOMGetNbrArcPartant() != 0)
			throw CException(ECHECNONTROUVE, "Erreur du test");
		cout << "Test ok" << endl;
	}
	catch (CException e) {
		cout << e.EXCLectureMessage() << endl;
	}

	try {
		// Lib�ration memoire des sommets
		delete(SOMNewSommetDefaut);
		delete(SOMNewSommetConfort);
		// FAIRE UN TEST DANS LE DESTRUCTEUR ARC SI PAS d4ARC ALORS NE RIEN FAIRE !!!!!
		delete(SOMNewSommetRecopie);
	}
	catch (CException e) {
		cout << e.EXCLectureMessage();
	}
}