//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef TEXTBOOKUI_H
#define TEXTBOOKUI_H
#include "bookui.h"

class TextBookUI : public BookUI
{
public:
    QStringList prompt();
};

#endif // TEXTBOOKUI_H
