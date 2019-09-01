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
 * a) Enquanto todo o vetor não for percorrido ou a chave não for falsa, a ordenação não terminará
 * b)implementação abaixo
 * c) O custo dessa operação será de O(n²), devido a presença de dois laços nessa função
*/
void par_Impar(int *v, int tam){
    int z = 1;
    bool chave = true;
    while(z < tam || chave){
        chave = false;
        if((z%2) != 0){
            for (int i = 1; i < tam; i = i+2){
                if(v[i] > v[i+1]){
                    int aux = v[i];
                    v[i] = v[i+1];
                    v[i] = aux;
                    chave = true;
                }
            }
        } else {
            for(int i = 0; i < tam; i = i+2){
                if(v[i] > v[i+1]){
                    int aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                    chave = true;
                }
            }
        }
        z++;
    }
}

/**
 * Número 2
*/
void merge(int* x, int c1,int f1,int c2,int f2){
}

/**
 * Número 3
*/
int particao(){

}

void quickFind(int* x, int inicio, int fim,int k){
    
    if(inicio < fim){
        int p = particao();

        quickFind(x,p+1,fim,k);
        quickFind(x,inicio,p-1,k);
    }
}

/**
 * Número 4
*/
void heap(){

}

/**
 * Número 5
*/
void troca(int* x,int i,int j){
    int aux = x[i];
    x[i] = x[j];
    x[j] = aux;
}

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

int main(){

    int teste1[] = {7,1,3,10,17,2,21,9};
    int teste2[] = {7,1,3,10,17,2,21,9};
    int teste3[] = {7,1,3,10,17,2,21,9};
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

    cout << "Número 3) QuickFind" << endl;
    cout << "ini: ";
    imprime(teste3, 8);
    //executa ordenação
    quickFind(teste3, 0,7,5);
    cout << "fim: ";
    imprime(teste3, 8);
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