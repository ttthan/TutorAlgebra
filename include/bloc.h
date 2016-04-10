#ifndef BLOC_H
#define BLOC_H
#include <list>
#include "expression.h"
#include "binaire.h"

class Bloc : public Expression
{
    public:
        Bloc();
        virtual ~Bloc();
        Bloc(const string &, Expression*);
        Expression *clone() const;
        string afficher() const;
        friend ostream & operator << (ostream & os, const Bloc &);
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        void add(Expression*);
    private:
        list<Expression*> _exp;
        const string _nom;
    protected:
};

#endif // IFTHENELSE_H
