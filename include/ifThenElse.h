#ifndef IFTHENELSE_H
#define IFTHENELSE_H
#include "expression.h"
#include "binaire.h"

class IfThenElse : public Expression
{
    public:
        IfThenElse();
        virtual ~IfThenElse();
        IfThenElse(Binaire*, Expression*, Expression*);
        Expression *clone() const;
        string afficher() const;
        friend ostream & operator << (ostream & os, const IfThenElse &);
        double eval() const;
    private:
        Binaire *_cond;
        Expression *_exp1, *_exp2;
    protected:
};

#endif // IFTHENELSE_H
