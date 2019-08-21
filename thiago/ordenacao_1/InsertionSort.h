/**
    Universidade Federal de Juiz de Fora
    SelectionSort.h
    Propósito: Implementação do algoritmo SelectionSort.

    @author Thiago Almeida
    @version 1.0 14/08/19
*/

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>

using namespace std;

class InsertionSort
{
    public:
        InsertionSort(){};
        ~InsertionSort(){};

        //metodos da classe
        void ordenar(int* vetor, int tam){
            for(int i=0; i<tam; i++){
                int pivo=vetor[i];
                int j=i-1;
                while(j>=0 && vetor[j] > pivo){
                    vetor[j+1] = vetor[j];
                    j-=1;
                }
                vetor[j+1] = pivo;
            }
        }
    private:
        //
};

#endif // INSERTIONSORT_H
