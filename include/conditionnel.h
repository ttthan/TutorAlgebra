#ifndef CONDITIONNEL_H
#define CONDITIONNEL_H
#include "expression.h"
#include "binaire.h"

class Conditionnel : public Expression
{
    public:
        Conditionnel();
        Conditionnel(Binaire*, Expression*, Expression*);
        virtual ~Conditionnel();
        Expression *clone() const;
        string afficher() const;
        friend ostream & operator << (ostream & os, const Conditionnel &);
        double eval() const;
    private:
        Binaire *_cond;
        Expression *_exp1, *_exp2;
};

#endif // CONDITIONNEL_H
