#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "ParkMiller.h"

ParkMiller::ParkMiller() {
  this->seed = 12345678;
}

ParkMiller::ParkMiller(const ParkMiller& P) {
  this->seed = P.seed;
}

ParkMiller::~ParkMiller() {
}

ParkMiller ParkMiller::operator =(const ParkMiller& P) {
  this->seed = P.seed;
  return *this;
}

double ParkMiller::genRandom() {
  const int m = 2147483647;
  const int a = 16807;
  const int q = 127773;
  const int r = 2836;

  double hi = this->seed / q;
  double lo = this->seed - q * hi;
  double t = a * lo - r * hi;
  if (t > 0) {
      this->seed = t;
  } else {
      this->seed = t + m;
  }
  return this->seed;
}
