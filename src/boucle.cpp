#include "boucle.h"

Pour::Pour()
{
    //ctor
}

Pour::~Pour()
{
    //dtor
}

Pour::Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc) :
        Expression("for"), _init(init), _condition(cond), _incremente(inc), _calcul(calc)
{

}

Expression* Pour::clone() const
{
	return new Pour(*this);
}

string Pour::afficher() const
{
    return _nom + " (" + _init->afficher() + " ; " + _condition->afficher() + " ; "
    + _incremente->afficher() + ") { " + _calcul->afficher() + " }";
}

ostream & operator << (ostream & os, const Pour & pour)
{
	os << pour.afficher();
	return os;
}

double Pour::eval() const {
    double res = 0.0; // = 0.0 rajouté
    _init->eval();
    while (_condition->eval()) {
            //cout<<res<<endl;
        res = _calcul->eval();
        _incremente->eval();
    }
    return res;
}
