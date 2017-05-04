#include "GenerateurNombreAleatoire.h"
#include "ParkMiller.h"

class GenerateurParkMiller: public GenerateurNombreAleatoire
{

private:
  int dim;
  ParkMiller P;

public:

  GenerateurParkMiller();

  GenerateurParkMiller(int dim);

  GenerateurParkMiller(const GenerateurParkMiller &Gen);

  GenerateurParkMiller* Clone();

  ~GenerateurParkMiller();

  GenerateurParkMiller operator =(const GenerateurParkMiller &Gen);

  int getDim() {
    return this->dim;
  }

  void set_seed(int seed);

  int get_seed();

  void reset_seed();

  Dvector genRand();

};
