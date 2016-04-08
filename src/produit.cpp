#include "produit.h"

Produit::Produit()
{
    //ctor
}

Produit::~Produit()
{
    //dtor
}

Produit::Produit(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,exp1->afficher()+" * "+exp2->afficher())
{

}

double Produit::eval()
{
    return (_gauche->eval()*_droite->eval());
}

