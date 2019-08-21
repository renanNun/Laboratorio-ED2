/**
    Universidade Federal de Juiz de Fora
    main.cpp

    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 main.cpp mergeSort.cpp -o main && ./main
    WINDOWS:    cls & g++ -std=c++11 main.cpp mergeSort.cpp -o main & main.exe

    @author Thiago Almeida
    @version 1.0 07/08/19
*/
#include <iostream>

#include "Memoria.h"
#include "Log.h"
#include <time.h>
#include <chrono>
//classes de entidade
#include "UserReview.h"
#include "GameInfo.h"
#include "UsersRated.h"
//classes de leitura
#include "LeitorGameInfo.h"
#include "LeitorUserReviews.h"
#include "LeitorUsersRated.h"

//ordenação
#include "mergeSort.h"

using namespace std;

uint64_t unix_timestamp()
{
    uint64_t now = chrono::duration_cast<std::chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return now;
}

int main(int argc, char *argv[])
{
    Memoria memInfo;
    //cout << "Uso de memoria atual: " << memInfo.getCurrentRSS() << endl;
    int peakMemoryIni = memInfo.getPeakRSS();

    cout << "---------- INICIO -----------" << endl;

    int numRegistrosUsrRated = 50;
    LeitorUsersRated *usersRated = new LeitorUsersRated(numRegistrosUsrRated);

    UsersRated *dataset3 = usersRated->getDataset();

    cout << " registros antes de ordenar" << endl;
    
    for(int i=0; i<numRegistrosUsrRated; i++){
        cout << "id: " << dataset3[i].id << ", ";
        cout << "users rated: " << dataset3[i].usersRated << endl;
    }
    
    mergeSort(dataset3, 0, numRegistrosUsrRated-1);

    cout << " registros depois de ordenar" << endl;

    for(int i=0; i<numRegistrosUsrRated; i++){
        cout << "id: " << dataset3[i].id << ", ";
        cout << "users rated: " << dataset3[i].usersRated << endl;
    }

    int memUsada = memInfo.getPeakRSS() - peakMemoryIni;
    float memUsadaKB = memUsada / (float)1024;
    //cout << "Uso de memoria atual: " << memInfo.getCurrentRSS() << endl;
    if(memUsada < 1024){
        cout << "Maximo de memoria usada: " << memUsada << " Bytes" << endl;
    } else if(memUsadaKB < 1024){
        cout << "Maximo de memoria usada: " << memUsadaKB << "Kb" << endl;
    } else {
        float memUsadaMB = memUsadaKB / (float)1024;
        cout << "Maximo de memoria usada: " << memUsadaMB << "Mb" << endl;
    }
    
    return 0;
}