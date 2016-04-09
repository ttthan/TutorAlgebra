
#include <iostream>
#include <fstream>
#include "expression.h"
#include "constante.h"
#include "cos.h"
#include "sin.h"
#include "somme.h"
#include "produit.h"
#include "superieur.h"
#include "variable.h"
#include "affectation.h"


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

void testVariable1()
{
    // x = 3
    Variable x("x", 3.0);
    // y = 0
    Variable y("y");
    cout << x << " = " << x.eval() << endl;
    cout << y << " = " << y.eval() << endl;

    // exp = 1 + 2 * x
    Expression * exp = new Somme(new Constante(1.0), new Produit(new Constante(2.0), &x));
    // a = (y <- exp)
    Affectation * a = new Affectation(new Variable("y"), exp->clone());
    cout << *a << " = " << a->eval() << endl;
    cout << y << " = " << y.eval() << endl;

    Variable::effacerMemoire();
    delete exp; // OK car il existe un clone
    delete a;
    cout << "destruction automatique des variables locales allouees sur la PILE: ICI X et Y" << endl;
}

void testVariable2()
{
    // x = PI/3
    Variable * x = new Variable("x", M_PI/3.0);
    cout << *x << " = " << x->eval() << endl;
    // x = x + (-10)
    x->set( x->eval() + -10);
    cout << *x << " = " << x->eval() << endl;

    Variable::effacerMemoire();
}

int main()
{
    //testConstante();
    //testCosinus();
    //testBinaire();
    //testVariable1();
    testVariable2();
    return 0;
}

