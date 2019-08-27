#ifndef ORDENACAPARIMPAR_H_INCLUDED
#define ORDENACAPARIMPAR_H_INCLUDED

class ParImpar{

private:

public:
    ParImpar(){};
    ~ParImpar(){};

    void ordenar(int *x,int tam){
        for(int i = 0; i < tam; i++)
        {
            if((i%2) != 0)
            {
                if(x[i] > x[i+1]){
                    int aux = x[i];
                    x[i] = x[i+1];
                    x[i+1] = aux;

                }
            }
        }

        for(int i = 0; i < tam; i++){
            if((i%2) == 0){
               if(x[i] > x[i+1]){
                    int aux = x[i];
                    x[i] = x[i+1];
                    x[i+1] = aux;

                }
            }
        }
    };

};


#endif //ORDENACAOPARIMPAR_H_INCLUDED