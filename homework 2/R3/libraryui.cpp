//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "libraryui.h"
#include "library.h"
#include "refitemui.h"
#include "bookui.h"
#include "textbookui.h"
#include "referencebookui.h"
#include "dvdui.h"
#include "filmui.h"
#include "databaseui.h"

using namespace::std;
const QStringList TYPES = (QStringList() << "BOOK" << "REFERENCEBOOK" << "TEXTBOOK" << "DVD" << "FILM" << "DATADVD");
QTextStream cout(stdout);
QTextStream cin(stdin);
bool saved(false);

LibraryUI::LibraryUI(Library* lib)
{
     this->m_Lib = lib;
}
LibraryUI::Choices LibraryUI::nextTask() {
   int choice;
   QString response;
   do {
      cout << READ << ". Read data from a file.\n"
           << ADD << ". Add items to the Library.\n"
           << FIND << ". Find and display an item.\n"
           << REMOVE << ". Remove an item from the Library.\n"
           << SAVE << ". Save the Library list to a file.\n"
           << LIST << ". Brief listing of Library items.\n"
           << QUIT << ". Exit from this program.\n"
           << "Your choice: " << flush;
     response = cin.readLine();
     choice = response.toInt();
   } while(choice < READ or choice > QUIT);
   return static_cast<Choices>(choice);
}

void LibraryUI::add(QStringList objdata) {
   cout << objdata.join("[::]") << endl;
   QString type = objdata.first();
   RefItem* ref;
   switch(static_cast<Types>(TYPES.indexOf(type))) {
   case BOOK:
      ref = new Book(objdata);
      m_Lib->addRefItem(ref);
      break;
   case REFERENCEBOOK:
      ref = new ReferenceBook(objdata);
      m_Lib->addRefItem(ref);
         break;
   case TEXTBOOK:
      ref = new TextBook(objdata);
      m_Lib->addRefItem(ref);
      break;
   case DVD:
      ref = new Dvd(objdata);
      m_Lib->addRefItem(ref);
      break;
   case FILM:
      ref = new Film(objdata);
      m_Lib->addRefItem(ref);
         break;
   case DATADVD:
      ref = new DataDvd(objdata);
      m_Lib->addRefItem(ref);
      break;
   default: qDebug() << "Bad type in add() function";
   }
}
void LibraryUI::read() {
   const QString sep("[::]");
   const int BADLIMIT(5); //max number of bad lines
   QString line, type;
   QStringList objdata;
   QFile inf("libfile");
   inf.open(QIODevice::ReadOnly);
   QTextStream instr(&inf);
   int badlines(0);
   while(not instr.atEnd()) {
      if(badlines >= BADLIMIT) {
         qDebug() << "Too many bad lines! Aborting.";
         return;
      }
      line = instr.readLine();
      objdata = line.split(sep);
      if(objdata.isEmpty()) {
         qDebug() << "Empty Line in file!";
         ++badlines;
      }
      else if(not TYPES.contains(objdata.first())) {
         qDebug() << "Bad type in line: " << objdata.join(";;;");
         ++badlines;
      }
      else
         add(objdata);
    }
}
void LibraryUI::enterData() {
   QString typestr;
   while(1) {
      cout << "Library item type: " << flush;
      typestr = cin.readLine();
      if(not TYPES.contains(typestr)) {
         cout << "Please enter one of the following types:\n"
              << TYPES.join(" ,") << endl;
         continue;
      }
      break;
   }
   QStringList objdata;
   RefItemUI* ui;
   switch (TYPES.indexOf(typestr)) {
   case BOOK: objdata = (ui = new BookUI())->prompt();
         break;
   case REFERENCEBOOK: objdata = (ui = new ReferenceBookUI())->prompt();
         break;
   case TEXTBOOK: objdata = (ui = new TextBookUI())->prompt();
         break;
   case DVD: objdata = (ui = new DVDUI())->prompt();
         break;
   case FILM: objdata = (ui = new FilmUI())->prompt();
         break;
   case DATADVD: objdata = (ui = new DataBaseUI())->prompt();
         break;
   default:
         qDebug() << "Bad type in enterData()";
   }
   objdata.prepend(typestr);
   add(objdata);
}
QString LibraryUI::find() {
   QString isbn, item;
   cout << "Search ISBN: " << flush;
   isbn = cin.readLine();
   item = m_Lib->getItemString(isbn);
   if(item == QString()) {
      cout << isbn << " not found." << endl;
      return item;
   }
   else {
      cout << item << endl;
      return isbn;
   }
}
void LibraryUI::remove() {
   QString isbn(find()), ans;
   if(isbn == QString()) {
      cout << isbn << " not found." << endl;
      return;
   }
   cout << "Remove this item (Y/N)? " << flush;
   ans = cin.readLine().toUpper();
   if(ans.startsWith("N"))
      return;
   int numCopiesLeft = m_Lib->removeRefItem(isbn);
   cout << "There are now  " << numCopiesLeft
        << " copies left in the library." << endl;
}

// Save data to a file.
//start id=lclsave
void LibraryUI::save(){
   QFile outf("libfile");
   outf.open(QIODevice::WriteOnly);
   QTextStream outstr(&outf);
   outstr << m_Lib->toString();
   outf.close();
}
//end

void LibraryUI::list() {
   cout << m_Lib->toString() << endl;
}

void LibraryUI::prepareToQuit(bool saved) {
   QString ans;
   if(!saved) {
      cout << "Save data first (Y/N)? " << flush;
      ans = cin.readLine().toUpper();
      if(ans.startsWith("Y")) {
         save();
         exit(0);
      }
   }
   exit(1);
}

