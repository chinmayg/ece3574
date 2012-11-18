//Name: Chinmay Ghotkar
//ID: 905469882
//Email: chinmayg@vt.edu
//Class Name: ECE 3574
//Homework2

#include "filmlist.h"
#include <QList>
#include <QDebug>

QString FilmList::toString(){
    QStringList filmStrings;
    for(int i = 0; i < size(); ++i){
        filmStrings << at(i)->toString(true,",");
    }
    return filmStrings.join(",");
 }
Film* FilmList::findFilm(QString id){
    for(int i = 0; i < size(); ++i) {
        if( at(i)->getID().trimmed() == id.trimmed())
            return  at(i);
    }
    return 0;
}
void FilmList::addFilm(Film* film){
    Film* old(findFilm(film->getID()));
    if(old==0){
          append(film);
    }
    else{
        delete old;
    }
}
void FilmList::removeFilm(QString filmID){
    Film* ref(findFilm(filmID));
    if(ref) {
        removeAll(ref);
        delete ref;
    }
}

QString FilmList::getId(QString title){
    for(int i = 0; i < size(); ++i) {
        if(at(i)->getTitle().trimmed() == title.trimmed())
            return at(i)->getID();
    }
    return 0;
}
