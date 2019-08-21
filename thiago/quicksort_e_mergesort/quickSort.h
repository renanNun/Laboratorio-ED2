#include <iostream>
#include "UsersRated.h"

using namespace std;

void quickSort(UsersRated* vet,int inicio, int fim){

    int pivo, i, j;

    i = inicio;
    j = fim;

    if (vet[i].id < vet[j].id)
    {
        pivo = auxQuickSort(vet,i,j);

        quickSort(vet, i, j-1);
        quickSort(vet, pivo + 1,j);
    }

};

int auxQuickSort(UsersRated* vet,int inicio, int fim){

    int i,pivo,j;
    UsersRated aux;
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