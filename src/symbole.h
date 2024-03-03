#pragma once

#include <string>
using namespace std;

enum Identificateurs
{
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   INT,
   FIN,
   ERREUR,
   EXPR
};

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole
{
public:
   Symbole(int i) : ident(i) {}
   virtual ~Symbole() {}
   operator int() const { return ident; }
   virtual void Affiche();
   virtual int getValue();

protected:
   int ident;
};

class Entier : public Symbole
{
public:
   Entier(int v) : Symbole(INT), valeur(v) {}
   ~Entier() {}
   virtual void Affiche();
   int getValue();

protected:
   int valeur;
};

class Fin : public Symbole
{
public:
   Fin() : Symbole(FIN) {}
   ~Fin() {}
   virtual void Affiche();
};

class Erreur : public Symbole
{
public:
   Erreur() : Symbole(ERREUR) {}
   ~Erreur() {}
   virtual void Affiche();
};
