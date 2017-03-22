#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "Dvector.h"
//using namespace std;

int main()
{

    std::cout << "##################################\n";
    std::cout << "###############    ###############\n";
    std::cout << "###########    TEST    ###########\n";
    std::cout << "###############    ###############\n";
    std::cout << "##################################\n\n";

    Dvector v(3,2.5);
    assert( v.size() == 3 );
    std::cout << "[OK] size / constructeur\n";

    std::stringstream str;
    v.display( str );
    assert( str.str() == "2.5\n2.5\n2.5\n" );
    std::cout << "[OK] display\n\n";

    v.fillRandomly();
    std::cout << "-----fill randomly-----\n";
    v.display(cout);
    std::cout << "\n";

    v.~Dvector();

    Dvector u(5,1);
    assert(u(1)==1);
    std::cout << "[OK] Op ()\n\n";


    u = u + 2;
    assert(u(3)==3);
    u = u - 2;
    assert(u(1)==1);
    u = u * 4;
    assert(u(1)==4);
    u = u / 2;
    assert(u(2)==2);
    std::cout << "[OK] Op + - * /\n\n";



/*
    Dvector x;
    x = Dvector (3, 1.);
    x.display(cout);
    std::cout << "\n";
    Dvector y = Dvector (3, 1.);
    y.display(cout);
    x.~Dvector();
    y.~Dvector();*/

}
