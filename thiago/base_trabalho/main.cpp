/**
    Universidade Federal de Juiz de Fora
    main.cpp

    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 main.cpp -o main && ./main
    WINDOWS:    cls & g++ -std=c++11 main.cpp -o main & main.exe

    @author Thiago Almeida
    @version 1.0 07/08/19
*/
#include <iostream>

#include "Memoria.h"
#include "UserReview.h"
#include "GameInfo.h"
#include "Log.h"
#include "LeitorGameInfo.h"
#include "LeitorUserReviews.h"

using namespace std;

int main(int argc, char *argv[])
{
    Memoria memInfo;
    //cout << "Uso de memoria atual: " << memInfo.getCurrentRSS() << endl;
    int peakMemoryIni = memInfo.getPeakRSS();

    int numRegistros = 10000;
    LeitorGameInfo *gameInfo = new LeitorGameInfo(numRegistros);

    GameInfo *dataset = gameInfo->getDataset();

    cout << numRegistros << " registros do arquivo de Game Info" << endl;
    /*
    for(int i=0; i<numRegistros; i++){
        GameInfo gameInfo = dataset[i];
        cout << "id: " << gameInfo.id << ", boardgamecategory: ";
        for(int j=0; j<gameInfo.boardgamecategory.size(); j++){
            cout << gameInfo.boardgamecategory[j] << ", ";
        }
        cout << endl;
    }*/

    //////////////////
    cout << endl;

    LeitorUserReviews *userReviews = new LeitorUserReviews(numRegistros);

    UserReview *dataset2 = userReviews->getDataset();

    cout << numRegistros << " registros do arquivo de User Reviews" << endl;
    /*
    for(int i=0; i<numRegistros; i++){
        UserReview userReview = dataset2[i];
        cout << "id: " << userReview.id << ", ";
        cout << "user: " << userReview.user << ", ";
        cout << "rating: " << userReview.rating << endl;
    }
    */

    int memUsada = memInfo.getPeakRSS() - peakMemoryIni;
    int memUsadaKB = memUsada / 1024;
    //cout << "Uso de memoria atual: " << memInfo.getCurrentRSS() << endl;
    if(memUsadaKB < 1024){
        cout << "Maximo de memoria usada: " << memUsadaKB << "Kb" << endl;
    } else {
        int memUsadaMB = memUsadaKB / 1024;
        cout << "Maximo de memoria usada: " << memUsadaMB << "Mb" << endl;
    }
    
    
    return 0;
}