#include "somme.h"

Somme::Somme()
{
    //ctor
}

Somme::~Somme()
{
    //dtor
}

Somme::Somme(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,exp1->afficher()+" + "+exp2->afficher())
{

}

double Somme::eval()
{
    return (_gauche->eval()+_droite->eval());
}

string Somme::afficher() const
{
    return (_gauche->afficher()+_droite->afficher());
}

ostream& operator<<(ostream& os, const Somme & a)
{
    os << a.afficher();
    return os;
}

