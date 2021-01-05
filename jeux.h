#ifndef _JEUX_H_
#define _JEUX_H_
#include "Matrice.h"
#include "Ensemble.cpp"

void devineNbr();
void sudoku();
void inserer(Matrice<int>&);
bool ligneEstValide(size_t, Ensemble<int>&, Matrice<int>);
bool colonneEstValide(size_t, Ensemble<int>&, Matrice<int>);

#endif
