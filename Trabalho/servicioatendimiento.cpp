#include "servicioatendimiento.h"

servicioAtendimiento::servicioAtendimiento()
{
  TipoAsunto tipoAsunto01(1, "Asunto01", 1);
  TipoAsunto tipoAsunto02(2, "Asunto02", 2);
  TipoAsunto tipoAsunto03(3, "Asunto03", 3);
  TipoAsunto tipoAsunto04(4, "Asunto04", 4);
  TipoAsunto tipoAsunto05(5, "Asunto05", 5);
  listaTipoAsunto.push_back(tipoAsunto01);
  listaTipoAsunto.push_back(tipoAsunto02);
  listaTipoAsunto.push_back(tipoAsunto03);
  listaTipoAsunto.push_back(tipoAsunto04);
  listaTipoAsunto.push_back(tipoAsunto05);
}

// ----------------------------------------------------------------------
int main(){
  servicioAtendimiento sa;
  // Cliente
  int cpf = 064;
  string nome = "Jordan";
  int edade = 26;
  Cliente cliente(cpf, nome, edade);

  //Asunto
  Asunto asunto01(sa.listaTipoAsunto[0], "testDescripcion01");
  Asunto asunto02(sa.listaTipoAsunto[1], "testDescripcion02");
  Asunto asunto03(sa.listaTipoAsunto[2], "testDescripcion03");
  Asunto asunto04(sa.listaTipoAsunto[3], "testDescripcion04");
  sa.listaAsunto.insert(asunto01);
  sa.listaAsunto.insert(asunto02);
  sa.listaAsunto.insert(asunto03);
  sa.listaAsunto.insert(asunto04);

  //Atendimiento
  Atendimiento atendimiento(cliente, sa.listaAsunto, 0);

  sa.heap_estructura.insertar(atendimiento);

  cout<<"tam: "<<sa.listaTipoAsunto[0].getTitle()<<endl;
}
