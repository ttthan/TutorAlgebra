#ifndef SUPERIEUR_H
#define SUPERIEUR_H
#include "binaire.h"
#include "expression.h"

class Superieur : public Binaire
{
    public:
        Superieur();
        virtual ~Superieur();
        double eval() const;
        Expression* clone() const;
        string afficher() const;
        Superieur(Expression *, Expression *);
        friend ostream& operator<<(ostream&, const Superieur &);

    protected:
    private:
};

#endif // SUPERIEUR_H
