//Name: Chinmay Ghotkar
//ID: 905469882
//email: chinmayg@vt.edu
//ECE 3574
//Homework 1

#include <QDate>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <string>
#include <iostream>
using namespace std;
static QString fileName = "birthdays.dat";

bool deleteLine(QString name)
{
    QFile dataFile(fileName);
    bool isAvailable = false;
    QFile dataFileTemp("temp.dat");
    if(dataFile.open(QFile::ReadOnly))
    {
        if((!dataFileTemp.open(QFile::WriteOnly))) {
            qDebug() << "Could not open file " + fileName;
        }
        QTextStream in(&dataFile);
        QTextStream out(&dataFileTemp);
        while(!in.atEnd()){
            QString line = in.readLine(); //read one line at a time
            QStringList lineItems = line.split('|');
            if(lineItems.indexOf(name)<0){
                out << line << endl;
            }
            else{
                isAvailable = true;
            }
        }
        dataFile.remove();
        if(!dataFileTemp.rename("temp.dat",fileName)){
            qDebug() << "Unable to change file name";
        }
    }
    return isAvailable;
}
bool appendFile(QString year, QString name)
{
    QFile dataFile(fileName);
    if(!dataFile.open(QIODevice::ReadWrite | QIODevice::Append)){
        qDebug() << "Could not open file for writing";
        return false;
    }
    QTextStream out(&dataFile);
    QString newText(year + "|" + name + "\n");
    out << newText;
    dataFile.close();
    return true;
}
bool addBirthday(QString year, QString name)
{
    bool isAvailable = false;
    QDate date = QDate::fromString(year,Qt::ISODate);
    if(date.isValid()){
        isAvailable = deleteLine(name);
        isAvailable = appendFile(year,name);
    }
    else{
        qDebug() << "ERROR:Invalid date was entered";
    }
    return isAvailable;
}
bool printList(int days)
{
    QFile dataFile(fileName);
    bool isAvailable = false;
    if((!dataFile.open(QFile::ReadOnly))){
        qDebug() << "Could not open file, you need to add people to the data file " + fileName;
    }
    QDate currentDate = QDate::currentDate();
    QDate monthBoundary = QDate::currentDate();
    monthBoundary = monthBoundary.addDays(days);
    QTextStream in(&dataFile);
    QStringList withinDates;
    while(!in.atEnd()){
        QString line = in.readLine(); //read one line at a time
        QStringList lineItems = line.split('|');
        for (QStringList::iterator it = lineItems.begin();it != lineItems.end(); ++it){
            QString current = *it;
            QDate date = QDate::fromString(current,Qt::ISODate);
            if(date >= currentDate && date <= monthBoundary){
                withinDates.push_front(line);
                isAvailable = true;
            }
        }
    }
    withinDates.sort();
    if(isAvailable){
        qDebug() << "Name" << "\t\t" << "Birthday";
        qDebug() << "====" << "\t\t" << "========";
    }
    for (QStringList::iterator it = withinDates.begin();it != withinDates.end(); ++it){
        QString current = *it;
        QStringList lineItems = current.split('|');
        qDebug() << lineItems[1] << "\t" << lineItems[0];
    }
    return isAvailable;
}
bool findBirthdayAfterPerson(int days, QString name)
{
    QFile dataFile(fileName);
    bool isAvailable = false;
    if((!dataFile.open(QFile::ReadOnly))){
        qDebug() << "Could not open file " + fileName;
    }
    else{
        QTextStream in(&dataFile);
        while(!in.atEnd()){
            QString line = in.readLine(); //read one line at a time
            QStringList lineItems = line.split('|');
            if(lineItems.indexOf(name)>0){
                printList(days);
                isAvailable = true;
            }
        }
    }
    dataFile.close();
    return isAvailable;
}
bool nameSpecSearch(QString phrase)
{
    QFile dataFile(fileName);
    bool isAvailable = false;
    if((!dataFile.open(QFile::ReadOnly))){
        throw "Could not open file " + fileName;
    }
    QTextStream in(&dataFile);
    QStringList withinName;
    while(!in.atEnd()){
        QString line = in.readLine(); //read one line at a time
        if(line.contains(phrase) >= 0){
            isAvailable = true;
            QStringList temp = line.split('|');
            QStringList temp2;
            for(int i = temp.size()-1; i>=0;i--){
                temp2.push_back(temp[i]);
            }
            line = temp2.join("|");
            withinName.push_front(line);
            isAvailable = true;
        }
    }
    withinName.sort();
    if(isAvailable){
        qDebug() << "Name" << "\t\t" << "Birthday";
        qDebug() << "====" << "\t\t" << "========";
    }
    for (QStringList::iterator it = withinName.begin();it != withinName.end(); ++it){
        QString current = *it;
        QStringList lineItems = current.split('|');
        qDebug() << lineItems[0] << "\t" << lineItems[1];
    }
    return isAvailable;
}
void update()
{
    QFile dataFile(fileName);
    if((!dataFile.open(QFile::ReadOnly))){
        qDebug() << "Could not open file " + fileName;
    }
    else{
        QFile dataFileTemp("temp.dat");
        if((!dataFileTemp.open(QFile::WriteOnly))){
            qDebug() << "Could not open file " + fileName;
        }
        QTextStream in(&dataFile);
        QTextStream out(&dataFileTemp);
        QDate currentDate = QDate::currentDate();
        while(!in.atEnd()){
            QString line = in.readLine(); //read one line at a time
            QStringList lineItems = line.split('|');
            for (QStringList::iterator it = lineItems.begin();it != lineItems.end(); ++it){
                QString current = *it;
                QDate date = QDate::fromString(current,Qt::ISODate);
                if(date.isValid()){
                    if(currentDate.year() > date.year()){
                        date.setDate(currentDate.year(),date.month(),date.day());
                        lineItems[0] = date.toString(Qt::ISODate);
                    }
                    if(date < currentDate){
                        if(QDate::isLeapYear(date.year())){
                            date = date.addYears(4);
                        }
                        else{
                            date = date.addYears(1);
                        }
                        lineItems[0] = date.toString(Qt::ISODate);
                        line = lineItems.join("|");
                        out << line << endl;
                    }
                    else{
                        line = lineItems.join("|");
                        out << line << endl;
                    }
                }
            }
        }
        dataFile.remove();
        if(!dataFileTemp.rename("temp.dat",fileName)){
            qDebug() << "Unable to change file name";
        }
    }
}
int main(int argc, char* argv[]){
    //check if file exists
    //if it doesn't create file "birthdays.dat"
    //else initiate the QFile object
    QString flag(argv[1]);
    bool isAvailable = false;
    try{
        if(flag.compare("") == 0){
            if(argc == 1){
                isAvailable = printList(30);
            }
            else{
                qDebug() << "Incorrect command line arguments";
                isAvailable = true;
            }
        }
        else if(flag.compare("-a") == 0){
            if(argc == 4){
                QString year(argv[2]);
                QString name(argv[3]);
                QDate date = QDate::fromString(year,Qt::ISODate);
                if(date.isValid()){
                    isAvailable = addBirthday(year,name);
                }
                else{
                    qDebug() << "ERROR:Invalid date entered";
                    isAvailable = true;
                }
            }
            else{
                qDebug() << "Incorrect command line arguments";
                isAvailable = true;
            }
        }
        else if(flag.compare("-n") == 0){
            if(argc == 3){
                QString string(argv[2]);
                bool ok;
                int days = string.toInt(&ok,10);
                if(ok){
                    isAvailable = printList(days);
                }
                else{
                    qDebug() << "ERROR:Enter a numerical value";
                    isAvailable = true;
                }
            }
            else{
                qDebug() << "Incorrect command line arguments";
                isAvailable = true;
            }
        }
        else if(flag.compare("-d") == 0){
            if(argc == 3){
                QString string(argv[2]);
                deleteLine(string);
            }
            else{
                qDebug() << "Incorrect command line arguments";
                isAvailable = true;
            }
        }
        else if(flag.compare("-m") == 0){
            QString name(argv[2]);
            QString string(argv[3]);
            bool ok;
            int days = string.toInt(&ok,10);
            if(ok){
                isAvailable = findBirthdayAfterPerson(days,name);
            }
            else{
                qDebug() << "ERROR:Enter a numerical value";
                isAvailable = true;
            }
        }
        else if(flag.compare("-u") == 0){

            update();
            isAvailable = true;
        }
        else{
            QString phrase = argv[2];
            isAvailable = nameSpecSearch(phrase);
        }
        if(!isAvailable)
        {
            qDebug() << "There was no birthday found!" << endl;
        }
    }catch(char* errorMessage)
    {
        qDebug() << errorMessage << endl;
    }
    return 0;
}
