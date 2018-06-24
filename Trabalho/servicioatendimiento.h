#ifndef SERVICIOATENDIMIENTO_H
#define SERVICIOATENDIMIENTO_H

#include "atendimento.h"
#include "Estructuras/myheap.h"
#include "Estructuras/mylist.h"
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <iostream>
using namespace std;

#define MAX_SIZE_LIST 20
#define GRAU_URGENCIA 10

class servicioAtendimiento
{
  private:
    TipoAssunto *listaTipoAssunto;

  public:
    //vector<TipoAssunto> listaTipoAsunto;
    //vector<Asunto> listaAsunto;
    MyList<Assunto> listaAsunto;
    MyHeap heap_estructura;

    servicioAtendimiento();
    void imprimirListaTipoAtendimento();
    //myheap recepcionar(Atendimiento);
};

#endif // SERVICIOATENDIMIENTO_H
