#include "conditionnel.h"

Conditionnel::Conditionnel()
{
    //ctor
}

Conditionnel::~Conditionnel()
{
    //dtor
}

Conditionnel::Conditionnel(Binaire* cond, Expression* exp1, Expression* exp2) : Expression("?"), _cond(cond), _exp1(exp1), _exp2(exp2)
{

}

string Conditionnel::afficher() const
{
    ostringstream os;
	os << _cond->afficher() << " ? " << _exp1->afficher() << " : " << _exp2->afficher();
	return os.str();


}

ostream & operator << (ostream & os, const Conditionnel & conditionnel)
{
	os << conditionnel.afficher();
	return os;
}

double Conditionnel::eval() const
{
    return (((bool)_cond->eval()) ? _exp1->eval() : _exp2->eval());
}
