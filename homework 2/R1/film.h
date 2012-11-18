//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QDate>
#include <QStringList>

class Film
{
public:
    Film(QString id,QString title, QString dir, QString length,QDate relDate);
    Film(QStringList& propList);
    Film();
    virtual QString toString(bool labeled, QString sepChar);
    enum MPAARating
    {
        G,
        PG,
        PG_13,
        R
    };

    enum FilmType
    {
        Action,
        Comedy,
        SciFi,
        Documentary,
        Horror
    };
    QString getID();
    QString getTitle();
private:
    QString m_FilmID;
    QString m_Title;
    QString m_Director;
    QString m_FilmLength;
    QDate m_ReleaseDate;
};

#endif // FILM_H
