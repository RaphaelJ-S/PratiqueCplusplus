compOpt=g++ -Wall -Werror -std=c++17

main: jeux.o Matrice.o Ensemble.o
	$(compOpt) -o main.exe jeux.o Ensemble.o Matrice.o main.cpp 

Matrice.o: Matrice.cpp Matrice.h
	$(compOpt) -c Matrice.cpp

Ensemble.o: Ensemble.cpp 
	$(compOpt) -c Ensemble.cpp

jeux.o: jeux.cpp jeux.h
	$(compOpt) -c jeux.cpp 

clean:
	rm -fo ./main.exe 

.PHONY: clean

