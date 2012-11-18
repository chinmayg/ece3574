//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "bookui.h"

QStringList BookUI::prompt() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);
   static const int MINYEAR(1900),
                    MAXYEAR(QDate::currentDate().year());
   int year;
   QStringList retval(RefItemUI::prompt());
   QString str;
   cout << "Author: " << flush;
   retval << cin.readLine();
   cout << "Publisher: " << flush;
   retval << cin.readLine();
   while(1) {
      cout << "Copyright year: " << flush;
      year = cin.readLine().toInt();
      if(year >= MINYEAR and year <= MAXYEAR) {
         str.setNum(year);
         break;
      }
   }
   retval << str;
   return retval;
}
