#include "expression.h"
#include "constante.h"

#include <fonction.h>
#include <math.h>

Constante::Constante()
{
    //ctor
}

Constante::Constante(const double val) : Expression(string_from_double(val)), _value(val)
{

}

Constante::~Constante()
{
    //dtor
}

double Constante::eval() const
{
    return _value;
}

Expression* Constante::clone() const
{
    return new Constante(*this);
}

ostream& operator<<(ostream& os, const Constante & a)
{
//    os << "cde";
    return os;
}

