#ifndef AFFECTATION_H
#define AFFECTATION_H
#include "binaire.h"
#include "variable.h"

class Affectation : public Binaire
{
    public:
        Affectation();
        Affectation(Variable*, Expression*);
        double eval() const;
        virtual ~Affectation();
        Expression* clone() const;
        string afficher() const;
        friend ostream & operator << (ostream & os, const Affectation & affectation);
    protected:
    private:
        Expression *_expression;
        Variable *_variable;
};

#endif // AFFECTATION_H
