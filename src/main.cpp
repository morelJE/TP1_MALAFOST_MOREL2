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
    std::cout << "[OK] Op + - * \n\n";

    Dvector t(5,3);
    Dvector x;
    x = u + t;
    assert(x(1)==5);
    x = t - u;
    assert(x(1)==1);
    std::cout << "[OK] Op + - même taille \n\n";
    t.~Dvector();

    Dvector w(4,3);
    x = u + w;
    cout << x(4);
    assert(x(4)==2);
    x = w - u;
    assert(x(4)==-2);
    std::cout << "[OK] Op + - taille diff\n\n";

    x = -u;
    assert(x(1)==-2);
    std::cout << "[OK] Op - unaire\n\n";
    u.~Dvector();

    x+= 3;
    assert(x(1)==1);
    x-= -2;
    assert(x(1)==3);
    std::cout << "[OK] Op += -=\n\n";

    u.~Dvector();
    x.~Dvector();
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
