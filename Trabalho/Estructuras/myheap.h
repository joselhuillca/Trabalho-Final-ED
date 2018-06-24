#ifndef MYHEAP_H
#define MYHEAP_H

#include "../atendimiento.h"

#define MAX_SIZE_HEAP 100

class MyHeap
{
private:
    Atendimiento *lista;
    int tamanho;
public:
    MyHeap(){lista = new Atendimiento[MAX_SIZE_HEAP](); tamanho = 0;}
    //~myheap();

    void inserir(Atendimiento atendimiento);
    void subir(int posicao);

    void trocar(int i, int j);

    void excluir();
    void descer(int posicao);
};

void MyHeap::inserir(Atendimiento atendimiento)
{
    if(tamanho >= MAX_SIZE_HEAP){
        //resizeMyHeap();
    }else{
        lista[tamanho] = atendimiento;
        subir(tamanho);
        tamanho += 1;
    }
}

void MyHeap::subir(int posicao)
{
    int padre = (posicao-1)/2;
    if(lista[posicao].getPrioridade() > lista[padre].getPrioridade()){
        trocar(posicao, padre);
        subir(padre);
    }
}

void MyHeap::trocar(int i, int j)
{
    Atendimiento aux = lista[i];
    lista[i] = lista[j];
    lista[j] = aux;
}

void MyHeap::excluir()
{
    if(tamanho>0){
        tamanho -= 1;
        trocar(0, tamanho);
        descer(0);
    }
}

void MyHeap::descer(int posicao)
{
    int izq = 2*posicao + 1;
    int der = 2*posicao + 2;
    int j = izq;

    if(izq < tamanho){
        if(der < tamanho){
            if(lista[der].getPrioridade() > lista[izq].getPrioridade()){
                j = der;
            }
        }
        if(lista[j].getPrioridade() > lista[posicao].getPrioridade()){
            trocar(j, posicao);
            descer(j);
        }
    }
}

#endif // MYHEAP_H
