#ifndef BINAIRE_H
#define BINAIRE_H
#include "expression.h"

class Binaire : public Expression
{
    public:
        Binaire();
        virtual ~Binaire();
        Binaire(Expression *, Expression *, const string& name="binaire");
        virtual string getString();
    protected:
        Expression *_gauche, *_droite;
    private:
};

#endif // BINAIRE_H
