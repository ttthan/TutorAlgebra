#ifndef FONCTION_H
#define FONCTION_H
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <map>
#include <set>
using namespace std;

class fonction
{
    public:
        fonction() {}
        virtual ~fonction() {}
    protected:
    private:
};

string string_from_double(double val) { ostringstream os; os << val; return os.str(); }


#endif // FONCTION_H
