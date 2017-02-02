#include "Dvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Dvector::Dvector() {
    taille = 0;
    pCor = new double[taille];
    pCor[0]=0.0;
};

int Dvector::size() {
    return this->taille;
};

Dvector::Dvector(const Dvector & V) {
    taille=V.taille;
    pCor = new double[taille];
    for (int i=0; i<taille; i++) {
      pCor[i] = V.pCor[i];
    }
};

Dvector::Dvector(int s, double *p) {
    taille = s;
    pCor = new double [taille];
    for (int i=0; i<taille; i++) {
      pCor[i]=*p;
    }
};


void Dvector::display(std::ostream& str) {
    if (this->taille != 0) {
        for (int i = 0; i < this->taille; i++) {
            std::cout << pCor[i] << "\n";
        }
    }
}

Dvector::~Dvector() {
  delete [] pCor;
}

void Dvector::fillRandomly() {
    float nombre_aleatoire = 0.0;
  	for(int i=0; i<taille; i++){
  		nombre_aleatoire = rand()/RAND_MAX;
  		pCor[i] = nombre_aleatoire;
  	}
};
