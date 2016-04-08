#ifndef SUPERIEUR_H
#define SUPERIEUR_H
#include "binaire.h"

class Superieur : public Binaire
{
    public:
        Superieur();
        virtual ~Superieur();
        virtual double eval();
        string afficher() const;
        Superieur(Expression *, Expression *);
        friend ostream& operator<<(ostream&, const Expression &);

    protected:
    private:
};

#endif // SUPERIEUR_H
