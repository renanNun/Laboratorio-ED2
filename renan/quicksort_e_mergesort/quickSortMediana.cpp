#include <iostream>
#include "UsersRated.h"
#include "quickSortMediana.h"

using namespace std;



int calculaMediana3K(UsersRated *vet)
{

    int mediana;
    int aux[3];

    aux[0] = vet[rand() % 1000].id;
    aux[1] = vet[rand() % 1000].id;
    aux[2] = vet[rand() % 1000].id;

    int auxordena;

    for (int i = 0; i < 2; i++)
    {
         for(int j=i+1;j<3;j++){
             
             if(aux[i] > aux[j]){
            	
                auxordena = aux[i];
                aux[i] = aux[j];
                aux[j] = auxordena;
            }

         }
    }

    mediana = aux[1];
    return mediana;
}

int calculaMediana5K(UsersRated *vet)
{

    int mediana;
    int aux[5];

    aux[0] = vet[rand() % 1000].id;
    aux[1] = vet[rand() % 1000].id;
    aux[2] = vet[rand() % 1000].id;
    aux[3] = vet[rand() % 1000].id;
    aux[4] = vet[rand() % 1000].id;

    int auxordena;

    for (int i = 0; i < 4; i++)
    {
         for(int j=i+1;j<5;j++){
             
             if(aux[i] > aux[j]){
            	
                auxordena = aux[i];
                aux[i] = aux[j];
                aux[j] = auxordena;
            }

         }
    }

    mediana = aux[2];
    return mediana;
}

void quickSortMediana(UsersRated *vet, int inicio, int fim)
{

    int pivo, i, j;

    i = inicio;
    j = fim;

    if (vet[i].id < vet[j].id)
    {
        pivo = auxQuickSort(vet, i, j);

        quickSortMediana(vet, i, j - 1);
        quickSortMediana(vet, pivo + 1, j);
    }
};

int auxQuickSort(UsersRated *vet, int inicio, int fim)
{

    int i, pivo, j;
    UsersRated aux;
    //chamada pra 3 medianas
    pivo =calculaMediana3K(vet);
    //chamada pra 5 medianas
    //pivo = calculaMediana5k;
    i = inicio - 1;

    for (j = inicio; j <= fim - 1; j++)
    {
        if (vet[j].id <= pivo)
        {
            i++;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
    aux = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = aux;

    return (i + 1);
};