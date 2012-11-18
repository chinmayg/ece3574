//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "dvdui.h"
#include <QTextStream>
#include <QDate>

QStringList DVDUI::prompt() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);
   bool ok;
   QString str, ans;
   int dnum;
   const int MAXDISKS(10);
   QStringList retval(RefItemUI::prompt());
   while(1) {
      cout << "Number of disks (no more than " << MAXDISKS
           << " please): " << flush;
      dnum = cin.readLine().toInt(&ok);
      if(ok and dnum > 0 and dnum <= MAXDISKS)
         break;
   }
   str.setNum(dnum);
   retval << str;
   cout << "Two-sided disks (Y/N)? " << flush;
   ans = cin.readLine().toUpper();
   if(ans.startsWith("Y"))
      str.setNum(1);
   else
      str.setNum(0);
   retval << str;
   return retval;
}
