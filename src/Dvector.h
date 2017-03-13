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

    Dvector(int,double p = 0);

    void display(std::ostream& str);

    void fillRandomly();

    ~Dvector();

    double operator()(int i);

    Dvector operator +(double o);

    Dvector operator *(double o);

    Dvector operator /(double o);

    Dvector operator +(const Dvector n);

    Dvector operator -(const Dvector n);

    Dvector operator -();

    Dvector operator >>(double o);

    Dvector operator <<(double o);

    Dvector operator +=(double o);

    Dvector operator -=(double o);
