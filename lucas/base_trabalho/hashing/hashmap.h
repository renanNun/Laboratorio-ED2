/**
    Universidade Federal de Juiz de Fora
    BubbleSort.h
    Propósito: Implementação do algoritmo BubbleSort.

    @author Lucas Ribeiro Pessamilio
    @version 1.0 04/09/19
*/

#ifndef BASE_TRABALHO_HASHMAP_H
#define BASE_TRABALHO_HASHMAP_H

#include <iostream>
#include <UserReview.h>

using namespace std;

class hashmap {

public:
    hashmap(UserReview* vetor, int tam) {
        newHashMap = new UserReview[tam];
        for(int i = 0; i<tam; i++){
            newHashMap[i] = UserReview();
            newHashMap[i].id = -1;
        }
        for(int i = 0; i<tam; i++){
            int hashNumero = hasher(vetor[i].id,vetor[i].user, tam);
            cout << "ID: "<<vetor[i].id << endl;
            cout << "Resultado Hash: " << hashNumero << endl;
            if(newHashMap[hashNumero].id == -1){
                newHashMap[hashNumero] = vetor[i];
                cout << "Posição Colocada: " <<hashNumero << endl;
            } else {
                hashNumero++;
                while(newHashMap[hashNumero].id != -1){
                    if(hashNumero == tam){
                        hashNumero = 0;
                    }
                    hashNumero++;
                }
                newHashMap[hashNumero] = vetor[i];
            }
        }
    };

    ~hashmap() {};

private:
    UserReview* newHashMap;
    int hasher(int id, string nome, int tam){
        int total = 0;
        for(int i = 0; i<nome.length(); i++){
            total = total + int(nome.at(i));
        }
        return (total*id)%tam;
    };
};


#endif //BASE_TRABALHO_HASHMAP_H
