#include "superieur.h"

Superieur::Superieur()
{
    //ctor
}

Superieur::~Superieur()
{
    //dtor
}

Superieur::Superieur(Expression *exp1, Expression *exp2):Binaire(exp1,exp2)
{

}

double Superieur::eval()
{
    if(_gauche->eval() >= _droite->eval())
        return 1;
    return 0;
}

string Superieur::afficher() const
{
    return (_gauche->afficher()+_droite->afficher());
}

ostream& operator<<(ostream& os, const Superieur & a)
{
    os << a.afficher();
    return os;
}

