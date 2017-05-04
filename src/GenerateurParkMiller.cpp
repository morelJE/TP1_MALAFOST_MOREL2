#include "GenerateurParkMiller.h"

GenerateurParkMiller::GenerateurParkMiller() {
  dim = 1;
  this->P = ParkMiller();
}

GenerateurParkMiller::GenerateurParkMiller(int dim) {
  this->dim = dim;
  this->P = ParkMiller();
}

GenerateurParkMiller::GenerateurParkMiller(const GenerateurParkMiller &Gen) {
  this->P = Gen.P;
  this->dim = Gen.dim;
}

GenerateurParkMiller* GenerateurParkMiller::Clone() {
  return this;
}

GenerateurParkMiller::~GenerateurParkMiller() {
  this->P.~ParkMiller();
}

GenerateurParkMiller GenerateurParkMiller::operator =(const GenerateurParkMiller &Gen) {
  this->P = Gen.P;
  this->dim = Gen.dim;
  return *this;
}

void GenerateurParkMiller::set_seed(int seed) {
  this->P.setSeed(seed);
}

int GenerateurParkMiller::get_seed() {
  return this->P.getSeed();
}

void GenerateurParkMiller::reset_seed() {
  this->P = ParkMiller();
}

Dvector GenerateurParkMiller::genRand() {
  Dvector v(this->dim);
  for (int i = 1; i < this->dim + 1; i++) {
    v(i) = P.genRandom();
  }
  return v;
}
