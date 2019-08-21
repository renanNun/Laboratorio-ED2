#include <iostream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

/* Exercicício Proposto do capítulo 1, notas de aulas página 24. Sobre leitura de arquivos */


class aluno{

    private:
        int matricula;
        string nome;
        float nota1;
        float nota2;
        float media  = (nota1 + nota2) / 2;;

    public:
        aluno(){};
        ~aluno(){};

        int getMat(){ return this->matricula;};
        string getNome(){return this->nome;};
        float getN1(){return this->nota1;};
        float getN2(){return this->nota2;};
        float getMedia(){return this->media;};

        void setMat(int m){this->matricula = m;};
        void setNome(string m){this->nome = m;};
        void setN1(float m){this->nota1 = m;};
        void setN2(float m){this->nota2 = m;};

        void novoAluno(){
            cout << "\nDigite a matricula: ";  
            cin >> this->matricula;
            cout << "\nDigite o nome: ";
            cin >> this->nome;
            cout << "\nDigite a nota 1: ";
            cin >> this->nota1;
            cout << "\nDigite a nota 2: ";
            cin >> this->nota2;
        };

        void print(){
            cout << endl << this->matricula << " " << this->nome << " "
            << this->nota1 << " " << this->nota2;

        };

};

int main(int argc, char *argv[]){
   
    /*ofstream arquivo;
    arquivo.open("arquivo.txt");
    
    aluno li;
    char chave = 's';

    if(arquivo.is_open()){

        do{
            li.novoAluno(); //lê o teclado
            arquivo.write((char*)&li, sizeof(aluno)); //grava o arquivo;
            cout << "\nInserir outro aluno (s/n)"; 
            cin >> chave;
        } while(chave == 's');


    }else{
        cout << "Erro ao abrir arquivo!" << endl;
        exit(1);
    }

    ifstream arquivo("arquivo.txt");
    while(arquivo){
        arquivo.read((char*)&li,sizeof(aluno));
        li.print();
    }*/

    fstream arquivo;
    aluno li;

    char chave = 's';

    arquivo.open("a:arquivo.txt",ios::ate|ios::out|ios::in);
    
    if(arquivo.is_open()){ 
        
        do{
            li.novoAluno();
            arquivo.write((char*)&li,sizeof(aluno));
            cout << "\nInserir novo Aluno (s/n)";
            cin >> chave;
        }while(chave != 'n');
        arquivo.seekg(0);
        cout << "\nLista de alunos";
        cout << "\n==================================";
        while(arquivo.read((char*)&li,sizeof(aluno))){
            li.print();
        }
    

    } else {
        cout << "\nErro ao abrir o arquivo!\n\n";
        exit(1);
    }



   return 0;
}
