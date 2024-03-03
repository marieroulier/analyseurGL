#include "expr.h"


// ExprMult
int ExprMult::getValue()
{
    return gauche->getValue() * droite->getValue();
}

// ExprPlus
int ExprPlus::getValue()
{
    return gauche->getValue() + droite->getValue();
}

// ExprConst
int ExprConst::getValue()
{
    return val;
}
