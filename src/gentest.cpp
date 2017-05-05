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


  double d;
  for (int i = 0; i < 8; i++) {
    d = GenP.genRand();
    cout << d << "   ";
  }
  cout << "\n";
  GenP.set_seed(int(d));
  for (int i = 0; i < 8; i++) {
    d = GenP.genRand();
    cout << d << "   ";
  }
  cout << "\n";

}
