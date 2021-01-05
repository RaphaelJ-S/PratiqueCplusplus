#include "Matrice.h"
#include <iostream>
template<typename T>
Matrice<T>::Matrice(size_t ligne, size_t colonne) {
	this->matrice = new T[ligne * colonne];	
	nbrLigne = ligne;
	nbrColonne = colonne;	
}

template<typename T>
Matrice<T>::~Matrice(){
	delete[] matrice;
}

template<typename T>
T Matrice<T>::getCell(const size_t ligne, const size_t colonne) {
	return matrice[(ligne * nbrColonne) + colonne];
}

template<typename T>
size_t Matrice<T>::getNbrLigne() {
	return nbrLigne;
}

template<typename T>
size_t Matrice<T>::getNbrColonne() {
	return nbrColonne;
}

template<typename T>
T* Matrice<T>::getMatrice() {
	return matrice;	
}

template<typename T>
void Matrice<T>::setCell(const T nombre, const size_t ligne, const size_t colonne) {
	matrice[(ligne * nbrColonne) + colonne] = nombre;
}

template<typename T>
void Matrice<T>::showEq() {
	for( size_t i = 0; i < nbrLigne; ++i ) {

		for( size_t j = 0 ; j < nbrColonne - 1; ++j) {
			std::cout << " " << getCell(i, j) << " ";
		}

		std::cout << " | " << getCell(i, nbrColonne -1) << std::endl;
	}
}

template<typename T>
void Matrice<T>::showSh() {

}
template class Matrice<short>;
template class Matrice<int>;
template class Matrice<size_t>;
template class Matrice<long>;
template class Matrice<float>;
template class Matrice<double>;//prefered
