#include <stdio.h>
#include <string>
#include <iostream>

#include "automate.h"
#include "etat.h"
#include "expr.h"

#define DEBUG false

Automate::Automate(string flux)
{
    this->lexer = new Lexer(flux);
    Etat0 *start = new Etat0();
    pileEtats.push(start);
}

void Automate::run()
{
    bool prochainEtat = true;

    // Analyse de la chaine
    while (prochainEtat)
    {
        if (DEBUG)
        {
            cout << "**----------**" << endl;
            printPileEtat();
            printPileSymbole();
        }

        Symbole *s = lexer->Consulter();

        if (DEBUG)
        {
            cout << "Symbole courant : ";
            s->Affiche();
            cout << endl;
        }
        prochainEtat = pileEtats.top()->transition(*this, s);
    }

    // Fin de l'analyse et affichage du résultat
    if (*pileSymboles.top() != ERREUR)
    {

        Expr *expression = (Expr *)pileSymboles.top();
        cout << endl << "Syntaxe correcte !" << endl
             << "\033[32m" << "\033[1m" << "Résultat : " << expression->getValue() << "\033[0m" << endl;
    }
    else
    {
        cout << endl << "\033[31m" << "\033[1m" << "Syntaxe non reconnue : caractère invalide" << "\033[0m" << endl;
    }
}

// Transition par décalage
void Automate::decalage(Symbole *s, Etat *e)
{
    pileSymboles.push(s);
    pileEtats.push(e);
    lexer->Avancer();
}

// Transition par réduction
// n : numéro de la règle de réduction
void Automate::reduction(int n, Symbole *s)
{
    stack<Symbole *> aEnlever;

	// Pop de la pile d'états et de la pile de symboles
    for (int i = 0; i < n; i++)
    {
        if (!pileEtats.empty() && !pileSymboles.empty())
        {
            delete pileEtats.top();
            pileEtats.pop();

            aEnlever.push(pileSymboles.top());
            pileSymboles.pop();
        }
        else
        {
            cerr << "Erreur : pile d'états insuffisante lors de la réduction." << endl;

            while (!aEnlever.empty())
            {
                delete aEnlever.top();
                aEnlever.pop();
            }

            return;
        }
    }

    int val;

    if (n == 1)
    {
        val = aEnlever.top()->getValue();
    }
    else if (n == 3)
    {
        if (*aEnlever.top() == OPENPAR)
        {
            aEnlever.pop();
            val = aEnlever.top()->getValue();
        }
        else
        {
            val = aEnlever.top()->getValue();
            aEnlever.pop();
            if (*aEnlever.top() == MULT)
            {
                aEnlever.pop();
                val = val * aEnlever.top()->getValue();
            }
            else
            {
                aEnlever.pop();
                val = val + aEnlever.top()->getValue();
            }
        }
    }

    pileEtats.top()->transition(*this, new ExprConst(val));
}

// Passer d'un état à un autre
void Automate::transitionSimple(Symbole *s, Etat *e)
{
    pileSymboles.push(s);
    pileEtats.push(e);
}

Symbole *Automate::popSymbol()
{
    Symbole *s = pileSymboles.top();
    pileSymboles.pop();
    return s;
}

void Automate::popAndDestroySymbol()
{
    delete pileSymboles.top();
    pileSymboles.pop();
}

Automate::~Automate()
{
    delete lexer;
}

void Automate::printPileEtat() const
{
    cout << "Contenu de la pile Etat : " << endl;

    stack<Etat *> copiePile = pileEtats;

    while (!copiePile.empty())
    {
        copiePile.top()->print();
        copiePile.pop();
    }

    cout << endl;
}

void Automate::printPileSymbole() const
{
    cout << "Contenu de la pile Symbole : " << endl;

    stack<Symbole *> copiePile = pileSymboles;

    while (!copiePile.empty())
    {
        copiePile.top()->Affiche();
        cout << endl;
        copiePile.pop();
    }

    cout << endl;
}