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
void mergeIntervals(int* x, int c1,int f1,int c2,int f2){
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
    
    if(inicio < fim){
        int p = particao(x,inicio,fim);

        quickFind(x,p+1,fim,k);
        quickFind(x,inicio,p-1,k);
    }
    
    return x[k];
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

void heapify(int* x,int n, int i){
    int p = (n/2) -1;
    bool existe = true;

    while(p > -1){
        int pai = x[p];
        int f1 = x[2*p];
        int f2 = x[2*p+1];

        if(2*p+1 >= n){
            existe = false;
        }

        if(f1 < f2 && existe){
            if(pai < f2){
                troca(x,p,2*p+1);
            }
        } else {
            if(pai < f1){
                troca(x,p,2*p);
            }
        }
        p--;
    }
}

void maxHeap(int* x,int n){
    for(int i = n-1; i > 1; i--){
        heapify(x,n,i);
        troca(x,0,i);
    }
}

void corrige(int* x,int n){
    int i = n;
    while(i >= 2 && x[i/2] < x[i]){
        troca(x,i/2,i);
        i = i/2;
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
    int teste3[] = {7,1,3,10,17,2,21,9};
    int teste4[] = {7,1,3,10,17,2,21,9};
    int teste5[] = {7,1,3,10,17,2,21,9};

    int testeMax[] = {99,8,7,65,82,84,72,82,71,3,1,9,22,10,1,100,555,657,983};

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
    mergeIntervals(teste2,0,3,4,7);
    cout << "fim: ";
    imprime(teste2, 8);
    cout << endl;

    cout << "Número 3) QuickFind" << endl;
    cout << "ini: ";
    imprime(teste3, 8);
    int k = 5;
    //executa ordenação
    int valor = quickFind(teste3, 0,7,k-1);
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