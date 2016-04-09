#include "somme.h"

Somme::Somme()
{
    //ctor
}

Somme::~Somme()
{
    //dtor
}

//Somme::Somme(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"(" + exp1->afficher() + " + " + exp2->afficher() + ")")
//{
//
//}

Somme::Somme(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"+")
{

}

double Somme::eval() const
{
    //cout << _gauche->afficher()+"\n";
    //cout << _droite->afficher();
    return (_gauche->eval()+_droite->eval());
}

string Somme::afficher() const
{
     return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}


Expression *Somme::clone() const
{
	return new Somme(*this);
}

ostream& operator<<(ostream& os, const Somme & a)
{
    os << a.afficher();
    return os;
}

