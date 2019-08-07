/**
    Universidade Federal de Juiz de Fora
    LerArquivo.cpp
    Descrição: 1. Faça o exercício 1 proposto nas págs 20 e 21 das notas de aula (Cap 1).

    @author Thiago Almeida
    @version 1.0 07/08/19

    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 AcrescentaArquivo.cpp -o AcrescentaArquivo && ./AcrescentaArquivo
    WINDOWS:    cls & g++ -std=c++11 AcrescentaArquivo.cpp -o AcrescentaArquivo & AcrescentaArquivo.exe
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    string nomeArquivo = "";
    fstream arquivo;

    /* Leitura */
    cout << "Digite o nome do arquivo" << endl;
    cin >> nomeArquivo;

    //abre o arquivo
    arquivo.open((nomeArquivo + ".txt").c_str(), fstream::in | fstream::out | fstream::app);

    //verifica se o arquivo foi aberto
    if (!arquivo || !arquivo.is_open())
    {
        cout << "Impossivel abrir o arquivo";
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
            arquivo << chave << "," << nome << "," << nota1 << "," << nota2 << endl;

            //calcula a média das duas notas do aluno
            float media = (nota1 + nota2)/2;

            //exibe resultado
            cout << "Nome: " << nome << ", Media das notas: " << media << endl;
        } 
        linha++;

        //limpa o buffer do cin
        cin.seekg(0,ios::end);
        cin.clear();
    }

    if(arquivo.is_open()){
        arquivo.close();
    }
    return 0;
}