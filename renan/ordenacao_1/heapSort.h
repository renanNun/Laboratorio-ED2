

#include <iostream>

class heapSort{

public:
    heapSort(){};
    ~heapSort(){};

    void troca(int* arr, int i,int j)
    {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    void heapify(int* arr,int tam,int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < tam && arr[left] > arr[largest])
        {
            largest = left;
        }

        if(right < tam && arr[right] > arr[largest])
        {
            largest = right;
        }

        if(largest != i)
        {
            troca(arr,i,largest);


            heapify(arr,tam,largest);
        }
    };

    void buildMaxHeap(int* arr,int tam){
        int index = (tam / 2) - 1;

        for(int i = index; i >= 0; i--)
        {
            heapify(arr,tam,i);
            troca(arr,0,i);
        }
    };   

    void printHeap(int* arr,int tam)
    {
        std::cout << "Representação de Array Por Heap\n";
        
        for(int i = 0; i < tam; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout<<std::endl;
    };


};

