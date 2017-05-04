#include "Dvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

Dvector::Dvector() {
    taille = 0;
    pCor = new double[taille];
}

int Dvector::size() {
    return this->taille;
}

Dvector::Dvector(const Dvector & V) {
    this->taille=V.taille;
    this->pCor = new double[this->taille];
    for (int i=0; i<this->taille; i++) {
      this->pCor[i] = V.pCor[i];
    }
}

Dvector::Dvector(std::string& my_str) {
    taille = my_str.size();
    pCor = new double[taille];
    for (int i=0; i<taille; i++) {
      pCor[i] = my_str[i];
    }
}


Dvector::Dvector(int s, double p) {
    this->taille = s;
    pCor = new double [this->taille];
    for (int i=0; i<this->taille; i++) {
      pCor[i] = p;
    }
}

Dvector::~Dvector() {
  delete [] this->pCor;
}


void Dvector::display(std::ostream& str) {
    if (this->taille != 0) {
        for (int i = 0; i < this->taille; i++) {
            str << pCor[i] << "\n";
        }
    }
}

void Dvector::fillRandomly() {
    float nombre_aleatoire = 0.0;
    srand(time(NULL));
  	for(int i=0; i<taille; i++){
  		nombre_aleatoire = rand() / ((double) RAND_MAX);
  		pCor[i] = nombre_aleatoire;
  	}
}

double& Dvector::operator ()(const int& i) const {
  try  {
    if (i < 1 || i > this->taille + 1) {
      throw string("Cette case du vecteur n'existe pas");
    }
    else {
      return this->pCor[i - 1];
    }
  }
  catch(string const& chaine) {
    cerr << chaine << endl;
  }
  exit(EXIT_FAILURE);
}

Dvector Dvector::operator +(double o) {
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i] + o;
  }
  return v;
}

Dvector Dvector::operator -(double o) {
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i] - o;
  }
  return v;
}

Dvector Dvector::operator *(double o) {
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i]*o;
  }
  return v;
}

Dvector Dvector::operator /(double o) {
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i]/o;
  }
  return v;
}

Dvector operator +(const Dvector& n, const Dvector& v) {
  Dvector u(std::max(v.taille,n.taille));
  if (v.taille > n.taille) {
    for (int i = 0; i < n.taille; i++) {
      u.pCor[i] = v.pCor[i] + n.pCor[i];
    }
    for (int j = n.taille; j < v.taille; j++) {
      u.pCor[j] = v.pCor[j];
    }
  } else {
    for (int i = 0; i < v.taille; i++) {
      u.pCor[i] = v.pCor[i] + n.pCor[i];
    }
    for (int j = v.taille; j < n.taille; j++) {
      u.pCor[j] = n.pCor[j];
    }
  }
  return u;
}

Dvector operator -(const Dvector& n, const Dvector& v) {
  Dvector u(std::max(v.taille,n.taille));
  if (v.taille > n.taille) {
    for (int i = 0; i < n.taille; i++) {
      u.pCor[i] = n.pCor[i] - v.pCor[i];
    }
    for (int j = n.taille; j < v.taille; j++) {
      u.pCor[j] = - v.pCor[j];
    }
  } else {
    for (int i = 0; i < v.taille; i++) {
      u.pCor[i] = n.pCor[i] - v.pCor[i];
    }
    for (int j = v.taille; j < n.taille; j++) {
      u.pCor[j] = n.pCor[j];
    }
  }
  return u;
}

Dvector Dvector::operator -() {
  Dvector u(taille);
  for (int i=0; i<taille; i++) {
    u.pCor[i] = -pCor[i];
  }
  return u;
}

Dvector Dvector::operator >>(double o) {
  for (int i = taille - 1; i >= o; i--) {
    pCor[i] = pCor[i - (int) o];
  }
  for (int i = 0; i < o; i++) {
    pCor[i] = 0;
  }
  return *this;
}

Dvector Dvector::operator <<(double o) {
  for (int i = 0; i < taille - o; i++) {
      pCor[i] = pCor[i + (int) o];
  }
  for (int i = taille - o; i < taille; i++) {
      pCor[i] = 0;
  }
  return *this;
}

Dvector Dvector::operator +=(double o) {
  for (int i=0; i<taille; i++) {
    pCor[i] = pCor[i] + o;
  }
  return *this;
}

Dvector Dvector::operator -=(double o) {
  for (int i=0; i<taille; i++) {
    pCor[i] = pCor[i] - o;
  }
  return *this;
}

Dvector Dvector::operator *=(double o) {
  for (int i=0; i<taille; i++) {
    pCor[i] = pCor[i] * o;
  }
  return *this;
}

Dvector Dvector::operator /=(double o) {
    try {
        if (o == 0) {
            throw string("Division par zéro ! le vecteur reste inchangé\n");
        } else {
            for (int i=0; i<taille; i++) {
              pCor[i] = pCor[i] / o;
            }
            return *this;
        }
    }
    catch (string const& chaine) {
        cerr << chaine;
    }
    return *this;
}

Dvector Dvector::operator =(const Dvector& V) {
    int i = 0;
    while (i<taille) {
        pCor[i] = V.pCor[i];
        i++;
    }
    return *this;
}

Dvector Dvector::resize(int taille, double valeur) {
    double* nouv = new double[taille];
    for (int i = 0; i < this->taille; i++) {
        nouv[i] = this->pCor[i];
    }

    delete [] this->pCor;
    this->pCor = nouv;

    if (taille > this->taille) {
        for (int i = this->taille; i < taille; i++) {
            this->pCor[i] = valeur;
        }
    }
    this->taille = taille;
    return *this;
}


bool operator ==(const Dvector& n, const Dvector& v) {
    if (n.taille != v.taille) {
        return false;
    }
    for (int i = 0; i < n.taille; i++) {
        if (n.pCor[i] != v.pCor[i]) {
            return false;
        }
    }
    return true;
}

//    taille=V.taille;
//    Dvector u(taille);
//    pCor = new double[taille];
//    for (int i=0; i<taille; i++) {
//      u.pCor[i] = V.pCor[i];
//    }
//    return u;


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
