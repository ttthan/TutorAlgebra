#ifndef CONSTANTE_H
#define CONSTANTE_H


class Constante : public Expression
{
    public:
        Constante();
        Constante(const double=0.0);
        virtual ~Constante();
        virtual double eval() const;
        string afficher() const;
        Expression* clone() const;
        friend ostream& operator<<(ostream&, const Constante &);

    protected:
    private:
        double _valeur = 0;
};

#endif // CONSTANTE_H
