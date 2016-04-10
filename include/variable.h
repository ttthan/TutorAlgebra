#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <map>
#include "expression.h"
#include "constante.h"

class Variable : public Expression
{
    public:
        Variable(const string&, double);
        Variable();
        Variable(const string&);
        double eval() const;
        Expression *deriver(const string &);
        Expression *simplifier();
        virtual ~Variable();
        string afficher() const;
        Expression* clone() const;
        double set(double);
        friend ostream & operator << (ostream &, const Variable &);
        static void effacerMemoire();
    protected:
    private:
        const string _id;
        static map<string, double> _variables;

};

#endif // VARIABLE_H
