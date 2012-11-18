//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef FILMLIST_H
#define FILMLIST_H
#include <QList>
#include "film.h"

class FilmList : public QList<Film*>
{
public:
    FilmList() : QList<Film*>() {}
    QString toString();
    Film* findFilm(QString id);
    void addFilm(Film* film);
    void removeFilm(QString filmID);
    QString getId(QString title);
};

#endif // FILMLIST_H
