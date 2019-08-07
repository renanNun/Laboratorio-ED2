#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

class Aluno {
    public:
        int matricula;
        string nome;
        float nota1,nota2;

        Aluno(){};
        ~Aluno(){};
        void setNome(string p){this->nome = p;};
        void setMat(int p){this->matricula = p;};
        void setN1(float p){this->nota1 = p;};
        void setN2(float p){this->nota2 = p;};

        string getNome(){return this->nome;};
        int getMat(){return this->matricula;};
        float getN1(){return this->nota1;};
        float getN2(){return this->nota2;};
};

int main(){
    int a;
    string b;
    float c,d;


    string line;
    ifstream arquivo("exercicio1.txt"); //Padrão do ifstream é ser in
    if(arquivo.is_open()){
        while(!arquivo.eof()){
            getline(arquivo,line);
            cout << line << endl;
        }
        arquivo.close();
    } else{
        cout << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    }  

    int lenght;
    char *buffer;

    ifstream myFile;
    myFile.open("exercicio1.txt");

    if(myFile.open()){
        int n = 0;
        buffer = new char[lenght];
        myFile.read(buffer,lenght);

        if(lenght > 0){
            while( n < lenght){
                n++;
                if (buffer[n] == ";") buffer[n] = '\t';
            }
            cout << "Matricula: \n"; 
        }
    }

    


    return 0;

}