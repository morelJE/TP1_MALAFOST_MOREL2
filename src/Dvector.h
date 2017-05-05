#ifndef DVECTOR_H_
#define DVECTOR_H_
//!
//! \file Dvector.h
//! \brief Classe implémentant des tableaux dynamiques et les opérations allant avec
//! \author morel2-malafost
//!

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

    Dvector(int s,double p = 0);

    Dvector(std::string&);

    void display(std::ostream& str);

    void fillRandomly();

    ~Dvector();

    double& operator ()(const int& i) const;

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

    friend bool operator ==(const Dvector& n, const Dvector& v);

    Dvector resize(int taille, double valeur = 0.);
};

#endif
