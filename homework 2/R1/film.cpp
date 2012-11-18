//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "film.h"

Film::Film(QString id,QString title, QString dir, QString length,QDate relDate)
{
    m_FilmID = id;
    m_Title = title;
    m_Director = dir;
    m_FilmLength = length;
    m_ReleaseDate = relDate;
}

Film::Film(QStringList& propList) : m_FilmID(propList.takeFirst()),m_Title(propList.takeFirst()),m_Director(propList.takeFirst())
  ,m_FilmLength(propList.takeFirst()),m_ReleaseDate(QDate::fromString(propList.takeFirst(),Qt::ISODate))
{}

QString Film::getID()
{
    return m_FilmID;
}
QString Film::getTitle()
{
    return m_Title;
}

QString Film::toString(bool labeled, QString sepChar)
{
    if(labeled){
        return QString("%1%2%3%4%5%6%7%8%9").arg(m_FilmID).arg(sepChar).arg(m_Title)
                                .arg(sepChar).arg(m_Director).arg(sepChar)
                                .arg(m_FilmLength).arg(sepChar).arg(m_ReleaseDate.toString());
    }
    return 0;
}