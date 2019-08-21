#ifdef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

#include <iostream>
#include <vector>

class Ordenacao{

    public:
        Ordenacao(){}; //Construtor
        ~Ordenacao(){}; //Destrutor

        static int particiona(int []lista,int p, int r){
            int i,j;
            int [] aux;

            aux = lista[r];
            i = p-1;
            j = r;

            for(;;){
                while();
                while();
                    if(j == p) break;
                    //exch(lista[i],lista[j])
            }
            //excha(lista[i],lista[j])
            return i;
        };

        int quickSort(int []lista,int p,int r){ 
            //Sobre o quickSort, lembrar caso seja tamanho 1, não pode se chamar o QuickSort
            int i;
            
            if(r <= p)
                return;
            
            i = particiona(lista,l,r);
            quickSort(lista, l, i+1);
            quickSort(lista, i + 1, r);

        };

};

#endif //ORDENACAO_H_INCLUDED