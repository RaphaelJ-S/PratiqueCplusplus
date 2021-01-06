#include "jeux.h"
#include "Matrice.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int choice;
	
	do{
		cout << "\n\nMenu Des Jeux";
		cout << "\n\n0. Arrêter\n1. Devine le nombre!\n2. Sudoku!";
		cout << "\nEntrez votre choix : ";
		cin >> choice;
		
		switch(choice){
			case 0:
				cout << "\nQuitting\n";
				break;
			case 1:
				devineNbr();
				break;
			case 2:
				sudoku();
				break;
		}
	}while(choice != 0);

	return 0;

}
