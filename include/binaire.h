#ifndef BINAIRE_H
#define BINAIRE_H
#include "expression.h"

class Binaire : public Expression
{
    public:
        Binaire();
        virtual ~Binaire();
        Binaire(Expression *, Expression *, const string& name="binaire");
        virtual string afficher();
    protected:
        Expression *_gauche, *_droite;
    private:
};

class Difference : public Binaire
{
    public:
        Difference();
        virtual ~Difference();
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Expression *clone() const;
        string afficher() const;
        Difference(Expression *, Expression *, const string& name="-");
        friend ostream& operator<<(ostream&, const Difference &);

    protected:
    private:
};

class Somme : public Binaire
{
    public:
        Somme();
        virtual ~Somme();
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Expression *clone() const;
        string afficher() const;
        Somme(Expression *, Expression *, const string& name="+");
        friend ostream& operator<<(ostream&, const Somme &);

    protected:
    private:
};


class Produit : public Binaire
{
    public:
        Produit();
        virtual ~Produit();
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Expression* clone() const;
        string afficher() const;
        Produit(Expression *, Expression *, const string& name="*");
        friend ostream& operator<<(ostream&, const Produit &);

    protected:
    private:
};

class Division : public Binaire
{
    public:
        Division();
        virtual ~Division();
        double eval() const;
        Expression* clone() const;
        string afficher() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Division(Expression *, Expression *, const string& name="/");
        friend ostream& operator<<(ostream&, const Division &);

    protected:
    private:
};

class Superieur : public Binaire
{
    public:
        Superieur();
        virtual ~Superieur();
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Expression* clone() const;
        string afficher() const;
        Superieur(Expression *, Expression *);
        friend ostream& operator<<(ostream&, const Superieur &);

    protected:
    private:
};

class Inferieur : public Binaire
{
    public:
        Inferieur();
        virtual ~Inferieur();
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Expression* clone() const;
        string afficher() const;
        Inferieur(Expression *, Expression *);
        friend ostream& operator<<(ostream&, const Inferieur &);

    protected:
    private:
};

class SuperieurEgal : public Binaire
{
    public:
        SuperieurEgal();
        virtual ~SuperieurEgal();
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Expression* clone() const;
        string afficher() const;
        SuperieurEgal(Expression *, Expression *);
        friend ostream& operator<<(ostream&, const SuperieurEgal &);

    protected:
    private:
};

class InferieurEgal : public Binaire
{
    public:
        InferieurEgal();
        virtual ~InferieurEgal();
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        Expression* clone() const;
        string afficher() const;
        InferieurEgal(Expression *, Expression *);
        friend ostream& operator<<(ostream&, const InferieurEgal &);

    protected:
    private:
};


#endif // BINAIRE_H
