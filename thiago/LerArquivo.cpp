/**
    Universidade Federal de Juiz de Fora
    LerArquivo.cpp
    Descrição: 1. Faça o exercício 1 proposto nas págs 20 e 21 das notas de aula (Cap 1).

    @author Thiago Almeida
    @version 1.0 07/08/19

    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 LerArquivo.cpp -o LerArquivo && ./LerArquivo
    WINDOWS:    cls & g++ -std=c++11 LerArquivo.cpp -o LerArquivo & LerArquivo.exe
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string nomeArquivo = "teste";
    ifstream arqEntrada;

    /* Leitura */

    cout << "Digite o nome do arquivo" << endl;
    cin >> nomeArquivo;

    //abre o arquivo
    arqEntrada.open((nomeArquivo + ".txt").c_str());

    //verifica se o arquivo foi aberto
    if (!arqEntrada || !arqEntrada.is_open())
    {
        cout << "Impossivel abrir o arquivo de saida para leitura";
        exit(1); // sai do programa se nao conseguir abrir o arquivo
    }


    //le o arquivo linha por linha
    string line;
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
        
        if(result.size() >= 4){
            //se separou os quatro valores, faz o cast para o tipo correto
            int chave = stoi(result[0]);
            string nome = result[1];
            float nota1 = stof(result[2]);
            float nota2 = stof(result[3]);

            //calcula a média das duas notas do aluno
            float media = (nota1 + nota2)/2;

            //saida
            cout << "Nome: " << nome << ", Media das notas: " << media << endl;
        }
        
    }

    if(arqEntrada.is_open()){
        arqEntrada.close();
    }
    return 0;
}