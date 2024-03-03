#include "symbole.h"

class Expr : public Symbole
{
public:
    Expr() : Symbole(EXPR) {}
    virtual ~Expr() {}
    virtual int getValue() = 0;
};

class ExprMult : public Expr
{
public:
    ExprMult(Expr *g, Expr *d) : gauche(g), droite(d) {}
    int getValue();
    ~ExprMult()
    {
        delete gauche;
        delete droite;
    }

protected:
    Expr *gauche;
    Expr *droite;
};

class ExprPlus : public Expr
{
public:
    ExprPlus(Expr *g, Expr *d) : gauche(g), droite(d) {}
    int getValue();
    ~ExprPlus()
    {
        delete gauche;
        delete droite;
    }

protected:
    Expr *gauche;
    Expr *droite;
};

class ExprConst : public Expr
{
public:
    ExprConst(int valeur) : val(valeur) {}
    int getValue();
    ~ExprConst() {}

protected:
    int val;
};