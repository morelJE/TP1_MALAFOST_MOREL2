#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "Dvector.h"
//using namespace std;

int main()
{


    Dvector v(3,2.5);
    assert( v.size() == 3 );
    std::stringstream str;
    v.display( str );
    assert( str.str() == "2.5\n2.5\n2.5\n" );
    std::cout << "OK\n";



    Dvector x;
    x = Dvector (3, 1.);
    x.display(cout);
    std::cout << "\n";
    Dvector y = Dvector (3, 1.);
    y.display(cout);



}
