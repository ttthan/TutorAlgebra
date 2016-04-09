#ifndef PRODUIT_H
#define PRODUIT_H
#include "binaire.h"

class Produit : public Binaire
{
    public:
        Produit();
        virtual ~Produit();
        double eval() const;
        Expression* clone() const;
        string afficher() const;
        Produit(Expression *, Expression *, const string& name="*");
        friend ostream& operator<<(ostream&, const Produit &);

    protected:
    private:
};

#endif // SOMME_H
