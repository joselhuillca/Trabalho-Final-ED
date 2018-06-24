#ifndef SERVICIOATENDIMIENTO_H
#define SERVICIOATENDIMIENTO_H

#include "atendimento.h"
#include "Estructuras/myheap.h"
#include "Estructuras/mylist.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <string>
// #include <iostream>
// using namespace std;

#define MAX_SIZE_LIST 20
#define GRAU_URGENCIA 10

class servicioAtendimento
{
  private:
    int urgenciaRand;
    int tipoAssuntoRand;
    TipoAssunto *listaTipoAssunto;
    MyList<Atendimento> listaEncerrar;
    MyHeap heapAtendimento;

  public:
    MyList<Assunto> listaAsunto;

    servicioAtendimento();
    void imprimirListaTipoAtendimento();
    void recepcionar(Cliente, MyList<Assunto>);
    void encerrar();
    MyList<Assunto> gerarListaAssunto(int);
};

#endif // SERVICIOATENDIMIENTO_H
