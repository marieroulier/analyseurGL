#include <string>
#include "symbole.h"
#include "automate.h"

class Etat
{
public:
    Etat(const string& name);
    virtual ~Etat();
    void print() const;
    virtual bool transition(Automate &automate, Symbole *s) = 0;
    virtual int etat() ;

protected:
    string name;
};

//Etat 0
class Etat0 : public Etat
{
public:
    Etat0();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;
};

//Etat 1
class Etat1 : public Etat
{
public:
    Etat1();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 2
class Etat2 : public Etat
{
public:
    Etat2();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 3
class Etat3 : public Etat
{
public:
    Etat3();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 4
class Etat4 : public Etat
{
public:
    Etat4();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 5
class Etat5 : public Etat
{
public:
    Etat5();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 6
class Etat6 : public Etat
{
public:
    Etat6();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 7
class Etat7 : public Etat
{
public:
    Etat7();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 8
class Etat8 : public Etat
{
public:
    Etat8();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};

//Etat 9
class Etat9 : public Etat
{
public:
    Etat9();
    bool transition(Automate &automate, Symbole *s);
    int etat() ;

protected:
    int val ;

};
