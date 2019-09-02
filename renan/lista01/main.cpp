/**
 * Universidade federal de Juiz de Fora - 01/09/2019
 * Lista de Exercícios de Ordenação - Prof. Bárbara de Melo Quintela
 * @version 1.0 
 * @autor: Renan Nunes da Costa Gonçalves
*/

#include <iostream>

using namespace std;

/**
 * Exercício Número 1
 * a)Enquanto a chave boolean não mudar indicando que o vetor foi totalmente trocado o laço continuará
 * b)implementação abaixo
 * c) O custo dessa operação será de O(n²), devido a presença de dois laços nessa função
*/
void troca(int* x,int i,int j);

void par_Impar(int* v,int tam){
    bool chave = false;
    while(!chave){
        chave = true;
        for(int i = 1; i < tam-1; i+= 2){
            if(v[i]> v[i+1]){
                troca(v,i,i+1);
                chave = false;
            }
        }
        for(int i = 0; i < tam-1; i += 2){
            if(v[i] > v[i+1]){
                troca(v,i,i+1);
                chave = false;
            }
        }
    }
}

/**
 * Número 2
*/
void mergeSortIntervalo(int* x, int c1,int f1,int c2,int f2){
    int meio = ((c1 + f2) / 2);
    int comeco2 = meio+1;

    if(x[meio] <= x[comeco2])
        return;

    while(c1 <= meio && comeco2 <= f2)
    {
        if(x[c1] <= x[comeco2]){
            comeco2++;
        } else {
            int valor = x[comeco2];
            int index = comeco2;

            while(index != c1){
                x[index] = x[index-1];
                index--;
            }
            x[c1] = valor;

            c1++;
            meio++;
            comeco2++;
        }
    }
}

/**
 * Número 3
*/
void troca(int* x,int i,int j);

 int particao(int *vetor,int inicio,int fim){
    int i = inicio - 1;
    int pivo = vetor[fim];

    for(int j = inicio; j <= fim - 1; j++){
        if(vetor[j] <= pivo){ 
            i++;
            troca(vetor,i,j);
        }

    }

    troca(vetor,i+1,fim);
    return (i + 1);

 } 

int quickFind(int* x, int inicio, int fim,int k){

    if(k > 0 && k <= fim-inicio +1){

        int pos = particao(x,inicio,fim);

        if(pos - inicio == k-1)
            return x[pos];
        if(pos - inicio > k - 1)
            return quickFind(x,inicio,pos-1,k);

        return quickFind(x,pos+1,fim, k-pos+inicio-1);

    }

    return 0;

}

/**
 * Número 4
*/
void heap(){

}

/**
 * Número 5
*/
void troca(int* x,int i,int j);

void heapify(int* x,int n,int i){
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if(left <= n && x[i]<x[left])
        largest = left;
    if(right <=n && x[largest]<x[right])
        largest = right;
 
    if(largest != i)
    {
        int temp = x[largest];
        x[largest] = x[i];
        x[i] = temp;
        heapify(x,n,largest);
    }
}

void maxHeap(int* x,int n){
    for(int i = n/2; i>=1;i--){
        heapify(x,n,i);
    }


}



/*Funções para teste*/
void imprime(int* vet, int tam){
    for(int i=0; i<tam;i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}

void troca(int* x,int i,int j){
    int aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

int main(){

    int teste1[] = {7,1,3,10,17,2,21,9};
    int teste2[] = {12,13,14,15,3,4,5,6};
    int teste3[] = {7, 10, 4, 3, 20, 15};
    int teste4[] = {7,1,3,10,17,2,21,9};
    int teste5[] = {7,1,3,10,17,2,21,9};

    cout << "Número 1) Transposição Par_Impar" << endl;
    cout << "ini: ";
    imprime(teste1, 8);
    //executa ordenação
    par_Impar(teste1, 8);
    cout << "fim: ";
    imprime(teste1, 8);
    cout << endl;

    cout << "Número 2) MergeSort Modificado" << endl;
    cout << "ini: ";
    imprime(teste2, 8);
    //executa ordenação
    mergeSortIntervalo(teste2,0,3,4,7);
    cout << "fim: ";
    imprime(teste2, 8);
    cout << endl;

    cout << "Número 3) QuickFind" << endl;
    cout << "ini: ";
    imprime(teste3, 6);
    int k = 3;
    //executa ordenação
    int valor = quickFind(teste3, 0,5,k);
    cout << k << "º valor:  " << valor << endl;
    cout << endl;


    cout << "Número 5) Max Heap" << endl;
    cout << "ini: ";
    imprime(teste5, 8);
    //executa ordenação
    maxHeap(teste5, 8);
    cout << "fim: ";
    imprime(teste5, 8);
    cout << endl;

    return 0;
}