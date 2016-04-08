#ifndef SIN_H
#define SIN_H
#include "unaire.h"

class Sin : public Unaire
{
    public:
        Sin();
        Sin(Expression *, const string& name="sin");
        virtual ~Sin();
        double eval() const;
    protected:
        double val;
    private:
};

#endif // SIN_H
