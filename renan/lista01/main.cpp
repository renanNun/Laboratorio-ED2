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
    int meio;
    int inicio, fim;

    inicio = c1;
    fim = f2;

    if(inicio < fim){
        meio = (inicio + fim)/2;
    }
}

/**
 * Número 3
*/
void quickFind(int* x, int inicio, int fim int k){

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

    cout << "Número 1) Transposição Par_Impar" << endl;
    cout << "ini: ";
    imprime(teste1, 8);
    //executa ordenação
    par_Impar(teste1, 8);
    cout << "fim: ";
    imprime(teste1, 8);
    cout << endl;

    return 0;
}