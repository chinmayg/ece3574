//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef FILMUI_H
#define FILMUI_H
#include "dvdui.h"

class FilmUI : public DVDUI
{
public:
    QStringList prompt();
};

#endif // FILMUI_H
