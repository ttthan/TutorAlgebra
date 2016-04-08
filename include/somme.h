#ifndef SOMME_H
#define SOMME_H
#include "binaire.h"

class Somme : public Binaire
{
    public:
        Somme();
        virtual ~Somme();
        virtual double eval();
        string afficher() const;
        Somme(Expression *, Expression *, const string& name="+");
        friend ostream& operator<<(ostream&, const Expression &);

    protected:
    private:
};

#endif // SOMME_H
