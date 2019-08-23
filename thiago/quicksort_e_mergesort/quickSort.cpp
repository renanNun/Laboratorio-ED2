#include "quickSort.h"

using namespace std;

void quickSort1(UsersRated* vet,int inicio,int fim){
    int pivot, i, j, meio;
    UsersRated aux;

    i = inicio;
    j = fim;

    meio = (int)((i+j)/2);
    pivot = vet[meio].id;

    do {
        while(vet[i].id < pivot) i = i + 1;
        while(vet[j].id > pivot) j = j + 1;

        if(i <= j){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i = i + 1;
            j = j -1;

        }
    } while (j > 1);

    if(inicio < j) quickSort1(vet,inicio, j);
    if(i < fim) quickSort1(vet,i,fim);


}

void quickSort2(UsersRated* vet,int inicio,int fim){    
    if(fim <= inicio) return;

    int p = particao(vet,inicio,fim);
    quickSort2(vet, inicio, p-1);
    quickSort2(vet,p+1,fim);
}

int particao(UsersRated* vet,int inicio, int fim){
    int i = inicio;
    int j = fim;
    UsersRated pivo = vet[(inicio+fim)/2];

    while(1){
        while(vet[i].id < pivo.id) i++;
        while(pivo.id < vet[j].id) j--;
        if(i >= j) break;
        troca(vet[i],vet[j]);
        i++;
        j--;
    }
    troca(vet[i],vet[fim]);
    return i;
}

void troca(UsersRated* v1[],UsersRated* v2[]){
    UsersRated* aux;
    aux = v1;
    v1 = v2;
    v2 = aux;
}