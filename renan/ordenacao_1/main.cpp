#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "QuickSort.h"
#include "ordenacaoParImpar.h"

using namespace std;

void imprime(int* vet, int tam){
    for(int i=0; i<tam;i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{

    ParImpar  *parImpar = new ParImpar();
    QuickSort *quickSort = new QuickSort();


    int teste1[] = {3,6,7,1,9,5,8,2,4,0};
    int teste2[] = {3,6,7,1,9,5,8,2,4,0};
    int teste3[] = {3,6,7,1,9,5,8,2,4,0};
    int teste4[] = {3,6,7,1,9,5,8,2,4,0};
    int teste5[] = {3,6,7,1,9,5,8,2,4,0};
    
    cout << "Par e Impar" << endl;
    cout << "ini: ";
    imprime(teste1, 10);
    //executa ordenação
    parImpar->ordenar(teste1,10);
    cout << "fim: ";
    imprime(teste1, 10);
    cout << endl;



    cout << "QuickSort" << endl;
    cout << "ini: ";
    imprime(teste5, 10);
    //executa ordenação
    quickSort->ordenar(teste5,0,9);
    cout << "fim: ";
    imprime(teste5, 10);
    cout << endl;


    return 0;

}