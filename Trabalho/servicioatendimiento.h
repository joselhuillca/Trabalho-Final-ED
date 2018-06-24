#ifndef SERVICIOATENDIMIENTO_H
#define SERVICIOATENDIMIENTO_H

#include "atendimento.h"
#include "Estructuras/myheap.h"
#include "Estructuras/mylist.h"
#include <vector>
#include <iostream>
using namespace std;

class servicioAtendimiento
{
  private:


  public:
    vector<TipoAssunto> listaTipoAsunto;
    //vector<Asunto> listaAsunto;
    MyList<Assunto> listaAsunto;
    MyHeap heap_estructura;

    servicioAtendimiento();
    //myheap recepcionar(Atendimiento);
};

#endif // SERVICIOATENDIMIENTO_H
