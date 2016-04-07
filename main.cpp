
#include <iostream>
#include <fstream>
#include "include\expression.h"
#include "constante.h"
#include "cos.h"


using namespace std;


void testConstante()
{
    // c = 5
    Expression * c = new Constante(5);
    cout << "c = "<< *c << endl;
    Expression * cbis = c->clone();
    cout << "clone de c = " << *cbis << endl;
    delete c;
    delete cbis;
}


void testCosinus()
{
    // c = cos(PI/3)
    Cos * c = new Cos(new Constante(M_PI/3.0));
    cout << *c << " = " << c->eval() << endl;
    delete c;
    cout << "destruction automatique des variables locales allouees sur la PILE: ICI AUCUNE " << endl;

}



int main()
{
    //testConstante();
   testCosinus();
    return 0;
}

