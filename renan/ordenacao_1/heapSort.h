

#include <iostream>

class heapSort{

public:
    heapSort(){};
    ~heapSort(){};
    
    //Está versão apresenta falha de segmentação
    /*
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

    void troca(int* vetor, int i, int j){
        int t = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = t;
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
    */

   //Segunda Versão

    //Essa copia da internet não ordena, mas também não faz muita coisa.
    /*
    void MaxHeapify(int* vet, int i, int n)
    {
	    int j, temp;
	    temp = vet[i];
	    j = 2*i;
 
     	while (j <= n)
	    {
		    if (j < n && vet[j+1] > vet[j])
		    j = j+1;
		    // Break if parent value is already greater than child value.
		    if (temp > vet[j])
			    break;
		    // Switching value with the parent node if temp < a[j].
		    else if (temp <= vet[j])
		    {
			    vet[j/2] = vet[j];
		    	j = 2*j;
		    }
	    }
	    vet[j/2] = temp;
	    return;
    }

    void ordena(int* vet, int n)
    {
	    int i, temp;
	    for (i = n; i >= 2; i--)
	    {
	    	// Storing maximum value at the end.
	    	temp = vet[i];
	    	vet[i] = vet[1];
	    	vet[1] = temp;
	    	// Building max heap of remaining element.
	    	MaxHeapify(vet, 1, i - 1);
	    }
    }

    void Build_MaxHeap(int* vet, int n)
    {
    	int i;
    	for(i = n/2; i >= 1; i--)
    		MaxHeapify(vet, i, n);
    }
    */

};

