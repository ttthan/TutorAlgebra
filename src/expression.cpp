#include "expression.h"

Expression::Expression()
{
    //ctor
}

Expression::Expression(const string& nom) : _nom(nom) {

}

Expression::~Expression()
{
    //dtor
}

string Expression::getString() const
{
    return _nom;
}

Expression* Expression::clone() const
{

}

double Expression::eval() const
{

}

ostream& operator<<(ostream& os, const Expression & a)
{
    os << a.getString();
    return os;
}

