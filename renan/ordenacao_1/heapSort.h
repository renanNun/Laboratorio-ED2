

#include <iostream>

class heapSort{

public:
    heapSort(){};
    ~heapSort(){};

    void ordena(int* vet, int n){
        for(int i = n - 1; i > 1; i--){
            maxHeapfy(vet,i);
            troca(vet,0,i);
        }
    };

    void maxHeapfy(int* vet, int fim){
        int p = (int) fim/2 - 1;
        bool chave = true;

        while(p > -1){
            int pai = vet[p];
            int filho1 = vet[2*p];
            int filho2 = vet[2*p+1];

            if(2*p+1 >= fim)
                chave = false;

            if(filho1 < filho2 && chave){
                if( pai < filho2){
                    troca(vet,p,2*p+1);
                }
            } else {
                if(pai < filho1)
                {
                    troca(vet,p,2*p);
                }
            }
            p--;
        }   
    };

    void troca(int* vetor, int i, int j){
        int t = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = t;
    };

};

