#include "variable.h"
map<string, double> Variable::_variables;
Variable::Variable()
{
    //ctor
}

Variable::Variable(const string& id, double valeur) : Expression(id),_id(id)
{
    _variables[_id] = valeur;
}

Variable::Variable(const string& id):Expression(id), _id(id)
{
    _variables[_id] = 0;
}

Variable::~Variable()
{
    //dtor
}

Expression* Variable::clone() const
{
	return new Variable(*this);
}

double Variable::eval() const
{
    return _variables[_id];
}

string Variable::afficher() const
{
	return _id;
}

double Variable::set(double valeur)
{
    _variables[_id] = valeur;
    return valeur;
}

ostream & operator << (ostream & os, const Variable & variable)
{
	os << variable.afficher();
	return os;
}


void Variable::effacerMemoire()
{
	_variables.clear();
}
