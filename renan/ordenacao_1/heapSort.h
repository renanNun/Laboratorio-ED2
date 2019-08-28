

#include <iostream>

class heapSort{

public:
    heapSort(){};
    ~heapSort(){};

    void heapify(int* vetor,int n,int i){
        int maior = i;
        int l = 2*i + 1;
        int r = 2*i +2;

        if(l < n && vetor[l] > vetor[maior]){
            maior = l;
        }

        if(r < n && vetor[r] > vetor[maior]){
            maior = r;
        }

        if(maior != i){
            troca(vetor,i,maior);
        }

        heapify(vetor, n, maior);
    };


    void ordena(int* vetor,int n){
        for(int i = (n / 2) - 1; i >= 0; i--){
            heapify(vetor,n,i);
        }

        for(int i = n -1; i >= 0; i--){
            troca(vetor,0,i);

            heapify(vetor,i,0);
        }
    };

    void troca(int* vetor, int i, int j){
        int t = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = t;
    };

    void printArray(int arr[], int n) 
    { 
    for (int i=0; i<n; ++i) 
        std::cout << arr[i] << " "; 
    std::cout << "\n"; 
    } 


};

