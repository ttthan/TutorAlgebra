#include "ifThenElse.h"

IfThenElse::IfThenElse()
{
    //ctor
}

IfThenElse::~IfThenElse()
{
    //dtor
}

IfThenElse::IfThenElse(Binaire* cond, Expression* exp1, Expression* exp2) : Expression("if"), _cond(cond), _exp1(exp1), _exp2(exp2)
{

}


string IfThenElse::afficher() const
{
   // ostringstream os;

	return "if (" + _cond->afficher() + ") { \n  " + _exp1->afficher() + "\n }else{\n" + _exp2->afficher() + "\n}";
	//return os.str();


}

Expression* IfThenElse::clone() const
{
	return new IfThenElse(*this);
}

Expression* IfThenElse::deriver(const string &var)
{

}

ostream & operator << (ostream & os, const IfThenElse & conditionnel)
{
	os << conditionnel.afficher();
	return os;
}

double IfThenElse::eval() const
{
    if (_cond->eval())

        return _exp1->eval();
    else
        return _exp2->eval();
   // return (((bool)_cond->eval()) ? _exp1->eval() : _exp2->eval());
}
