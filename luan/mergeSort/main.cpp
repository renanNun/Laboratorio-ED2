#include <iostream>
#include "mergeSort.h"

using namespace std;

int main()
{

    int vet[10] = {10, 56, 2, 59, 23, 1, 68, 26, 3, 88};
    int numregistros = 10;

    
    mergeSort(vet, 0, numregistros-1);

    for (int i = 0; i < numregistros; i++)
    {
        cout << vet[i] << endl;
    }
}
