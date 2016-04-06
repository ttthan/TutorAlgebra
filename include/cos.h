#ifndef COS_H
#define COS_H
#include "unaire.h"

class Cos : public Unaire
{
    public:
        Cos();
        Cos(Expression *, const string& name="cos");
        virtual ~Cos();
        double eval() const;
    protected:
        double val;
    private:
};

#endif // COS_H
