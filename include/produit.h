#ifndef PRODUIT_H
#define PRODUIT_H
#include "binaire.h"

class Produit : public Binaire
{
    public:
        Produit();
        virtual ~Produit();
        virtual double eval();
        Produit(Expression *, Expression *, const string& name="+");

    protected:
    private:
};

#endif // SOMME_H
