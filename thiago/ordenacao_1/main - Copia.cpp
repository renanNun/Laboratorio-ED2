#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

using namespace std;

void imprime(int* vet, int tam){
    for(int i=0; i<tam;i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[])
{

    string nomeArquivo = "2019-05-02.csv";
    string line;
    ifstream arqEntrada;
    bool headerProcessado=false;
    int* dataset;
    int numColunas=1;
    int numLinhas=10;
    int linePos=0;

    //abre o arquivo
    arqEntrada.open(nomeArquivo.c_str());

    //verifica se o arquivo foi aberto
    if (!arqEntrada || !arqEntrada.is_open())
    {
        cout << "Impossivel abrir o arquivo para leitura";
        exit(1); // sai do programa se nao conseguir abrir o arquivo
    }

    while (getline(arqEntrada, line))
    {
        istringstream iss_dados(line);
        vector<string> result;

        //separa por virgula a linha
        while(iss_dados.good())
        {
            getline( iss_dados, line, ',' );
            result.push_back( line );
        }

        //obtem o numero de colunas e extrai o header
        if(headerProcessado==false){
            headerProcessado=true;

            //inicia a matriz do dataset
            dataset = new int[numLinhas];
        } else {
            //preenche o dataset
            for(int i=0; i<result.size() && i<numColunas;i++){
                dataset[linePos] = stoi(result[0]);
            }
            linePos++;
            if(linePos>=numLinhas){
                break;
            }
        }
    }

    if(arqEntrada.is_open()){
        arqEntrada.close();
    }

    BubbleSort *bubbleSort = new BubbleSort();
    SelectionSort *selectionSort = new SelectionSort();
    InsertionSort *insertionSort = new InsertionSort();

    int teste1[] = {3,6,7,1,9,5,8,2,4,0};
    int teste2[] = {3,6,7,1,9,5,8,2,4,0};
    int teste3[] = {3,6,7,1,9,5,8,2,4,0};
    int teste4[] = {3,6,7,1,9,5,8,2,4,0};
    
    cout << "BubbleSort comum" << endl;
    cout << "ini: ";
    imprime(teste1, 10);
    //executa ordenação
    bubbleSort->ordenar(teste1, 10);
    cout << "fim: ";
    imprime(teste1, 10);
    cout << endl;

    cout << "BubbleSort melhorado" << endl;
    cout << "ini: ";
    imprime(teste2, 10);
    //executa ordenação
    bubbleSort->ordenar_melhorado(teste2, 10);
    cout << "fim: ";
    imprime(teste2, 10);
    cout << endl;

    cout << "SelectionSort" << endl;
    cout << "ini: ";
    imprime(teste3, 10);
    //executa ordenação
    selectionSort->ordenar(teste3, 10);
    cout << "fim: ";
    imprime(teste3, 10);
    cout << endl;

    cout << "InsertionSort" << endl;
    cout << "ini: ";
    imprime(teste3, 10);
    //executa ordenação
    insertionSort->ordenar(teste3, 10);
    cout << "fim: ";
    imprime(teste3, 10);
    cout << endl;

    return 0;

}