//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "databaseui.h"

QStringList DataBaseUI::prompt() {
   QTextStream cout(stdout);
   QTextStream cin(stdin);
   QStringList retval(DVDUI::prompt());
   cout << "Database protocol: " << flush;
   retval << cin.readLine();
   return retval;
}
