//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "libraryui.h"
#include "library.h"

int main() {
   Library lib;
   bool saved(false);
   LibraryUI libio(&lib);
   while(1) {
      switch(libio.nextTask()) {
      case LibraryUI::READ: libio.read();
         saved = false;
         break;
      case LibraryUI::ADD: libio.enterData();
         saved = false;
         break;
      case LibraryUI::FIND: libio.find();
         break;
      case LibraryUI::REMOVE: libio.remove();
         saved = false;
         break;
      case LibraryUI::SAVE: libio.save();
         saved = true;
         break;
      case LibraryUI::LIST: libio.list();
         break;
      case LibraryUI::QUIT: libio.prepareToQuit(saved);
         break;
      default:
         break;
      }
   }
}


