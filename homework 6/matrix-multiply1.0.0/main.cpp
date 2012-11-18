//Chinmay Ghotkar
//905469882
//chinmayg@vt.edu
//ECE 3574
//Homework 6

/*Why I used Mutex:
I used to mutex to lock and unlock the multiplication that created the resultant matrix C.
The mutex code was added to the multplication code that was used in the threads.
I had to use mutex lock because threads have to access the resultant matrix C at the same time when the value is stored.
I didnt use mutex in the read file function because each thread is reading two different files and are accessing two
different matrices*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QList>
#include <sstream>
#include <typeinfo>

using namespace std;
pthread_mutex_t resultantLock = PTHREAD_MUTEX_INITIALIZER;

struct Matrix{
    int M;
    int N;
    QList<QList<float> > matrix;
};

struct ThreadArgs{
    char* filename;
    Matrix* matrix;
    bool success;
    bool floatType;
    bool intType;
};

struct DotProductThreadArgs{
    int row;
    int column;
};

Matrix* A;
Matrix* B;
Matrix* C;

void *readFile(void *arg)
{
    ThreadArgs* args = (ThreadArgs*) arg;
    string strline;
    ifstream myfile(args->filename);
    if (myfile.is_open()) {
        int counterM = 0;
        while(!myfile.eof()){
            QList<float> line;
            getline(myfile,strline);
            istringstream iss(strline,istringstream::in);
            istringstream tester(strline,istringstream::in);
            int counterN = 0;
            //Test the type of the matrix
            while(tester.good()){
                string tempStr;
                tester >> tempStr;
                if(tempStr != ""){
                    if(tempStr.find(".") != string::npos && args->intType){
                        cout << "ERROR: File " << args->filename << " was not a single type format" << endl;
                        args->success = false;
                        pthread_exit((void*)1);
                    }
                    else if(tempStr.find(".") == string::npos && args->floatType){
                        cout << "ERROR: File " << args->filename << " was not a single type format" << endl;
                        args->success = false;
                        pthread_exit((void*)1);
                    }
                    if(tempStr.find(".") != string::npos){
                        args->floatType = true;
                        args->intType = false;
                    }
                    else{
                        args->floatType = false;
                        args->intType = true;
                    }
                }
            }
            //Creates the matrix
            while(iss.good()){
                float temp;
                iss >> temp;
                if(iss.fail()){
                    cout << temp << endl;
                    cout << "ERROR: File " << args->filename << " was not formatted correctly or there is blank line somewhere"
                                                             << endl;
                    args->success = false;
                    pthread_exit((void*)1);
                }
                line.append(temp*1.0);
                counterN++;
            }
            args->matrix->matrix.append(line);
            if(args->matrix->N == 0){
                args->matrix->N = counterN;
            }
            else if(args->matrix->N != counterN){
                cout << "ERROR: File " << args->filename << " was not formatted correctly" << endl;
                args->success = false;
                pthread_exit((void*)1);
            }
            counterM++;
        }
        args->matrix->M = counterM;
        myfile.close();
        args->success = true;
    }
    else{
        cout << "ERROR: Unable to open file " << args->filename <<  endl;
        args->success = false;
        pthread_exit((void*)1);
    }
    pthread_exit((void*)0);
}

void *multiplyMatrix(void* args)
{
    DotProductThreadArgs* arg = (DotProductThreadArgs*) args;
    int row = arg->row;
    int col = arg->column;
    float total = 0;
    for(int i = 0; i < A->N; i++){
        total += A->matrix[row][i]*B->matrix[i][col];
    }
    pthread_mutex_lock(&resultantLock);
    C->matrix[row][col] = total;
    pthread_mutex_unlock(&resultantLock);
    pthread_exit((void*)0);
}

int main(int argc, char* argv[])
{
    if(argc == 4){
        pthread_t thread1, thread2;
        ThreadArgs file1Arg, file2Arg;
        //Intializes all of the matrices
        A = new Matrix;
        B = new Matrix;
        C = new Matrix;
        A->M = 0;
        A->N = 0;
        B->M = 0;
        B->N = 0;
        C->M = 0;
        C->N = 0;
        file1Arg.filename = argv[1];
        file1Arg.matrix = A;
        file1Arg.intType = false;
        file1Arg.floatType = false;
        file2Arg.filename = argv[2];
        file2Arg.matrix = B;
        file2Arg.intType = false;
        file2Arg.floatType = false;
        pthread_mutex_init(&resultantLock,NULL);
        // Create independent threads each of which will execute function
        pthread_create( &thread1, NULL, readFile, (void*) &file1Arg);
        pthread_create( &thread2, NULL, readFile, (void*) &file2Arg);

        pthread_join( thread1, NULL);
        pthread_join( thread2, NULL);
        if(file1Arg.floatType == file2Arg.floatType || file1Arg.intType == file2Arg.intType){
            if(file1Arg.success && file2Arg.success){
                //check the types of the matrices
                if(A->N == B->M){
                    //Setting the dimensions of resultant matrix
                    C->M = A->M;
                    C->N = B->N;
                    for(int r = 0; r < C->M; r++){
                        QList<float> line;
                        for(int c = 0; c < C->N; c++){
                            line.append(0.0);
                        }
                        C->matrix.append(line);
                    }
                    //Thread Creation Loop
                    pthread_t thread_id[C->M][C->N];
                    for(int r = 0; r < C->M; r++){
                        for(int c = 0; c < C->N; c++){
                            DotProductThreadArgs* dotProductArg = new DotProductThreadArgs;
                            dotProductArg->row = r;
                            dotProductArg->column = c;
                            pthread_create( &thread_id[r][c], NULL, multiplyMatrix,(void*) dotProductArg);
                        }
                    }
                    //Thread Joining Loop
                    for(int r = 0; r < C->M; r++){
                        for(int c = 0; c < C->N; c++){
                            pthread_join( thread_id[r][c], NULL);
                        }
                    }

                }
            }
            else{
                return 1;
            }
            ofstream myfile;
            myfile.open(argv[3]);
            myfile.precision(4);
            if(myfile.is_open()){
                for(int r = 0; r < C->M; r++){
                    for(int c = 0; c < C->N; c++){
                        if(file1Arg.floatType){
                            myfile << fixed << C->matrix[r][c] << " ";
                        }
                        else{
                            myfile << C->matrix[r][c] << " ";
                        }
                    }
                    myfile << endl;
                }
            }
            else{
                cout << argv[3] << "ERROR: Doesn't have permission to open and write to it" << endl;
            }
        }
        else{
            cout << "ERROR: Matrices are not the same type" << endl;
        }
    }
    else{
        cout << "ERROR: Not enough inputs" << endl;
        return 1;
    }
    return 0;
}
