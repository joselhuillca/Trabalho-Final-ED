#include "servicioatendimiento.h"

servicioAtendimiento::servicioAtendimiento()
{
  // Random
  int urgenciaRand;
  srand (time(NULL));
  urgenciaRand = rand() % GRAU_URGENCIA + 1;

  // Create list
  listaTipoAssunto = new TipoAssunto[MAX_SIZE_LIST];
  for(int i=0; i<MAX_SIZE_LIST; i++){
    ostringstream str1;
    str1<<i+1;
    TipoAssunto tipoAsuntoTemporal(i+1, "Asunto "+str1.str(), urgenciaRand);
    listaTipoAssunto[i] = tipoAsuntoTemporal;
  }
}

void servicioAtendimiento::imprimirListaTipoAtendimento()
{
  for(int i=0; i<MAX_SIZE_LIST; i++){
    cout<<"Tipo Assunto: "<< listaTipoAssunto[i].getTitulo()<<endl;
  }
  cout<<endl;
}

void servicioAtendimiento::encerrar()
{
    time_t tempoEncerrar;
    time(&tempoEncerrar);
    Atendimento atendimentoEncerrar = heapAtendimento.excluir();
    atendimentoEncerrar.getAssuntos().setDuracaoAtendimento(atendimentoEncerrar.getHoraAtendimento(), tempoEncerrar);

    listaEncerrar.inserir(atendimentoEncerrar);
}

/*
int main(){
  servicioAtendimiento Objeto_SA;
  // Objeto_SA.imprimirListaTipoAtendimento();
  return 0;
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
  Assunto asunto01(sa.listaTipoAssunto[0], "testDescripcion01");
  Assunto asunto02(sa.listaTipoAssunto[1], "testDescripcion02");
  Assunto asunto03(sa.listaTipoAssunto[2], "testDescripcion03");
  Assunto asunto04(sa.listaTipoAssunto[3], "testDescripcion04");
  sa.listaAsunto.insert(asunto01);
  sa.listaAsunto.insert(asunto02);
  sa.listaAsunto.insert(asunto03);
  sa.listaAsunto.insert(asunto04);

  //Atendimiento
  Atendimento atendimiento(cliente, sa.listaAsunto, 0);

  sa.heap_estructura.inserir(atendimiento);

  cout<<"tam: "<<sa.listaTipoAssunto[0].getTitulo()<<endl;
}*/
