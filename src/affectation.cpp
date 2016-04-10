#include "affectation.h"


Affectation::Affectation()
{
    //ctor
}

Affectation::~Affectation()
{
    //dtor
}

Expression* Affectation::clone() const
{
	return new Affectation(*this);
}

Affectation::Affectation(Variable* variable, Expression* expression): Binaire(variable,expression,"<-"), _variable(variable),_expression(expression)
{
    //_variable->set(_expression->eval());
}

double Affectation::eval() const
{

    _variable->set(_expression->eval());
    return _variable->eval();
    //return ((Variable*)_gauche)->set(_droite->eval());
}

Expression* Affectation::deriver(const string &var)
{

}

Expression *Affectation::simplifier()
{

}

string Affectation::afficher() const
{
    ostringstream os;
	os << '(' <<  *_variable << " <- " << _expression->afficher() << ')';
	return os.str();
}

ostream & operator << (ostream & os, const Affectation & affectation)
{
	os << affectation.afficher();
	return os;
}
