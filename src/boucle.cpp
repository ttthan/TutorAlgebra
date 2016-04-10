#include "boucle.h"

Pour::Pour()
{
    //ctor
}

Pour::~Pour()
{
    //dtor
}

Pour::Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc) : Expression("for"), _init(init), _cond(cond), _incr(inc), _calcul(calc)
{

}

Expression* Pour::clone() const
{
	return new Pour(*this);
}

Expression* Pour::deriver(const string &var)
{

}

string Pour::afficher() const
{
    return _nom + " (" + _init->afficher() + " ; " + _cond->afficher() + " ; "    + _incr->afficher() + ") { " + _calcul->afficher() + " }";
}

ostream & operator << (ostream & os, const Pour & pour)
{
	os << pour.afficher();
	return os;
}

double Pour::eval() const {
    double res = 0.0;
    _init->eval();
    while (_cond->eval())
        {
        res = _calcul->eval();
        _incr->eval();
        }
    return res;
}
