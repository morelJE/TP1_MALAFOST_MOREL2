#include "Dvector.h"
class GenerateurNombreAleatoire
{

private:
  int dim;


public:

  GenerateurNombreAleatoire();

  GenerateurNombreAleatoire(int dim);

  GenerateurNombreAleatoire(const GenerateurNombreAleatoire &Gen);

  GenerateurNombreAleatoire* Clone();

  ~GenerateurNombreAleatoire();

  GenerateurNombreAleatoire operator =(const GenerateurNombreAleatoire &Gen);

  int getDim() {
    return this->dim;
  }

  void set_seed();

  int get_seed();

  void reset_seed();

  Dvector genUniforme();

};
