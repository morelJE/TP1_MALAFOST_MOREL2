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
}

int Dvector::size() {
    return this->taille;
}

Dvector::Dvector(const Dvector & V) {
    taille=V.taille;
    pCor = new double[taille];
    for (int i=0; i<taille; i++) {
      pCor[i] = V.pCor[i];
    }
}

Dvector::Dvector(int s, double p) {
    taille = s;
    pCor = new double [taille];
    for (int i=0; i<taille; i++) {
      pCor[i] = p;
    }
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

double Dvector::operator ()(int i)
{
  try  {
    if (i < 0 || i > this->size()) {
      throw string("Cette case du vecteur n'existe pas");
    }
    else {
      return(pCor[i]);
    }
  }
  catch(string const& chaine) {
    cerr << chaine << endl;
  }
  return(0);
}

Dvector Dvector::operator +(double o)
{
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i] + o;
  }
  return v;
}

Dvector Dvector::operator -(double o)
{
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i] - o;
  }
  return v;
}

Dvector Dvector::operator *(double o)
{
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i]*o;
  }
  return v;
}

Dvector Dvector::operator /(double o)
{
  Dvector v(taille);
  for (int i=0; i<taille; i++) {
    v.pCor[i] = pCor[i]/o;
  }
  return v;
}

Dvector operator +(const Dvector n, const Dvector v)
{
  if (v.taille > n.taille) {
    for (int i = 0; i < n.taille; i++) {
      v.pCor[i] = v.pCor[i] + n.pCor[i];
    }
    return v;
  } else {
    for (int i = 0; i < v.taille; i++) {
      v.pCor[i] = v.pCor[i] + n.pCor[i];
    }
    return n;
  }

}

Dvector operator -(const Dvector n, const Dvector v)
{
  if (v.taille > n.taille) {
    for (int i = 0; i < n.taille; i++) {
      v.pCor[i] = n.pCor[i] - v.pCor[i];
    }
    for (int j = n.taille; j < v.taille; j++) {
      v.pCor[j] = - v.pCor[j];
    }
    return v;
  } else {
    for (int i = 0; i < v.taille; i++) {
      n.pCor[i] = n.pCor[i] - v.pCor[i];
    }
    return n;
  }
}

Dvector Dvector::operator -()
{
  for (int i=0; i<taille; i++) {
    pCor[i] = -pCor[i];
  }
  return *this;
}

Dvector Dvector::operator >>(double o)
{
  Dvector v(taille);
  for (int i=0; i<(taille-o); i++) {
    v.pCor[taille-i-1] = v.pCor[taille-i-1-(int)o];
  }
  for (int i=0; i<o; i++) {
    v.pCor[i] = 0;
  }
  return v;
}

Dvector Dvector::operator <<(double o)
{
  Dvector v(taille);
  for (int i=0; i<(taille-o); i++) {
    v.pCor[i] = v.pCor[i+(int)o];
  }
  for (int i=0; i<o; i++) {
    v.pCor[taille-i-1] = 0;
  }
  return v;
}

Dvector Dvector::operator +=(double o)
{
  for (int i=0; i<taille-o; i++) {
    pCor[i] = pCor[i] + o;
  }
  return *this;
}

Dvector Dvector::operator -=(double o)
{
  for (int i=0; i<taille-o; i++) {
    pCor[i] = pCor[i] - o;
  }
  return *this;
}
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
