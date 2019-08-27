#include "quickSort.h"

using namespace std;


void quickSort1(UsersRated* vet,int inicio,int fim){    
    if(inicio < fim){
        int p = particao(vet,inicio,fim);
        quickSort1(vet, inicio, p-1);
        quickSort1(vet,p+1,fim);
    }  
}

int particao(UsersRated* vet,int inicio, int fim){
    int pivo = vet[(inicio+fim)/2].id;
    int i = inicio - 1;
    
    for(int j = inicio; j < fim-1; j++){
        if(vet[j].id < pivo)
        {
            i++;
            troca(&vet[i],&vet[j]);
        }
    }
    troca(&vet[i],&vet[fim]);
    return i + 1;
}

void troca(UsersRated* v1,UsersRated* v2){
    UsersRated* aux;
    aux = v1;
    v1 = v2;
    v2 = aux;
}