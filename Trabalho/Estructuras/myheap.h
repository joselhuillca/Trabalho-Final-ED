#ifndef MYHEAP_H
#define MYHEAP_H

#include "../atendimiento.h"

#define MAX_SIZE_HEAP 100

class myheap
{
private:
    Atendimiento *lista;
    int size;
public:
    myheap(){lista = new Atendimiento[MAX_SIZE_HEAP](); size = 0;}
    //~myheap();

    void insertar(Atendimiento atendimiento);
    void subir(int position);

    void trocar(int i, int j);

    void excluir();
    void descer(int position);
};

void myheap::insertar(Atendimiento atendimiento)
{
    if(size >= MAX_SIZE_HEAP){
        //resizeMyHeap();
    }else{
        lista[size] = atendimiento;
        subir(size);
        size += 1;
    }
}

void myheap::subir(int position)
{
    int padre = (position-1)/2;
    if(lista[position].getPrioridade() > lista[padre].getPrioridade()){
        trocar(position, padre);
        subir(padre);
    }
}

void myheap::trocar(int i, int j)
{
    Atendimiento aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}

void myheap::excluir()
{
    if(size>0){
        size -= 1;
        trocar(0, size);
        descer(0);
    }
}

void myheap::descer(int position)
{
    int izq = 2*position + 1;
    int der = 2*position + 2;
    int j = izq;

    if(izq < size){
        if(der < size){
            if(lista[der].getPrioridade() > lista[izq].getPrioridade()){
                j = der;
            }
        }
        if(lista[j].getPrioridade() > lista[position].getPrioridade()){
            trocar(j, position);
            descer(j);
        }
    }
}

#endif // MYHEAP_H
