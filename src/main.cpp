#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "Dvector.h"
//using namespace std;

int main()
{


    Dvector x = Dvector(3,1.);
    Dvector y;
    y = Dvector(3);

    x.display(cout);
    cout << "\n";
    y.display(cout);

    x.~Dvector();
    y.display(cout);
    //y.~Dvector();

    //x.display(cout);
    //y.display(cout);


/*
    std::cout << "##################################\n";
    std::cout << "###############    ###############\n";
    std::cout << "###########    TEST    ###########\n";
    std::cout << "###############    ###############\n";
    std::cout << "##################################\n\n";

    std::stringstream str;

    Dvector v(3,2.5);
    assert( v.size() == 3 );
    std::cout << "[OK] size / constructeur\n";


    v.display( str );
    assert( str.str() == "2.5\n2.5\n2.5\n" );
    std::cout << "[OK] display\n\n";

    v.fillRandomly();
    std::cout << "-----fill randomly-----\n";
    v.display(cout);
    std::cout << "\n";

    v.~Dvector();
*/
    /*Dvector u(5,1.);
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
    std::cout << "[OK] Op + - * \n\n";*/

    //Dvector x;
    //Dvector t(5,3);
/*
    x = u + t;

    assert(x(1)==5);
    x = t - u;
    assert(x(1)==1);
    std::cout << "[OK] Op + - même taille \n\n";
    //t.~Dvector();

    Dvector w(4,3);
    x = u + w;
    assert(x(4)==2);
    x = w - u;
    assert(x(4)==-2);
    std::cout << "[OK] Op + - taille diff\n\n";

    x = -u;
    assert(x(1)==-2);
    std::cout << "[OK] Op - unaire\n\n";

    x += 3;
    assert(x(1)==1);
    x -= -2;
    assert(x(3)==3);
    x *= 2;
    assert(x(2)==6);
    x /= 3;
    assert(x(4)==2);
    std::cout << "[OK] Op += -= *= /=\n";*/

    /*x /= 0;
    cout << endl;

    u.~Dvector();
    x.~Dvector();

    Dvector m(4,2);
    m << 1;
    str.str(std::string());
    m.display(str);
    assert(str.str() == "2\n2\n2\n0\n");
    m >> 2;
    str.str(std::string());
    m.display(str);
    assert(str.str() == "0\n0\n2\n2\n");
    std::cout << "[OK] << et >>\n\n";

    m.~Dvector();*/


/*
    std::cout <<"QUESTION 1-1\n";
    Dvector a;
    a = Dvector(3,1.);
    a.display(cout);
    Dvector b = Dvector(3,1.);
    b.display(cout);*/

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
