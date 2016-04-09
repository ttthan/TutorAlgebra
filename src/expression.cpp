#include "expression.h"

static set<Expression*> _pool;

Expression::Expression()
{
    _pool.insert(this);
}

Expression::Expression(const string& nom) : _nom(nom) {

}

Expression::~Expression()
{
    _pool.erase(this);
}



string Expression::afficher() const
{
    return _nom;
}


ostream& operator<<(ostream& os, const Expression & a)
{
    os << a.afficher();
    return os;
}

static void toutLiberer()
{
    set<Expression*>::iterator it;
    while ( (it = _pool.begin()) != _pool.end() )
    delete (*it);
}
