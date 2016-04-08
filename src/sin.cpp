#include "sin.h"


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

double Sin::eval() const
{
    return sin(_op->eval());
}
