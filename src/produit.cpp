#include "produit.h"

Produit::Produit()
{
    //ctor
}

Produit::~Produit()
{
    //dtor
}

//Produit::Produit(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"(" + exp1->afficher() + " * " + exp2->afficher() + ")")
//{
//
//}

Produit::Produit(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"*")
{

}

double Produit::eval() const
{
    //cout << _gauche->afficher()+"\n";
    //cout << _droite->afficher();
    return (_gauche->eval()*_droite->eval());
}

Expression* Produit::clone() const
{
	return new Produit(*this);
}

string Produit::afficher() const
{
     return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}

ostream& operator<<(ostream& os, const Produit & a)
{
    os << a.afficher();
    return os;
}

