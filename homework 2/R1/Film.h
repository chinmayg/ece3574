//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QDate>

class Film
{
public:
    //Constructors and Destructors
    virtual QString toString(bool labeled, QString proplist);
private:
    QString m_FilmID;
    QString m_Title;
    QString m_Director;
    int m_FilmLength;
    QDate m_ReleaseDate;
};


#endif // FILM_H


