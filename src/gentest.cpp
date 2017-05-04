#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "GenerateurParkMiller.h"
using namespace std;
int main()
{

  GenerateurParkMiller GenP(8);
  Dvector x = GenP.genRand();
  x.display(cout);

/*
  ParkMiller p;
  double d;
  for (int i = 0; i < 3; i++) {
    d = p.genRandom();
    cout << d << "\n";
  }
  cout << "\n";*/

}
