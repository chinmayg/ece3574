//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef EDUCATIONAL_H
#define EDUCATIONAL_H
#include "film.h"

class Educational : public Film{
public:
    Educational(QString id, QString title, QString dir, QString len, QDate relDate, QString subject, int gradeLvl);
    Educational(QStringList& propList);
    QString toString(bool labeled, QString sepChar);
private:
    QString m_Subject;
    int m_GradeLevel;
};

#endif // EDUCATIONAL_H
