#include "CException.h"
#include "CGraphe.h"
#include "CParse.h"

#include <vld.h>
void main() {
	try {
	// TEST 1 - Constructeur par défaut
		// Configuration
			// Creation d'un graphe vide
	CGraphe * GRANewGraphe1 = new CGraphe();
			// Test du graphe initialise
				// Test si le graphe existe et si NbSommets et NbArcs du graphe = 0
	if(GRANewGraphe1 != nullptr && GRANewGraphe1->GRAGetNbSommets() != 0 && GRANewGraphe1->GRAGetNbArcs() != 0)
		throw CException(ECHECNONTROUVE, "Erreur du test");

			// Affichage du graphe
	cout << "Test du graphe 1 -> Vide : " << endl;
	GRANewGraphe1->GRAAfficherGraphe();

			// Libération memoire du graphe
	delete(GRANewGraphe1);

	// TEST 2 - Constructeur de confort
		// Création du graphe
	CGraphe * GRANewGraphe2 = new CGraphe();
		// Affectation des 3 sommets au graphe
	GRANewGraphe2->GRAAjoutSommet(1, nullptr, nullptr);
	GRANewGraphe2->GRAAjoutSommet(3, nullptr, nullptr);
	GRANewGraphe2->GRAAjoutSommet(2, nullptr, nullptr);
		// Vérification du compteur général du nombre de sommet dans le graphe
	//if(GRANewGraphe2->GRAGetNbSommets() != 3)
	//	throw CException(ERREURTEST, "Erreur du test, il n'y a pas 3 sommets");
			// Ajouter des arcs
				// 1 vers 3
	GRANewGraphe2->GRAAjoutArc(3, GRANewGraphe2->GRATrouverSommet(1));
	//GRANewGraphe2->GRAAjoutArc(3, GRANewGraphe2->GRATrouverSommet(1));
	// ICI !!!!! FUITE SI JE LEVE L EXCEPTION !!!!!!!

			// Affichage du graphe
	cout << "Test du graphe 2 -> Non vide : " << endl;
	GRANewGraphe2->GRAAfficherGraphe();

		// Liberation memoire du graphe
	//delete(GRANewGraphe2);

	}
	catch (CException e) {
		cout << e.EXCLectureMessage() << endl;
	}

	cout << "test";
}