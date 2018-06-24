#ifndef SERVICIOATENDIMIENTO_H
#define SERVICIOATENDIMIENTO_H

#include "atendimiento.h"
#include "Estructuras/myheap.h"
#include "Estructuras/mylist.h"
#include <vector>
#include <iostream>
using namespace std;

class servicioAtendimiento
{
  private:


  public:
    vector<TipoAsunto> listaTipoAsunto;
    //vector<Asunto> listaAsunto;
    MyList<Asunto> listaAsunto;
    MyHeap heap_estructura;

    servicioAtendimiento();
    //myheap recepcionar(Atendimiento);
};

#endif // SERVICIOATENDIMIENTO_H
