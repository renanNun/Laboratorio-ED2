/**
    Universidade Federal de Juiz de Fora
    EscreveArquivo.cpp
    Descrição: 1. Faça o exercício 1 proposto nas págs 20 e 21 das notas de aula (Cap 1).

    @author Thiago Almeida
    @version 1.0 07/08/19

    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 EscreveArquivo.cpp -o EscreveArquivo && ./EscreveArquivo
    WINDOWS:    cls & g++ -std=c++11 EscreveArquivo.cpp -o EscreveArquivo & EscreveArquivo.exe
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    string nomeArquivo;
    ofstream arqSaida;

    /* Escrita */

    cout << "Digite o nome do arquivo" << endl;
    getline(cin, nomeArquivo);
    
    //abre o arquivo
    arqSaida.open((nomeArquivo + ".txt").c_str());

    //verifica se o arquivo foi aberto
    if (!arqSaida || !arqSaida.is_open())
    {
        cout << "Impossivel abrir o arquivo de saida para escrita";
        exit(1); // sai do programa se nao conseguir abrir o arquivo
    }
    cout << "Digite '-1' para sair" << endl;
    cout << "Formato da entrada: [chave] [nome] [nota 1] [nota 2]" << endl << endl;

    int linha=0;
    int chave;
    string nome;
    float nota1, nota2;

    while(chave != -1){
        
        //indica a linha
        cout << "[" << linha << "] ";

        //leitura dos dados 
        cin >> chave;
        if(chave != -1){
            cin >> nome >> nota1 >> nota2;
            arqSaida << chave << "," << nome << "," << nota1 << "," << nota2 << endl;
        } 
        linha++;

        //limpa o buffer do cin
        cin.seekg(0,ios::end);
        cin.clear();
    }

    //fecha o arquivo
    if(arqSaida.is_open()){
        arqSaida.close();
    }

    return 0;
}