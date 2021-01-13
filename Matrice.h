#ifndef MATRICE_H
#define MATRICE_H

#include <cstddef>

template <class T>
class Matrice{

	T* matrice;
	size_t nbrLigne;
	size_t nbrColonne;	
	
	public:
		Matrice();
		Matrice(size_t , size_t); 
		~Matrice();
		T getCell(size_t, size_t);
		size_t getNbrLigne(); 
		size_t getNbrColonne();		
		T* getMatrice();
		void setCell(T, size_t, size_t);
		void show();
		Matrice operator+(const Matrice&) const;
		Matrice operator-(const Matrice&) const;

};

#endif
