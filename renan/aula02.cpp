#include <iostream>

/** 
 * Métodos de ordenação apresentados nas notas de aula 02 da aula de estrutura de dados;
 * BurbbleSort página 26
 * BurbbleSort Melhorado página 27
 * SelectionSort página 31
 * InsertionSort página 34
 * **/

void bubbleSort(int* lista[], int n){
    int* aux;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (lista[j] > lista[j+1])
            {
                aux = lista[j+1];
                lista[j+1] =  lista[j];
                lista[j] = aux;
            }
        }
    }
}

void bubbleSortMelhorado(int* lista[], int n){
    int *aux;
    bool chave;
    for (int i = 0; i < n-1; i++)
    {
        chave = false;
        for (int j = 0; j < n-1; j++)
        {
            if(lista[j] > lista[j+1]){
                aux = lista[j+1];
                lista[j+1] =  lista[j];
                lista[j] = aux;
                chave = true;
            }
        }
        if (chave == false){
            break;
        }
    }
}

void selectionSort(int* lista[], int n){
    for(int i = 0; i < n-2; i++)
    {
        int *menor = lista[i];
        for (int j = 0; j < n-2; j++)
        {
            if(lista[j] < menor)
                menor = lista[j];
        }
    }
}

void insertionSort(int* lista[],int n){
    for (int i = 1; i < n; i++){
        int *pivo = lista[i];
        int j = i-1;

        while(j >= 0 && lista[j] > pivo){
            lista[j+1] = lista[j];
            j = j-1;
        }
        lista[j+1] = pivo;
    }
}