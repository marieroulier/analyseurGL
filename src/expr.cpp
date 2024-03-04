#include "expr.h"

// Expression d'une multiplication
int ExprMult::getValue()
{
    return gauche->getValue() * droite->getValue();
}

// Expression d'une addition
int ExprPlus::getValue()
{
    return gauche->getValue() + droite->getValue();
}

// Expression constante
int ExprConst::getValue()
{
    return val;
}
