/**
    Universidade Federal de Juiz de Fora
    LeitorGameInfo.h
    Propósito: Leitor do arquivo pre processado'games_detailed_info.csv' 

    @version 1.0 19/08/19
*/
#ifndef LEITORGAMEINFO_H
#define LEITORGAMEINFO_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "LeitorBase.h"
#include "GameInfo.h"

using namespace std;

class LeitorGameInfo : protected LeitorBase
{
    public:

        LeitorGameInfo(int numRegistros){
            this->caminhoArquivo = "datasets"+getDirSep()+"preprocessado"+getDirSep()+"bgg-13m-reviews.csv";
            this->numRegistros = numRegistros;
            lerArquivo();            
        };
        ~LeitorGameInfo(){}; 

        GameInfo* getDataset(){
            return dataset;
        }

    private:

        GameInfo *dataset;
        string caminhoArquivo;
        int numRegistros;
        string line;
        ifstream arqEntrada;
        bool headerProcessado;
        int linePos;
        int idMin;
        int idMax;

        void lerArquivo(){
            //abre o arquivo
            arqEntrada.open(caminhoArquivo.c_str());

            //verifica se o arquivo foi aberto
            if (!arqEntrada || !arqEntrada.is_open())
            {
                cout << "Impossivel abrir o arquivo para leitura";
                exit(1); // sai do programa se nao conseguir abrir o arquivo
            }
            
            headerProcessado=false;

            while (getline(arqEntrada, line))
            {
                vector<string> result = explode(line, ',');

                //obtem o numero de colunas e extrai o header
                if(headerProcessado==false){
                    headerProcessado=true;

                    //inicia o vetor de objetos do dataset
                    dataset = new GameInfo[numRegistros];
                    linePos=0;
                } else {

                    //preenche o dataset
                    GameInfo g;
                    g.id = stoi(result[0]);
                    g.boardgamecategory = explode(result[1], '|');
                    dataset[linePos] = g;

                    linePos++;
                    if(linePos>=numRegistros){
                        break;
                    }     
                }
            }

            if(arqEntrada.is_open()){
                arqEntrada.close();
            }
        }
};

#endif // LEITORGAMEINFO_H