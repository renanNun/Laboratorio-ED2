/**
    Universidade Federal de Juiz de Fora
    LeitorUserReviews.h
    Propósito: Leitor do arquivo pre processado 'bgg-13m-reviews.csv' 

    @version 1.0 18/08/19
*/
#ifndef LEITORUSERREVIEWS_H
#define LEITORUSERREVIEWS_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "UserReview.h"
#include "GameInfo.h"

using namespace std;

class LeitorUserReviews : protected LeitorBase
{
    public:

        LeitorUserReviews(int numRegistros){
            this->caminhoArquivo = "datasets"+getDirSep()+"preprocessado"+getDirSep()+"bgg-13m-reviews.csv";
            this->numRegistros = numRegistros;
            lerArquivo();
        };
        ~LeitorUserReviews(){}; 

        UserReview* getDataset(){
            return dataset;
        }

    private:
        UserReview *dataset;
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
                    dataset = new UserReview[numRegistros];
                    linePos=0;
                    idMin=99999999;
                    idMax=-99999999;
                } else {
                    //preenche o dataset
                    UserReview u;
                    u.id = stoi(result[0]);
                    u.user = result[1];
                    u.rating = stof(result[2]);
                    dataset[linePos] = u;

                    //id minimo
                    if(u.id < idMin){
                        idMin = u.id;
                    }
                    //id maximo
                    if(u.id > idMax){
                        idMax = u.id;
                    }


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

#endif // LEITORUSERREVIEWS_H