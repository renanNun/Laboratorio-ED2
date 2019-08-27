/**
    Universidade Federal de Juiz de Fora
    SelectionSort.h
    Propósito: Implementação do algoritmo SelectionSort.

    @author Thiago Almeida
    @version 1.0 14/08/19
*/

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>

using namespace std;

class SelectionSort
{
    public:
        SelectionSort(){};
        ~SelectionSort(){};

        //metodos da classe
        void ordenar(int* vetor, int tam){
            for(int i=0; i<tam-1; i++){
                int menor=i;
                for(int j=i+1; j<tam; j++){
                    if(vetor[j] < vetor[menor]){
                        menor = j;
                    }
                }
                troca(vetor, i, menor);
            }
        }
    private:

        void troca(int* vetor, int p1, int p2){
            int aux = vetor[p1];
            vetor[p1] = vetor[p2];
            vetor[p2] = aux;
        }

};

#endif // SELECTIONSORT_H
