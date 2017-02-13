#include <iostream>
using namespace std;

class Dvector
{

    double *pCor;

  public:

    int taille;

    Dvector();

    int size();

    Dvector(const Dvector & V);

    Dvector(int,double *p = new double(0));

    void display(std::ostream& str);

    void fillRandomly();

    ~Dvector();

    double operator()(int i);

    int operator(+)(int a, int b);
};
