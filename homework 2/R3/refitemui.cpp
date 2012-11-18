//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "refitemui.h"

QStringList RefItemUI::prompt() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);
   const int MAXCOPIES(10);
   const int ISBNLEN(13);
   int copies;
   QString str;
   QStringList retval;
   while(1) {
      cout << "ISBN ("<< ISBNLEN << " digits): " << flush;
      str = cin.readLine();
      if(str.length() == ISBNLEN) {
         retval << str;
         break;
      }
   }
   cout << "Title: " << flush;
   retval << cin.readLine();
   while(1) {
      cout << "Number of copies: " << flush;
      copies = cin.readLine().toInt();
      if(copies > 0 and copies <= MAXCOPIES) {
         str.setNum(copies);
         break;
      }
   }
   retval << str;
   return retval;
}