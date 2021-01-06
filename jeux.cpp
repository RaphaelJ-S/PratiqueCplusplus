#include "jeux.h"
#include "Matrice.h" 
#include "Ensemble.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;

static bool ligneEstComplete(size_t ligne, Matrice<int> grille) {
	Ensemble<int> ens;
	for( size_t i = 0 ; i < 9 ; ++i ) {
		ens.ajouteMembre(grille.getCell( ligne, i));
	}
	return ens.size() == 9; 
}

static bool colonneEstComplete(size_t colonne, Matrice<int> grille) {
	Ensemble<int> ens;
	for( size_t i = 0 ; i < 9 ; ++i) {
		ens.ajouteMembre(grille.getCell( i, colonne ));
	}
	return ens.size() == 9;
}

static bool sectionEstComplete(size_t section, Matrice<int> grille) {
	Ensemble<int> ens;
	size_t ligne = section / 3 * 3;
	size_t colonne = section < 3 ? section * 3 : section % 3 * 3; 
	for( size_t i = 0; i < 9 ; ++i) {
		if (i > 2 && i % 3 == 0 ) {
			ligne++;
			colonne	= section < 3 ? section * 3 : section % 3 * 3; 
		}
		ens.ajouteMembre(grille.getCell( ligne, colonne ));
		colonne++;
	}
	return ens.size() == 9;
}

static bool sudokuEstComplet(Matrice<int> grille) {
	size_t i = 0;	
	while(sectionEstComplete(i, grille) && colonneEstComplete(i, grille) && ligneEstComplete(i, grille)) {
		++i;
		if(i == 9) return true;
	}
	return false;
}
static void inserer(Matrice<int> &grille) {
	int nombre;
	size_t ligne;
	size_t colonne;
	cout << "\nEntrez le nombre que vous voulez insérer dans la grille : ";
	cin >> nombre;
	cout << "\nEntrez la ligne de la grille : ";
	cin >> ligne;
	cout << "\nEntrez la colonne de la grille : ";
	cin >> colonne;
	grille.setCell(nombre, ligne-1, colonne-1);
}

void devineNbr() {
	vector<int> essais;	
  int random = rand() % 251;	int guess;
	cout << "\n\nJeu DEVINE";

	do {
		cout << "\nDevinez le nombre entre 0 et 250(-1 pour abandonner) : ";
	
		cin >> guess;

		if(guess == random) cout << "Félicitation! Le nombre était bien " << random;
		else if (guess < random) cout << "Trop bas!";
		else if (guess > random) cout << "Trop haut!";
		essais.push_back(guess);
	
	}while (guess != random && guess != -1);
	
	size_t longueur = essais.size();
	cout << "\nVous avez esseyer " << longueur<< " fois. Voici vos essais : \n";	
	
	for( size_t i = 0; i < longueur-1 ; ++i) {
		cout << essais[i] << " ";
	}	
}


void sudoku() {

	Matrice<int> grille(9,9);
	Ensemble<int> set;
	cout << "\n\nJeu de sudoku\n";
	
	do {
		grille.show();
		inserer(grille);	
	}while(!sudokuEstComplet(grille));
	cout << "\nFélicitation"<< endl;
}



