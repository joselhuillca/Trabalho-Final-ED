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
//    vector<TipoAsunto> listaTipoAsunto;
    // myList lista_simpla;
    // myheap heap_estructura;

public:
    vector<TipoAsunto> listaTipoAsunto;
    //vector<Asunto> listaAsunto;
    myList<Asunto> listaAsunto;
    myheap heap_estructura;

    servicioAtendimiento();
    //myheap recepcionar(Atendimiento);
};

#endif // SERVICIOATENDIMIENTO_H
