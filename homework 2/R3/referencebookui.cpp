//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "referencebookui.h"
#include "library.h"
#include "bookui.h"

QStringList ReferenceBookUI::prompt() {
    QTextStream cout(stdout);
    QTextStream cin(stdin);
   int idx(0);
   bool ok;
   QString str;
   QStringList retval(BookUI::prompt());
   QStringList cats(ReferenceBook::getRefCategories());
   while(1) {
      cout << "Enter the index of the correct Reference Category: ";
      for(int i = 0; i < cats.size(); ++i)
         cout << "\n\t(" << i << ") " << cats.at(i);
      cout << "\n\t(-1)None of these\t:::" << flush;
      idx = cin.readLine().toInt(&ok);
      if(ok) {
         retval << str.setNum(idx);
         break;
      }
   }
   return retval;
}
//end