#include "bloc.h"

Bloc::Bloc()
{
    //ctor
}

Bloc::~Bloc()
{
    //dtor
}

Bloc::Bloc(const string& nom, Expression* exp1) : Expression("bloc"), _nom(nom)
{
    _exp.push_back(exp1->clone());
}


string Bloc::afficher() const
{
    string str = "{\n";
    list<Expression*>::const_iterator it;
	for (it = _exp.begin(); it != _exp.end(); it++)
	{
	    Expression * tmp = *it;
	    str.append("");
	    str.append(tmp->afficher());
	    str.append("\n");
		//str += (*it)->afficher();

	}
	str += "\n}";
	return str;
//    list<Expression *>::const_iterator it = _exp.begin();
//	string str("{\n");
//	while (it != _exp.end())
//	{
//		Expression * tmp = *it;
//		str.append("\t");
//		str.append(tmp->afficher());
//		str.append("\n");
//		it++;
//	}
//	str.append("}");
//	return str;

}

Expression* Bloc::clone() const
{
	return new Bloc(*this);
}


ostream & operator << (ostream & os, const Bloc & bloc)
{
	os << bloc.afficher();
	return os;
}

double Bloc::eval() const
{
    list<Expression*>::const_iterator it;
	double value;
	for (it = _exp.begin(); it != _exp.end(); it++)
	{
		value = (*it)->eval();
	}
	return value;
    Expression * tmp = _exp.back();
	return tmp->eval();
}

void Bloc::add(Expression* expression)
{

	this->_exp.push_back(expression);
}
