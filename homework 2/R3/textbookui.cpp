//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "textbookui.h"

QStringList TextBookUI::prompt() {
   QTextStream cout(stdout);
   QTextStream cin(stdin);
   QStringList retval(BookUI::prompt());
   cout << "Course: " << flush;
   retval << cin.readLine();
   return retval;
}

