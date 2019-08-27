/**
    Universidade Federal de Juiz de Fora
    QuickSort.h
    Propósito: Implementação do algoritmo QuickSort.

    @author Renan Nunes
    @version 1.0 21/08/19
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>

using namespace std;

template <class T>
class QuickSort
{
    public:
        QuickSort(){};
        ~QuickSort(){};

        void ordenar(T* vet,int inicio, int fim){

            int pivo, i, j;

            i = inicio;
            j = fim;

            if (vet[i].id < vet[j].id)
            {
                pivo = auxQuickSort(vet,i,j);

                ordenar(vet, i, j-1);
                ordenar(vet, pivo + 1,j);
            }

        };

    private:

        int auxQuickSort(T* vet,int inicio, int fim){

            int i,pivo,j;
            T aux;
            pivo = vet[fim].id;
            i = inicio-1;

            for(j = inicio; j <= fim - 1; j++){
                if(vet[j].id <= pivo)
                {
                    i++;
                    aux = vet[i];
                    vet[i] = vet[j];
                    vet[j] = aux;
                }
            }
            aux = vet[i+1];
            vet[i+1] = vet[fim];
            vet[fim] = aux;
            
            return (i+1);
        };

};

#endif // QUICKSORT_H