#pragma once

#include "lexer.h"
#include "symbole.h"
#include <stack>
#include <string>

using namespace std;

class Etat;

class Automate
{
public:
    Automate(string flux);
    ~Automate();
    void decalage(Symbole *s, Etat *e);
    void reduction(int n, Symbole *s);
    void transitionSimple(Symbole *s, Etat *e);
    void run();
    Symbole *popSymbol();
    void popAndDestroySymbol();
    void printPileSymbole() const;
    void printPileEtat() const;

protected:
    stack<Symbole *> pileSymboles;
    stack<Etat *> pileEtats;
    Lexer *lexer;
};
