#include <iostream>
#include "Dvector.h"
using namespace std;

int main()
{

    Dvector d(3);
    cout << d.size();
    cout << "\n";
    double i = 2;
    Dvector e(3,&i);
    e.display(cout);



}
