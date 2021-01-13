#include "Matrice.h"
#include <iostream>

template<typename T>
Matrice<T>::Matrice() {
	this->matrice = new T[0];
	nbrLigne = 0;
	nbrColonne = 0;
}

template<typename T>
Matrice<T>::Matrice(const size_t ligne, const size_t colonne) 
{
	if( ligne > 0 && colonne > 0) 
	{
		this->matrice = new T[ligne * colonne];	
		nbrLigne = ligne;
		nbrColonne = colonne;
		for ( size_t i = 0 ; i < ligne*colonne ; ++i) matrice[i] = 0;	
	
	}else std::cout << "La matrice doit contenir au minimum 1 colonne et 1 ligne" << std::endl;
}

template<typename T>
Matrice<T>::~Matrice()
{
	delete[] matrice;
}

template<typename T>
T Matrice<T>::getCell(const size_t ligne, const size_t colonne) 
{
	return matrice[(ligne * nbrColonne) + colonne];
}

template<typename T>
size_t Matrice<T>::getNbrLigne() 
{
	return nbrLigne;
}

template<typename T>
size_t Matrice<T>::getNbrColonne() 
{
	return nbrColonne;
}

template<typename T>
T* Matrice<T>::getMatrice() 
{
	return matrice;	
}

template<typename T>
void Matrice<T>::setCell(const T nombre, const size_t ligne, const size_t colonne) 
{
	matrice[(ligne * nbrColonne) + colonne] = nombre;
}

template<typename T>
void Matrice<T>::show() 
{
	for( size_t i = 0; i < nbrLigne; ++i ) 
	{
		for( size_t j = 0 ; j < nbrColonne ; ++j) 
		{
			std::cout << " " << getCell(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
Matrice<T> Matrice<T>::operator+(const Matrice& arg) const{

	if(this->nbrColonne == arg.nbrColonne && this->nbrLigne == arg.nbrLigne) {
		
		Matrice<T> matrice(arg.nbrLigne, arg.nbrColonne);

		for	(size_t i = 0; i < this->nbrColonne*this->nbrLigne ; ++i) {
			matrice.matrice[i] = this->matrice[i] + arg.matrice[i];
		}
		return matrice;

	}else std::cout << "Les matrices doivent avoir le même nombre de lignes et de colonnes" << std::endl;
	return arg;
} 

template<typename T>
Matrice<T> Matrice<T>::operator-(const Matrice& arg) const {
	if ( this->nbrColonne == arg.nbrColonne && this->nbrLigne == arg.nbrLigne ) {
		Matrice<T> matrice( arg.nbrLigne, arg.nbrColonne );
		for (size_t i = 0 ; i < this->nbrColonne*this->nbrLigne ; ++i) {
			matrice.matrice[i] = this->matrice[i] - arg.matrice[i];
		}
		return matrice;	
	}
	return arg;
}

template class Matrice<short>;
template class Matrice<int>;
template class Matrice<long>;
template class Matrice<float>;
template class Matrice<double>;
