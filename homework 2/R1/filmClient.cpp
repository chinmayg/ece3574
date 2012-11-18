//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "filmlist.h"
#include "entertainment.h"
#include "educational.h"
#include <QDebug>
#include <QTextStream>
enum Choices {ADD, FIND, DELETE, QUIT};
QTextStream cout(stdout);
QTextStream cin(stdin);

void addFilm(FilmList* database)
{
    Film* newFilm;
    int choice;
    QString response, id, dir, len, title, year,type, rating;
    Film::FilmType types;
    Film::MPAARating ratings;
    do {
        cout
                << 0 << ". Entertainment Film.\n"
                << 1 << ". Educational Film.\n"
                << 2 << ". Neither.\n"
                << "Your choice: " << flush;
        response = cin.readLine();
        choice = response.toInt();
    } while(choice < 0 or choice > 3);
    cout << "Enter the Film ID: " << flush;
    id = cin.readLine();
    if(database->findFilm(id))
    {
        qDebug() << "ERROR:This film already exists in the film list";
        return;
    }
    cout << "Enter the Film Title: " << flush;
    title = cin.readLine();
    cout << "Enter the Film Director: " << flush;
    dir = cin.readLine();
    cout << "Enter the Film Length: " << flush;
    len = cin.readLine();
    cout << "Enter the release date (YYYY-MM-DD): " << flush;
    year = cin.readLine();
    QDate date = QDate::fromString(year,Qt::ISODate);
    if(!date.isValid()){
        qDebug() << "ERROR:Invalid date was entered";
        return;
    }
    if(choice == 0)
    {
        cout << "Enter the Film Type(Action,Comedy,SciFi,Documentary,Horror): " << flush;
        type = cin.readLine();
        if(type.compare("Action") == 0)
        {
            types = Film::Action;
        }
        else if(type.compare("Comedy") == 0)
        {
            types = Film::Comedy;
        }
        else if(type.compare("SciFi") == 0)
        {
            types = Film::SciFi;
        }
        else if(type.compare("Documentary") == 0)
        {
            types = Film::Documentary;
        }
        else
        {
            types = Film::Horror;
        }
        cout << "Enter the Film Rating(G,PG,PG-13,R): " << flush;
        rating = cin.readLine();
        if(rating.compare("G") == 0)
        {
            ratings = Film::G;
        }
        else if(rating.compare("PG") == 0)
        {
            ratings = Film::PG;
        }
        else if(rating.compare("PG-13") == 0)
        {
            ratings = Film::PG_13;
        }
        else
        {
            ratings = Film::R;
        }
        newFilm = new Entertainment(id,title,dir,len,date,types,ratings);
    }
    else if(choice == 1)
    {
        cout << "Enter the Film Subject" << flush;
        QString sub = cin.readLine();
        cout << "Enter the Grade Level" << flush;
        QString grd = cin.readLine();
        newFilm = new Educational(id,title,dir,len,date,sub,grd.toInt());
    }
    else
    {
        newFilm = new Film(id,title,dir,len,date);
    }
    database->addFilm(newFilm);
}

void find(FilmList* database)
{
    cout << "Enter the Film Id you are looking for " << flush;
    QString id = cin.readLine();
    if(database->findFilm(id))
    {
        Film* temp = database->findFilm(id);
        qDebug() << temp->toString(true,",");
    }
    else
    {
        qDebug() << "Could not find film with id " << id;
    }
}
void deleteFilm(FilmList* database)
{
    cout << "Enter the Film Id you are looking for " << flush;
    QString id = cin.readLine();
    if(database->findFilm(id))
    {
        qDebug() << "Deleted film with id" << id;
        database->removeFilm(id);
    }
    else
    {
        qDebug() << "Could not find film with id " << id;
    }
}

int menu()
{
    int choice;
    QString response;
    do {
        cout
                << 1 << "-- ADD -- " << ". Add items to the Library.\n"
                << 2 << "-- FIND --" << ". Find and display an item.\n"
                << 3 << "-- DELETE --" << ". Remove an item from the Library.\n"
                << 0 << "-- QUIT --" << ". Exit from this program.\n"
                << "Your choice( Use Numbers): " << flush;
        response = cin.readLine();
        choice = response.toInt();
    } while(choice < ADD or choice > QUIT);
    return choice;
}

int main()
{
    FilmList* database = new FilmList();
    while(1) {
        switch(menu()) {
        case 1 : addFilm(database);
            break;
        case 2: find(database);
            break;
        case 3: deleteFilm(database);
            break;
        case 0: exit(1);
            break;
        default:
            break;
        }
    }
    return 0;
}
