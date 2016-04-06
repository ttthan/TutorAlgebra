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

string Unaire::getString()
{
return Expression::_nom+"("+ _op->getString() +")";
}
