#include "jeux.h"
#include "Matrice.h"
#include "Ensemble.cpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void devineNbr() {
	vector<int> essais;	
	int random = rand() % 251;	
	int guess;
	
		
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

	cout << "\n\nJeu de sudoku\n";
	do {
		grille.showEq();
		inserer(grille);	
	}while(true);
}

void inserer(Matrice<int> &grille) {
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

bool ligneEstValide(size_t ligne, Ensemble<int> &ens, Matrice<int> grille) {
	for( size_t i = 0 ; i < 9 ; ++i ) {
		ens.ajouteMembre(grille.getCell( ligne, i));
	}
	return ens.size() == 9; 
}

bool colonneEstValide(size_t colonne, Ensemble<int> &ens, Matrice<int> grille) {
	for( size_t i = 0 ; i < 9 ; ++i) {
		ens.ajouteMembre(grille.getCell( i, colonne ));
	}
	return ens.size() == 9;
}
