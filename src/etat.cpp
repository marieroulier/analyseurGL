#include <iostream>
#include <string>

#include "etat.h"
#include "expr.h"

// virtual
Etat::~Etat() {}
Etat::Etat(const string &s) { name = s; }
int Etat::etat() { return -1; }

// E0
Etat0::Etat0() : Etat("E0"), val(0) {}
int Etat0::etat() { return 0; }
bool Etat0::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (INT):
        a.decalage(s, new Etat3);
        break;

    case (OPENPAR):
        a.decalage(s, new Etat2);
        break;

    case (EXPR):
        a.transitionSimple(s, new Etat1);
        break;

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E0" << endl;
        ret = false;
    }
    }
    return ret;
}

// E1
Etat1::Etat1() : Etat("E1"), val(1) {}
int Etat1::etat() { return 1; }
bool Etat1::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (PLUS):
        a.decalage(s, new Etat4);
        break;

    case (MULT):
        a.decalage(s, new Etat5);
        break;

    case (FIN):
        ret = false;
        break;

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E1" << endl;
        ret = false;
    }
    }
    return ret;
}

// E2
Etat2::Etat2() : Etat("E2"), val(2) {}
int Etat2::etat() { return 2; }
bool Etat2::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (INT):
        a.decalage(s, new Etat3);
        break;

    case (OPENPAR):
        a.decalage(s, new Etat2);
        break;

    case (EXPR):
        a.transitionSimple(s, new Etat6);
        break;

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E2" << endl;
        ret = false;
    }
    }
    return ret;
}

// E3
Etat3::Etat3() : Etat("E3"), val(3) {}
int Etat3::etat() { return 3; }
bool Etat3::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (PLUS):
    case (MULT):
    case (CLOSEPAR):
    case (FIN):
    {
        a.reduction(1, s); // 1 = le nombre de symbole/états a pop
        break;
    }
    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E3" << endl;
        ret = false;
    }
    }
    return ret;
}

// E4
Etat4::Etat4() : Etat("E4"), val(4) {}
int Etat4::etat() { return 4; }
bool Etat4::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (INT):
        a.decalage(s, new Etat3);
        break;

    case (OPENPAR):
        a.decalage(s, new Etat2);
        break;

    case (EXPR):
        a.transitionSimple(s, new Etat7);
        break;

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E4" << endl;
        ret = false;
    }
    }
    return ret;
}

// E5
Etat5::Etat5() : Etat("E5"), val(5) {}
int Etat5::etat() { return 5; }
bool Etat5::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (INT):
        a.decalage(s, new Etat3);
        break;

    case (OPENPAR):
        a.decalage(s, new Etat2);
        break;

    case (EXPR):
        a.transitionSimple(s, new Etat8);
        break;

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E5" << endl;
        ret = false;
    }
    }
    return ret;
}

// E6
Etat6::Etat6() : Etat("E6"), val(6) {}
int Etat6::etat() { return 6; }
bool Etat6::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (PLUS):
        a.decalage(s, new Etat4);
        break;

    case (MULT):
        a.decalage(s, new Etat5);
        break;

    case (CLOSEPAR):
        a.decalage(s, new Etat9);
        break;

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E6" << endl;
        ret = false;
    }
    }
    return ret;
}

// E7
Etat7::Etat7() : Etat("E7"), val(7) {}
int Etat7::etat() { return 7; }
bool Etat7::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (PLUS):
    case (CLOSEPAR):
    case (FIN):
    {
        a.reduction(3, s); // 3 = le nombre de symboles/états a pop
        break;
    }

    case (MULT):
    {
        a.decalage(s, new Etat5);
        break;
    }

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E7" << endl;
        ret = false;
    }
    }
    return ret;
}

// E8
Etat8::Etat8() : Etat("E8"), val(8) {}
int Etat8::etat() { return 8; }
bool Etat8::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (PLUS):
    case (MULT):
    case (CLOSEPAR):
    case (FIN):
    {
        a.reduction(3, s);
        break;
    }

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E8" << endl;
        ret = false;
    }
    }
    return ret;
}

// E9
Etat9::Etat9() : Etat("E9"), val(9) {}
int Etat9::etat() { return 9; }
bool Etat9::transition(Automate &a, Symbole *s)
{
    bool ret = true;
    switch (*s)
    {
    case (PLUS):
    case (MULT):
    case (CLOSEPAR):
    case (FIN):
    {
        a.reduction(3, s);
        break;
    }

    default:
    {
        a.decalage(new Symbole(ERREUR), nullptr);
        cout << "Erreur E9" << endl;
        ret = false;
    }
    }
    return ret;
}

void Etat::print() const
{
    cout << name << endl;
}
