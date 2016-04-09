#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <map>
#include "expression.h"

class Variable : public Expression
{
    public:
        Variable(const string&, double);
        Variable();
        Variable(const string&);
        double eval() const;
        virtual ~Variable();
        string afficher() const;
        Expression* clone() const;
        double set(double);
        friend ostream & operator << (ostream &, const Variable &);
        static void effacerMemoire();
    protected:
    private:
        const std::string _id;
        static std::map<std::string, double> _variables;

};

#endif // VARIABLE_H
