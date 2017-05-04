#include "GenerateurNombreAleatoire.h"

GenerateurNombreAleatoire::GenerateurNombreAleatoire() {

}

GenerateurNombreAleatoire::GenerateurNombreAleatoire(int dim) {
  this->dim = dim;
}

GenerateurNombreAleatoire::GenerateurNombreAleatoire(const GenerateurNombreAleatoire &Gen) {

}

GenerateurNombreAleatoire::~GenerateurNombreAleatoire() {

}

GenerateurNombreAleatoire GenerateurNombreAleatoire::operator =(const GenerateurNombreAleatoire &Gen) {
  return *this;
}


void GenerateurNombreAleatoire::set_seed() {

}

int GenerateurNombreAleatoire::get_seed() {
  return 0;
}

void GenerateurNombreAleatoire::reset_seed() {

}

Dvector GenerateurNombreAleatoire::genUniforme() {
  Dvector v(this->dim);
  return v;
}
