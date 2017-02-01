#include <iostream>
using namespace std;

class Dvector
{
    int size;
    double *pCor;
public:
    Dvector();
    int getSize();
    Dvector(int,double*);
    Dvector(int);
    void display(std::ostream& str);
};
