//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "educational.h"

Educational::Educational(QString id, QString title, QString dir, QString len, QDate relDate, QString subject, int gradeLvl) : Film(id,title,dir,len,relDate)
{
    m_Subject = subject;
    m_GradeLevel = gradeLvl;
}

Educational::Educational(QStringList& propList) :  Film(propList), m_Subject(propList.takeFirst()), m_GradeLevel(propList.takeFirst().toInt())
{

}

QString Educational::toString(bool labeled, QString sepChar)
{
    if(labeled){
        return QString("%1%2%3%4%5").arg(Film::toString(labeled,sepChar)).arg(sepChar).arg(m_Subject).arg(sepChar).arg(m_GradeLevel);
    }
    return 0;
}
