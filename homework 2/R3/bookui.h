//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef BOOKUI_H
#define BOOKUI_H
#include "refitemui.h"
#include <QDate>

class BookUI : public RefItemUI
{
public:
    QStringList prompt();
};

#endif // BOOKUI_H
