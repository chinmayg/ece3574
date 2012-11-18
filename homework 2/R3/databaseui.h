//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef DATABASEUI_H
#define DATABASEUI_H
#include "dvdui.h"

class DataBaseUI : public DVDUI
{
public:
    QStringList prompt();
};

#endif // DATABASEUI_H
