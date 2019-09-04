#include <iostream>
#include <string>

using namespace std;

//######### Metodos auxiliares ###########//

void imprimeVetor(int *vetor, int tam, string label){
    cout << label << endl;
    for(int i=0; i<tam; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}
void troca(int* vetor, int p1, int p2){
    int aux = vetor[p1];
    vetor[p1] = vetor[p2];
    vetor[p2] = aux;
}


//######### Questao 1 ###########//


void transposicaoParImpar(int *x, int tam){
    bool compAtual = false; //compara inicialmente os impares
    bool ordenado = false; //fica true quando chega a condição de parada
    
    while(ordenado==false){
        int numTrocas=0;
        for(int i=0; i<tam-1; i++){
            bool isPar = i%2==0;
            if(isPar == compAtual && x[i] > x[i+1]){
                troca(x, i, i+1);
                numTrocas++;
            }
        }
        if(numTrocas==0){
            //condição de parada
            ordenado=true;
        }
        //inverte a comparação atual
        compAtual = !compAtual;
    }
}

//######### Questao 2 ###########//

int* merge(int* x, int c1, int f1, int c2, int f2, int tam){
    int *retorno = new int[tam];

    //indices de controle
    int i = c1;
    int j = c2;
    int k = 0;

    while(k < tam){
        if(i>f1){
            //se só sobrar um de uma lista 1, coloca ele no vetor
            retorno[k] = x[j];
        } 
        else if(j>f2){
            //se só sobrar um de uma lista 2, coloca ele no vetor
            retorno[k] = x[i];
        } 
        else if(x[i] < x[j]){
            //o item da lista 1 é menor - coloca no vetor
            retorno[k] = x[i];
            i++;
        } else {
            //o item da lista 2 é menor - coloca no vetor
            retorno[k] = x[j];
            j++;
        }
        k++;//move indice do vetor
    }

    return retorno;
}

//######### Questao 3 ###########//

int quickfind(int *s, int inicio, int fim, int k){
    return 0;
}

//######### Questao 5 ###########//

void auxHeap(int *v, int tam, int i, int p){
    if(i < tam){
        auxHeap(v,tam, 2*i+1, i);
        auxHeap(v,tam, 2*i+2, i);

        if(v[i] > v[p]){
            int aux = v[i];
            v[i] = v[p];
            v[p] = aux;
        }
    }
}

void maxHeap(int *v, int tam){
    for(int i=0; i < tam/2;i++){
        auxHeap(v,tam,0, 0);
    }
}

//######### Questao 4 ###########//

int* maxValores(int *v, int tam, int k){
    //cria vetor auxiliar pra heap de tamanho k
    int *heap = new int[k];
    int j = 0;

    //passa 10 numeros do vetor
    for(int i=0; i<k; i++){
        heap[i] = v[j];
        j++;
    }

    while (j < tam){
        //cria maxheap
        maxHeap(heap, k);
        int entra=0;

        //substitui de k/2 a k com elementos do vetor
        for(int i=(k/2)-1; i<k; i++){
            if(j < tam && v[j] > heap[i]){
                heap[i] = v[j];
            }
            j++;            
        }
    }

    return heap;
}

int main(int argc, char *argv[])
{
    cout << "///// Questão 1 ////" << endl;

    int vetorQ1[] = {9,4,7,2,0,8,5,1,6,3,2,-1};
    int tamVetor = 12;

    imprimeVetor(vetorQ1, tamVetor, "Vetor antes");
    transposicaoParImpar(vetorQ1, tamVetor);
    imprimeVetor(vetorQ1, tamVetor, "Vetor depois");

    cout << "a) A condicao de termino é quando ele passar o vetor sem fazer nenhuma troca." << endl;
    cout << "b) O algoritmo esta na funcao transposicaoParImpar()." << endl;
    cout << "a) O que eu observei é que esse algoritmo é O(n^2)." << endl;
    

    cout << endl << "///// Questão 2 ////" << endl;

    int vetorQ2[] = {0,2,4,7,8,9, -1,1,2,3,5,6,10};
    tamVetor=13;
    int c1 = 0;
    int f1 = 5;
    int c2 = 6;
    int f2 = 12;

    imprimeVetor(vetorQ2, tamVetor, "Vetor antes");
    int* retorno = merge(vetorQ2, c1, f1, c2, f2, tamVetor);
    imprimeVetor(retorno, tamVetor, "Vetor depois");

    cout << endl << "///// Questão 3 ////" << endl;

    int vetorQ3[] = {7,1,3,10,17,2,21,9};
    tamVetor = 8;

    imprimeVetor(vetorQ3, tamVetor, "Vetor antes");
    int encontrado = quickfind(vetorQ3, 0, 7, 5);
    cout << "Encontrado: " << encontrado << endl;

    cout << endl << "///// Questão 4 ////" << endl;

    //100 números aleatorios unicos de 1 a 100
    int vetorQ4[] = {81,7,86,47,9,53,79,84,85,23,45,68,42,76,82,80,52,59,29,51,93,22,77,83,16,41,49,63,21,55,48,64,1,46,70,30,12,6,2,91,74,54,50,3,5,24,89,18,58,67,10,15,73,92,20,100,90,65,35, 8,25,34,13,99,40,57,95,36, 4,14,96,43,69,17,98,97,71,44,38,61,33,62,60,39,27,88,75,56,87,19,94,28,37,26,72,11,78,66,31,32};
    tamVetor = 100;
    
    cout << "Resultado esperado para k=10" << endl << "100 99 98 97 96 95 94 93 92 91" << endl;
    int *resultado = maxValores(vetorQ4, tamVetor, 10);
    imprimeVetor(resultado, 10, "10 maiores numeros");


    cout << endl << "///// Questão 5 ////" << endl;

    int vetorQ5[] = {4,1,3,2,16,9,10,14,8,7};
    tamVetor = 10;

    imprimeVetor(vetorQ5, tamVetor, "Vetor antes");
    maxHeap(vetorQ5, tamVetor);
    imprimeVetor(vetorQ5, tamVetor, "Vetor depois");

    return 0;
}
