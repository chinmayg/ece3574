//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#ifndef LIBRARYUI_H
#define LIBRARYUI_H
#include "library.h"
#include <QList>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QDate>

class LibraryUI
{
public:
    enum Choices {READ=1, ADD, FIND, REMOVE, SAVE, LIST, QUIT};
    enum Types {BOOK, REFERENCEBOOK, TEXTBOOK, DVD, FILM, DATADVD};
    LibraryUI(Library* lib);
    void add(QStringList objData);
    void read();
    void enterData();
    QString find();
    void remove();
    void save();
    void list();
    QStringList promptRefItem();
    QStringList promptBook();
    QStringList promptReferenceBook();
    QStringList promptTextBook();
    QStringList promptDVD();
    QStringList promptFilm();
    QStringList promptDataBase();
    Choices nextTask();
    void prepareToQuit(bool saved);
private:
    Library* m_Lib;
};

#endif // LIBRARYUI_H
