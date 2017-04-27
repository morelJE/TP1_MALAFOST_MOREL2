#include "Dvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

Dvector::Dvector() {
    cout << "CREATE EMPTY\n";
    taille = 0;
    pCor = new double[taille];
}

int Dvector::size() {
    return this->taille;
}

Dvector::Dvector(const Dvector & V) {
  cout << "CREATE\n";
    this->taille=V.taille;
    this->pCor = new double[this->taille];
    for (int i=0; i<this->taille; i++) {
      this->pCor[i] = V.pCor[i];
    }
}

Dvector::Dvector(std::string& my_str) {
    cout << "CREATE\n";
    taille = my_str.size();
    pCor = new double[taille];
    for (int i=0; i<taille; i++) {
      pCor[i] = my_str[i];
    }
}


Dvector::Dvector(int s, double p) {
    cout << "CREATE\n";
    this->taille = s;
    pCor = new double [this->taille];
    for (int i=0; i<this->taille; i++) {
      pCor[i] = p;
    }
}

Dvector::~Dvector() {
  cout << "SUPRESS\n";
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

Dvector operator +(const Dvector& n, const Dvector& v)
{
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

Dvector operator -(const Dvector& n, const Dvector& v)
{
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

Dvector Dvector::operator -()
{
  Dvector u(taille);
  for (int i=0; i<taille; i++) {
    u.pCor[i] = -pCor[i];
  }
  return u;
}

Dvector Dvector::operator >>(double o)
{
  for (int i = taille - 1; i >= o; i--) {
    pCor[i] = pCor[i - (int) o];
  }
  for (int i = 0; i < o; i++) {
    pCor[i] = 0;
  }
  return *this;
}

Dvector Dvector::operator <<(double o)
{
  for (int i = 0; i < taille - o; i++) {
      pCor[i] = pCor[i + (int) o];
  }
  for (int i = taille - o; i < taille; i++) {
      pCor[i] = 0;
  }
  return *this;
}

Dvector Dvector::operator +=(double o)
{
  for (int i=0; i<taille; i++) {
    pCor[i] = pCor[i] + o;
  }
  return *this;
}

Dvector Dvector::operator -=(double o)
{
  for (int i=0; i<taille; i++) {
    pCor[i] = pCor[i] - o;
  }
  return *this;
}

Dvector Dvector::operator *=(double o)
{
  for (int i=0; i<taille; i++) {
    pCor[i] = pCor[i] * o;
  }
  return *this;
}

Dvector Dvector::operator /=(double o)
{
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
  if (taille == V.taille) {
    for (int i=0; i<taille; i++) {
      pCor[i] = V.pCor[i];
    }
    return *this;
  }
  else {
    std::cout << "Error : Les vecteurs ne font pas la même taille";
    return *this;
  }
}

/*
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
}*/

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
