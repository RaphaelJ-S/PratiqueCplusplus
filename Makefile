compOpt=g++ -Wall -Werror -std=c++11


main: jeux.o Matrice.o Ensemble.o
	$(compOpt) -o main jeux.o Ensemble.o Matrice.o main.cpp 

Matrice.o: Matrice.cpp Matrice.h
	$(compOpt) -c Matrice.cpp

Ensemble.o: Ensemble.cpp 
	$(compOpt) -c Ensemble.cpp

jeux.o: jeux.cpp jeux.h
	$(compOpt) -c jeux.cpp 

clean:
	rm main *.o

.PHONY: clean

