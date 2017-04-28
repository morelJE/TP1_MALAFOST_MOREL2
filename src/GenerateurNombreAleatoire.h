class GenerateurNombreAleatoire
{

private:
  int dim;


public:

  GenerateurNombreAleatoire();

  GenerateurNombreAleatoire(int);

  GenerateurNombreAleatoire(const GenerateurNombreAleatoire &Gen);

  virtual GenerateurNombreAleatoire* Clone();

  virtual ~GenerateurNombreAleatoire();

  GenerateurNombreAleatoire operator =(const GenerateurNombreAleatoire &Gen);

  int getDim() {
    return this->dim;
  }

  void set_seed();

  void get_seed();

  void reset_seed();
};
