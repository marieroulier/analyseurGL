#include <iostream>
#include <stdio.h>
#include "lexer.h"
#include "automate.h"

int main()
{
   string chaine("");

   // Entrée par l'utilisateur de la chaîne à analyser
   cout << "Ecrivez la phrase à analyser (symboles acceptés : '*' '+' '(' ')' ) :" << endl;
   cin >> chaine;

   cout << "\033[33m" << "Analyse de " << chaine << "..." << "\033[0m" << endl << endl;

   // Lancement de l'analyse
   Automate *a = new Automate(chaine);
   a->run();

   return 0;
}
