#ifndef UNAIRE_H
#define UNAIRE_H
#include "expression.h"

class Unaire : public Expression
{
    public:
        Unaire();
        Unaire(Expression *, const string& name="unaire");
        virtual ~Unaire();
        virtual string afficher();
    protected:
        Expression *_op;
    private:
};


class Sin : public Unaire
{
    public:
        Sin();
        Sin(Expression *, const string& name="sin");
        virtual ~Sin();
        Expression* clone() const;
        double eval() const;
        Expression *deriver(const string &);

    protected:
        double val;
    private:
};

class Cos : public Unaire
{
    public:
        Cos();
        Cos(Expression *, const string& name="cos");
        virtual ~Cos();
        double eval() const;
        Expression *deriver(const string &);
        Expression* clone() const;
    protected:
        double val;
    private:
};

class Exponentielle : public Unaire
{
    public:
        Exponentielle();
        Exponentielle(Expression *, Expression *, const string& name="ex");
        virtual ~Exponentielle();
        double eval() const;
        Expression *deriver(const string &);
        Expression* clone() const;
        string afficher() const;
        friend ostream& operator<<(ostream&, const Exponentielle &);

    protected:
        Expression* _exp;
        Expression* _pow;
    private:
};

#endif // UNAIRE_H
