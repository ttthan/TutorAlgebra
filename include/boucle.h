#ifndef BOUCLE_H
#define BOUCLE_H
#include "expression.h"

class Pour : public Expression
{
    public:
        Pour();
        virtual ~Pour();
        Pour(Expression *init, Expression *cond, Expression *inc, Expression *calc);
        Expression *clone() const;
        string afficher() const;
        friend ostream & operator << (ostream & os, const Pour &);
        double eval() const;
        Expression *deriver(const string &);
    protected:
    private:
        Expression *_init, *_cond, *_incr, *_calcul;
};

#endif // BOUCLE_H
