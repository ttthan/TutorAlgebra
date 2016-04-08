#ifndef UNAIRE_H
#define UNAIRE_H
#include "expression.h"

class Unaire : public Expression
{
    public:
        Unaire();
        Unaire(Expression *, const string& name="unaire");
        virtual ~Unaire();
        virtual string afficher();
    protected:
        Expression *_op;
    private:
};

#endif // UNAIRE_H
