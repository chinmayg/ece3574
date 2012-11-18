//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H
#include "film.h"

class Entertainment : public Film {
public:
    Entertainment(QString id, QString title, QString dir, QString len, QDate relDate, FilmType type, MPAARating rating);
    Entertainment(QStringList& propList);
    QString toString(bool labeled, QString proplist);
private:
    QString filmTypeToQString(FilmType type);
    QString ratingToQString(MPAARating rating);
    MPAARating qStringToRating(QString rating);
    FilmType qStringtoFilmType(QString type);
    QString m_FilmID;
    FilmType m_Type;
    MPAARating m_Rating;
};

#endif // ENTERTAINMENT_H
