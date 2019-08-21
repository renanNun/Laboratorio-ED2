/**
    Universidade Federal de Juiz de Fora
    LeitorUsersRated.h
    Propósito: Leitor do arquivo pre processado '2019-05-02.csv' 

    @version 1.0 21/08/19
*/
#ifndef LEITORUSERSRATED_H
#define LEITORUSERSRATED_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "UsersRated.h"

using namespace std;

class LeitorUsersRated : protected LeitorBase
{
    public:

        LeitorUsersRated(int numRegistros){
            this->caminhoArquivo = "datasets"+getDirSep()+"preprocessado"+getDirSep()+"2019-05-02.csv";
            this->numRegistros = numRegistros;
            lerArquivo();
        };
        ~LeitorUsersRated(){}; 

        UsersRated* getDataset(){
            return dataset;
        }

    private:
        UsersRated *dataset;
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
            gerarSemente();//gera uma nova semente para essa execução
            
            while (getline(arqEntrada, line))
            {
                vector<string> result = explode(line, ',');

                //obtem o numero de colunas e extrai o header
                if(headerProcessado==false){
                    headerProcessado=true;

                    //inicia o vetor de objetos do dataset
                    dataset = new UsersRated[numRegistros];
                    linePos=0;
                    idMin=99999999;
                    idMax=-99999999;
                } else {
                    //preenche o dataset
                    //if(getRand(1)){
                        UsersRated u;
                        u.id = stoi(result[0]);
                        u.usersRated = stoi(result[1]);
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
                    //}                 
                }
            }

            if(arqEntrada.is_open()){
                arqEntrada.close();
            }
        }
};

#endif // LEITORUSERSRATED_H