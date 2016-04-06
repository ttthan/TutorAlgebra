#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;


class Expression
{
    public:
        Expression();
        Expression(const string&);
        virtual ~Expression();
        string getString() const;
        Expression* clone() const;
        virtual double eval() const;
        friend ostream& operator<<(ostream&, const Expression &);

    protected:
//        double val;
        string _nom;
    private:

};



#endif // EXPRESSION_H
