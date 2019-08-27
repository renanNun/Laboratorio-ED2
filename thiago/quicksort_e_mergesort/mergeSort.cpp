#include "mergeSort.h"


void mergeSort(UsersRated *vet, int inicio, int fim)
{

    int meio;

    if (inicio < fim)
    {

        meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio);
        mergeSort(vet, meio + 1, fim);
        intercala(vet, inicio, meio, fim);
    }
}

void intercala(UsersRated* vet,int inicio, int meio,int fim)
{

    UsersRated auxiliar[fim+1];
    int inicioVetor2, inicioVetor1, posicaoLivre;
    inicioVetor1 = inicio;
    inicioVetor2 = meio + 1;
    posicaoLivre = inicio;

    while (inicioVetor1 <= meio && inicioVetor2 <= fim)
    {
        if (vet[inicioVetor1].id <= vet[inicioVetor2].id)
        {
            auxiliar[posicaoLivre] = vet[inicioVetor1];
            inicioVetor1++;
        }
        else
        {
            auxiliar[posicaoLivre] = vet[inicioVetor2];
            inicioVetor2++;
        }
        posicaoLivre++;
    }

    for (int i = inicioVetor1; i <= meio; i++)
    {
        auxiliar[posicaoLivre] = vet[i];
        posicaoLivre++;
    }
    for (int i = inicioVetor2; i <= fim; i++)
    {
        auxiliar[posicaoLivre] = vet[i];
        posicaoLivre++;
    }

    for (int i = inicio; i <= fim; ++i)
    {
        vet[i] = auxiliar[i];
    }
}