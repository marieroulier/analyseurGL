#include "symbole.h"
#include <iostream>

// Symbole
void Symbole::Affiche()
{
   cout << Etiquettes[ident];
}

int Symbole::getValue() { return -1; }

// Entier
void Entier::Affiche()
{
   Symbole::Affiche();
   cout << "(" << valeur << ")";
}

int Entier::getValue() { return valeur; }

// Fin
void Fin::Affiche()
{
   Symbole::Affiche();
}

// Erreur
void Erreur::Affiche()
{
   Symbole::Affiche();
}


