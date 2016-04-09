#include "cos.h"


Cos::Cos()
{
    //ctor
}

Cos::Cos(Expression *exp, const string&name):Unaire(exp,"cos("+exp->afficher()+")")
{

}

Cos::~Cos()
{
    //dtor
}

Expression* Cos::clone() const
{
	return new Cos(*this);
}


double Cos::eval() const
{
    return cos(_op->eval());
}
