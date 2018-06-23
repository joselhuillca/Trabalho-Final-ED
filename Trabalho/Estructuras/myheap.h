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
    myheap();
    //~myheap();

    void insertar(Atendimiento atendimiento);
    void subir(int position);

    void trocar(int i, int j);

    void excluir();
    void descer(int position);
};

#endif // MYHEAP_H
