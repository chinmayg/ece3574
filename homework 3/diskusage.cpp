#include <QDir>
#include <QString>
#include <QTextStream>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>
#include <cmath>

QTextStream cout(stdout);
bool v = 0, w = 0, c = 0, d = 0,b = 0,k = 0,m = 0;
float divider = 0.0;

int calculateDirectoryBytes(QString dirName, int byteTotal, int callCount){
    QFileInfo file(dirName);
    if(file.isDir()){
        callCount++;
        QDir directory(dirName);
        directory.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
        QFileInfoList fileList = directory.entryInfoList();
        int sumFolder = 0;
        for(int i = 0; i < fileList.size();i++){
            QFileInfo fileDir = fileList.at(i);
            sumFolder += fileDir.size();
            byteTotal = calculateDirectoryBytes(fileList.at(i).filePath(),byteTotal,callCount);
            if(!w && !c && !d && fileDir.isDir()){
                cout << fileDir.filePath() << " " << ceil(fileDir.size()/divider);
                if(k){
                    cout <<"k"<<endl;
                }
                else if(m){
                    cout <<"M"<<endl;
                }
                else{
                    cout<<endl;
                }
            }
            else if(w){
                cout << fileDir.filePath() << " " << ceil(fileDir.size()/divider);
                if(k){
                    cout <<"k"<<endl;
                }
                else if(m){
                    cout <<"M"<<endl;
                }
                else{
                    cout<<endl;
                }
            }
            else if(c && !w && !d && !v){
                if(callCount < 2){
                    cout << fileDir.filePath() << " " << ceil(fileDir.size()/divider);
                    if(k){
                        cout <<"k"<<endl;
                    }
                    else if(m){
                        cout <<"M"<<endl;
                    }
                    else{
                        cout<<endl;
                    }
                }
            }
        }
    }
    byteTotal += file.size();
    return byteTotal;
}
QStringList processArgument(int argc,char* argv[]){
    QStringList listOfFiles;
    for(int i = 0; i < argc; i++){
        QString str(argv[i]);
        if(str.contains("-v",Qt::CaseSensitive)){
            v = 1;
        }
        else if(str.contains("-w",Qt::CaseSensitive)){
            w = 1;
        }
        else if(str.contains("-c",Qt::CaseSensitive)){
            c = 1;
        }
        else if(str.contains("-d",Qt::CaseSensitive)){
            d = 1;
        }
        else if(str.contains("-b",Qt::CaseSensitive)){
            b = 1;
            divider = 1;
        }
        else if(str.contains("-k",Qt::CaseSensitive)){
            k = 1;
            divider = 1024.0;
        }
        else if(str.contains("-m",Qt::CaseSensitive)){
            m = 1;
            divider = 1024.0*1024.0;
        }
        if((str.contains("/") && !str.contains(".")) || (!str.contains("-") && !str.contains("diskusage"))){
            listOfFiles.append(str);
        }
    }
    if((!v|!w|!c|!d)){
        v = 1;
    }
    if(divider == 0){
        k = 1;
        divider = 1024.0;
    }
    return listOfFiles;
}
int main(int argc, char* argv[]){
    QStringList listOfFiles;
    listOfFiles = processArgument(argc,argv);
    for(int i = 0; i < listOfFiles.size();i++){
        int byteTotal = 0;
        int count = 0;
        QFileInfo dir(listOfFiles.at(i));
        byteTotal = calculateDirectoryBytes(dir.filePath(),byteTotal,count);
        if(v && dir.isDir()){
            cout << dir.filePath() << " " << ceil(byteTotal/divider);
            if(k){
                cout <<"k"<<endl;
            }
            else if(m){
                cout <<"M"<<endl;
            }
            else{
                cout<<endl;
            }
            if(i != listOfFiles.size()-1){
                cout<<endl;
            }
        }
        else if(!v | w | c | d){
            cout << dir.filePath() << " " << ceil(byteTotal/divider);
            if(k){
                cout <<"k"<<endl;
            }
            else if(m){
                cout <<"M"<<endl;
            }
            else{
                cout<<endl;
            }
            if(i != listOfFiles.size()-1){
                cout<<endl;
            }
        }
    }
    return 0;
}
