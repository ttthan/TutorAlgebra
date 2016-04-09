#include "binaire.h"

Binaire::Binaire()
{
    //ctor
}

Binaire::~Binaire()
{
    delete _gauche;
    delete _droite;
}

Binaire::Binaire(Expression *op1, Expression *op2, const string& name):Expression(name),_gauche(op1), _droite(op2)
{

}


string Binaire::afficher()
{
    return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}

