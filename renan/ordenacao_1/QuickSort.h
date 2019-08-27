#include <iostream>

using namespace std;

class QuickSort{

public:
    QuickSort(){};
    ~QuickSort(){};

    //Métodos da classe
    void ordenar(int* vetor,int inicio, int fim){

        if(inicio < fim) {

            int p = particao(vetor,inicio,fim);

            ordenar(vetor,inicio,p-1);
            ordenar(vetor,p+1,fim);

        }
    };


private:

    int particao(int *vetor,int inicio,int fim){
        int i = inicio - 1;

        int pivo = vetor[fim];

        for(int j = inicio; j <= fim - 1; j++){
            //cout << "passou aqui" << endl;
            if(vetor[j] <= pivo){
                i++;
                troca(&vetor[i],&vetor[j]);
            }

        }

        troca(&vetor[i+1],&vetor[fim]);
        return (i + 1);

    };  

    void troca(int* a, int* b){
        int* t = a;
        a = b;
        b = t;
        //cout << "trocou" << endl;
    };

};  