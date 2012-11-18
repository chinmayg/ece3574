//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "entertainment.h"

Entertainment::Entertainment(QString id, QString title, QString dir, QString len, QDate relDate, FilmType type, MPAARating rating) : Film(id,title,dir,len,relDate)
{
    m_Type = type;
    m_Rating = rating;
}

Entertainment::Entertainment(QStringList& propList) : Film(propList), m_Type(qStringtoFilmType(propList.takeFirst())), m_Rating(qStringToRating(propList.takeFirst()))
{
}

Entertainment::FilmType Entertainment::qStringtoFilmType(QString type)
{
    if(type.compare("Action") == 0)
    {
        return Action;
    }
    else if(type.compare("Comedy") == 0)
    {
        return Comedy;
    }
    else if(type.compare("SciFi") == 0)
    {
        return SciFi;
    }
    else if(type.compare("Documentary") == 0)
    {
        return Documentary;
    }
    else
    {
        return Horror;
    }
}

Entertainment::MPAARating Entertainment::qStringToRating(QString rating)
{
    if(rating.compare("G") == 0)
    {
        return G;
    }
    else if(rating.compare("PG") == 0)
    {
        return PG;
    }
    else if(rating.compare("PG_13") == 0)
    {
        return PG_13;
    }
    else
    {
        return R;
    }
}


QString Entertainment::filmTypeToQString(Entertainment::FilmType type)
{
    if(type == Action)
    {
        return "Action";
    }
    else if(type == Comedy)
    {
        return "Comedy";
    }
    else if(type == SciFi)
    {
        return "SciFi";
    }
    else if(type == Documentary)
    {
        return "Documentary";
    }
    else if(type == Horror)
    {
        return "Horror" ;
    }
    else
    {
        return "Unknown";
    }
}

 QString Entertainment::ratingToQString(Entertainment::MPAARating rating)
{
    if(rating == G)
    {
        return "G";
    }
    else if(rating == PG)
    {
        return "PG";
    }
    else if(rating == PG_13)
    {
        return "PG-13";
    }
    else if(rating == R)
    {
        return "R";
    }
    else
    {
        return "Unknown";
    }
}
QString Entertainment::toString(bool labeled, QString sepChar)
{
    if(labeled){
        return QString("%1%2%3%4%5").arg(Film::toString(labeled,sepChar)).arg(sepChar).arg(filmTypeToQString(m_Type)).arg(sepChar).arg(ratingToQString(m_Rating));
    }
    return 0;
}
