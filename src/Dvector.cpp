#include "Dvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

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

Dvector::Dvector(int s, double p) {
    taille = s;
    pCor = new double [taille];
    for (int i=0; i<taille; i++) {
      pCor[i] = p;
    }
};


void Dvector::display(std::ostream& str) {
    if (this->taille != 0) {
        for (int i = 0; i < this->taille; i++) {
            str << pCor[i] << "\n";
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


//Dvector::Dvector(std::string) {
//  int compteur = 0;
//  ifstream fichier(std::string);
//  while (flux.eof() == false) {
//      compteur = compteur + 1;
//      double valeur_cour;
//      fichier >> valeur_cour;
//  }
//  Dvector v = Dvector(compteur);
//  for (int i=0; i<compteur; i++) {
//    int valeur_cour_2 = 0;
//    v[i] = fichier >> valeur_cour_2;
//  }
//};
