#include <iostream>
using namespace std;

class Dvector
{
private:

    double *pCor;

public:

    int taille;

    Dvector();

    int size();

    Dvector(const Dvector & V);

    Dvector(int,double p = 0);

    Dvector(std::string&);

    void display(std::ostream& str);

    void fillRandomly();

    ~Dvector();

    double operator()(int i);

    Dvector operator +(double o);

    Dvector operator -(double o);

    Dvector operator *(double o);

    Dvector operator /(double o);

    friend Dvector operator +(const Dvector& n, const Dvector& v);

    friend Dvector operator -(const Dvector& n, const Dvector& v);

    Dvector operator -();

    Dvector operator >>(double o);

    Dvector operator <<(double o);

    Dvector operator +=(double o);

    Dvector operator -=(double o);

    Dvector operator *=(double o);

    Dvector operator /=(double o);

    Dvector operator =(const Dvector &V);

    //bool operator ==(const Dvector& n, const Dvector& v);

    Dvector resize(const Dvector &V);
};
