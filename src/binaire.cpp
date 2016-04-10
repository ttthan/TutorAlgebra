#include "binaire.h"

Binaire::Binaire()
{
    //ctor
}

Binaire::~Binaire()
{
    delete _gauche;
    delete _droite;
}

Binaire::Binaire(Expression *op1, Expression *op2, const string& name):Expression(name),_gauche(op1), _droite(op2)
{

}


string Binaire::afficher()
{
    return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}

Somme::Somme()
{
    //ctor
}

Somme::~Somme()
{
    //dtor
}

Somme::Somme(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"+")
{

}

double Somme::eval() const
{
    //cout << _gauche->afficher()+"\n";
    //cout << _droite->afficher();
    return (_gauche->eval()+_droite->eval());
}

Expression *Somme::deriver(const string &var)
{
    return new Somme( _gauche->deriver(var), _droite->deriver(var));
}

Expression * Somme::simplifier()
{

}

string Somme::afficher() const
{
     return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}


Expression *Somme::clone() const
{
	return new Somme(*this);
}

ostream& operator<<(ostream& os, const Somme & a)
{
    os << a.afficher();
    return os;
}

Difference::Difference()
{
    //ctor
}

Difference::~Difference()
{
    //dtor
}

Difference::Difference(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"-")
{

}

double Difference::eval() const
{
    //cout << _gauche->afficher()+"\n";
    //cout << _droite->afficher();
    return (_gauche->eval() - _droite->eval());
}

Expression *Difference::deriver(const string &var)
{
    return new Difference( _gauche->deriver(var),_droite->deriver(var));
}

Expression * Difference::simplifier()
{

}

string Difference::afficher() const
{
     return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}


Expression *Difference::clone() const
{
	return new Difference(*this);
}

ostream& operator<<(ostream& os, const Difference & a)
{
    os << a.afficher();
    return os;
}

Produit::Produit()
{
    //ctor
}

Produit::~Produit()
{
    //dtor
}

Produit::Produit(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"*")
{

}

double Produit::eval() const
{
    //cout << _gauche->afficher()+"\n";
    //cout << _droite->afficher();
    return (_gauche->eval()*_droite->eval());
}

Expression* Produit::deriver(const string &var)
{
    return new Somme( new Produit(_gauche->deriver(var),_droite ), new Produit(_gauche, _droite->deriver(var)));
}

Expression * Produit::simplifier()
{

}

Expression* Produit::clone() const
{
	return new Produit(*this);
}

string Produit::afficher() const
{
     return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}

ostream& operator<<(ostream& os, const Produit & a)
{
    os << a.afficher();
    return os;
}


Division::Division()
{
    //ctor
}

Division::~Division()
{
    //dtor
}

Division::Division(Expression *exp1, Expression *exp2, const string& name):Binaire(exp1,exp2,"/")
{

}

double Division::eval() const
{
    return (_gauche->eval() / _droite->eval());
}

Expression* Division::deriver(const string &var)
{
    return new Division( new Difference( new Produit(_gauche->deriver(var),_droite ), new Produit(_gauche, _droite->deriver(var))) , new Produit(_droite, _droite));
}

Expression * Division::simplifier()
{

}

Expression* Division::clone() const
{
	return new Division(*this);
}

string Division::afficher() const
{
     return "(" + _gauche->afficher() + Expression::_nom + _droite->afficher() + ")";
}

ostream& operator<<(ostream& os, const Division & a)
{
    os << a.afficher();
    return os;
}

Superieur::Superieur()
{
    //ctor
}

Superieur::~Superieur()
{
    //dtor
}

Superieur::Superieur(Expression *exp1, Expression *exp2):Binaire(exp1,exp2,">")
{

}

double Superieur::eval() const
{
    if(_gauche->eval() > _droite->eval())
        return 1;
    return 0;
}

Expression* Superieur::deriver(const string &var)
{

}

Expression * Superieur::simplifier()
{

}

string Superieur::afficher() const
{
    return ( "(" + _gauche->afficher()+ " > " + _droite->afficher() + ")");
}

Expression* Superieur::clone() const
{
	return new Superieur(*this);
}

ostream& operator<<(ostream& os, const Superieur & a)
{
    os << a.afficher();
    return os;
}

Inferieur::Inferieur()
{
    //ctor
}

Inferieur::~Inferieur()
{
    //dtor
}

Inferieur::Inferieur(Expression *exp1, Expression *exp2):Binaire(exp1,exp2,"<")
{

}

double Inferieur::eval() const
{
    if(_gauche->eval() < _droite->eval())
        return 1;
    return 0;
}

Expression* Inferieur::deriver(const string &var)
{

}

Expression * Inferieur::simplifier()
{

}

string Inferieur::afficher() const
{
    return ( "(" + _gauche->afficher()+ " <" + _droite->afficher() + ")");
}

Expression* Inferieur::clone() const
{
	return new Inferieur(*this);
}

ostream& operator<<(ostream& os, const Inferieur & a)
{
    os << a.afficher();
    return os;
}

SuperieurEgal::SuperieurEgal()
{
    //ctor
}

SuperieurEgal::~SuperieurEgal()
{
    //dtor
}

SuperieurEgal::SuperieurEgal(Expression *exp1, Expression *exp2):Binaire(exp1,exp2,">=")
{

}

double SuperieurEgal::eval() const
{
    if(_gauche->eval() >= _droite->eval())
        return 1;
    return 0;
}

Expression* SuperieurEgal::deriver(const string &var)
{

}

Expression * SuperieurEgal::simplifier()
{

}

string SuperieurEgal::afficher() const
{
    return ( "(" + _gauche->afficher()+ " >= " + _droite->afficher() + ")");
}

Expression* SuperieurEgal::clone() const
{
	return new SuperieurEgal(*this);
}

ostream& operator<<(ostream& os, const SuperieurEgal & a)
{
    os << a.afficher();
    return os;
}

InferieurEgal::InferieurEgal()
{
    //ctor
}

InferieurEgal::~InferieurEgal()
{
    //dtor
}

InferieurEgal::InferieurEgal(Expression *exp1, Expression *exp2):Binaire(exp1,exp2,"<=")
{

}

double InferieurEgal::eval() const
{
    if(_gauche->eval() <= _droite->eval())
        return 1;
    return 0;
}

Expression* InferieurEgal::deriver(const string &var)
{

}

Expression *InferieurEgal::simplifier()
{

}

string InferieurEgal::afficher() const
{
    return ( "(" + _gauche->afficher()+ " <= " + _droite->afficher() + ")");
}

Expression* InferieurEgal::clone() const
{
	return new InferieurEgal(*this);
}

ostream& operator<<(ostream& os, const InferieurEgal & a)
{
    os << a.afficher();
    return os;
}
