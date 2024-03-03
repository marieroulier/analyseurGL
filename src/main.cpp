#include <iostream>
#include <stdio.h>
#include "lexer.h"
#include "automate.h"

int main()
{
   string chaine("(1+34)*123");

   cout << "Ecrivez la phrase à analyser (symboles acceptés : '*' '+' '(' ')' ) :" << endl;
   cin >> chaine;

   cout << "\033[33m" << "Analyse de " << chaine << "..." << "\033[0m" << endl << endl;

   /*Lexer l(chaine);

   Symbole *s;
   while (*(s = l.Consulter()) != FIN)
   {
      s->Affiche();
      cout << endl;
      l.Avancer();
   }*/

   Automate *a = new Automate(chaine);
   a->run();

   return 0;
}
