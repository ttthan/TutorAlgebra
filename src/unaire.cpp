#include "unaire.h"

Unaire::Unaire()
{
    //ctor
}

Unaire::Unaire( Expression *op, const string& name):Expression(name),_op(op)
{
}

Unaire::~Unaire()
{
    //dtor
}

string Unaire::afficher()
{
return Expression::_nom+"("+ _op->afficher() +")";
}

Sin::Sin()
{
    //ctor
}

Sin::Sin(Expression *exp, const string&name):Unaire(exp,"sin("+exp->afficher()+")")
{

}

Sin::~Sin()
{
    //dtor
}

Expression* Sin::clone() const
{
	return new Sin(*this);
}

double Sin::eval() const
{
    return sin(_op->eval());
}

Expression* Sin::deriver(const string& var)
{
    //return new Produit(_op->deriver(var),new Cos(_op));
}

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

Expression *Cos::deriver(const string& var)
{
    //return new Produit(_op->deriver(var),new Sin(_op));
}

Exponentielle::Exponentielle()
{
    //ctor
}

Exponentielle::Exponentielle(Expression *exp, Expression *pow, const string&name):Unaire(exp,"("+exp->afficher()+")^("+pow->afficher()+")"),_exp(exp),_pow(pow)
{

}

Exponentielle::~Exponentielle()
{
    //dtor
}

Expression* Exponentielle::clone() const
{
	return new Exponentielle(*this);
}


double Exponentielle::eval() const
{
    return pow(_exp->eval(),_pow->eval());
}

Expression* Exponentielle::deriver(const string &var)
{

}

string Exponentielle::afficher() const
{
    return ( "("+_exp->afficher()+")^("+_pow->afficher()+")");
}

ostream& operator<<(ostream& os, const Exponentielle & a)
{
    os << a.afficher();
    return os;
}
