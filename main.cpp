
#include <iostream>
#include <fstream>
#include "expression.h"
#include "constante.h"
#include "cos.h"
#include "sin.h"
#include "somme.h"
#include "produit.h"
#include "superieur.h"


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

void testBinaire()
{
    // s = 1 + 2 * sin(PI/6)
    Somme * s = new Somme(new Constante(1.0), new Produit(new Constante(2.0), new Sin(new Constante(M_PI/6.0))));
    cout << "s : " << *s << " = " << s->eval() << endl;

    Expression * sbis = s->clone();
    cout << "clone de s : " << *sbis << " = " << sbis->eval() << endl;

    // s > 1
    Superieur comp(s->clone(), new Constante(1.8));
    cout << comp << " = " << (bool)comp.eval() << endl;

    delete s;
    delete sbis;
    cout << "destruction automatique des variables locales allouees sur la PILE: ICI COMP" << endl;
}

int main()
{
    testConstante();
   testCosinus();
   testBinaire();
    return 0;
}

