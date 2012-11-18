//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "filmui.h"

QStringList FilmUI::prompt() {
   QTextStream cout(stdout);
   QTextStream cin(stdin);
   int min;
   const int MAXTIME(1000);
   bool ok;
   QString str, ans;
   QStringList retval(DVDUI::prompt());
   cout << "Star of film: " << flush;
   retval << cin.readLine();
   cout << "Director of film: " << flush;
   retval << cin.readLine();
   while(1) {
      cout << "Length of film (minutes): " << flush;
      min = cin.readLine().toInt(&ok);
      if(ok and min > 0 and min <= MAXTIME)
         break;
   }
   str.setNum(min);
   retval << str;
   cout << "BlueRay (Y/N)? " << flush;
   ans = cin.readLine().toUpper();
   if(ans.startsWith("Y"))
      str.setNum(1);
   else
      str.setNum(0);
   retval << str;
   return retval;
}
