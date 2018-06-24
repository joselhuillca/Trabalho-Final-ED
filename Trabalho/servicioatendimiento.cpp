#include "servicioatendimiento.h"

servicioAtendimento::servicioAtendimento()
{
  // Random
  srand (time(NULL));

  // Create list listaTipoAssunto
  listaTipoAssunto = new TipoAssunto[MAX_SIZE_LIST];
  for(int i=0; i<MAX_SIZE_LIST; i++){
    ostringstream str1;
    str1<<i+1;
    int urgenciaRand = rand() % GRAU_URGENCIA + 1;
    TipoAssunto tipoAsuntoTemporal(i+1, "Asunto "+str1.str(), urgenciaRand);
    listaTipoAssunto[i] = tipoAsuntoTemporal;
  }
}

void servicioAtendimento::imprimirListaTipoAtendimento()
{
  for(int i=0; i<MAX_SIZE_LIST; i++){
    cout<<"Tipo Assunto: "<<listaTipoAssunto[i].getTitulo()<<
          " // urgencia: "<<listaTipoAssunto[i].getUrgencia()<<endl;
  }
  cout<<endl;
}

void servicioAtendimento::encerrar()
{
    time_t tempoEncerrar;
    time(&tempoEncerrar);
    Atendimento atendimentoEncerrar = heapAtendimento.excluir();
    atendimentoEncerrar.getAssuntos().setDuracaoAtendimento(atendimentoEncerrar.getHoraAtendimento(), tempoEncerrar);

    listaEncerrar.inserir(atendimentoEncerrar);
}

void servicioAtendimento::recepcionar(Cliente cliente_, MyList<Assunto> listaAssunto_)
{
  time_t tempoAgora;
  time(&tempoAgora);

  Atendimento Objeto_Atendimento(cliente_, listaAssunto_, tempoAgora);
  listaAtendimento.inserir(Objeto_Atendimento);
  // heapAtendimento.inserir(Objeto_Atendimento);
}

MyList<Assunto> servicioAtendimento::gerarListaAssunto(int cantidade)
{
  MyList<Assunto> lista_Assunto;
  for(int i=0; i<cantidade; i++){
    ostringstream str1;
    str1<<i+1;
    int tipoAssuntoRand = rand() % MAX_SIZE_LIST + 1;
    Assunto Objecto_Assunto(listaTipoAssunto[tipoAssuntoRand], "testDescripcion "+str1.str());
    lista_Assunto.inserir(Objecto_Assunto);
  }
  return lista_Assunto;
}

Atendimento servicioAtendimento::atender()
{
  time_t tempoAgora;
  time(&tempoAgora);
  // Create Heap
  int tamanhoLista = listaAtendimento.getTamanho();
  for(int i=0; i<tamanhoLista; i++){
    Atendimento Objecto_Atendimento = listaAtendimento.get(i);
    Objecto_Atendimento.setHoraAtendimento(tempoAgora);
    heapAtendimento.inserir(Objecto_Atendimento);
  }

  // Get max prioridade
  Atendimento atendimentoAtender = heapAtendimento.excluir();
  return atendimentoAtender;
}


int main(){
  servicioAtendimento Objeto_SA;

  // **** 1° funcao recepcionar
  Objeto_SA.recepcionar(Cliente(64, "Jordan"), Objeto_SA.gerarListaAssunto(3));
  Objeto_SA.recepcionar(Cliente(65, "Luis"), Objeto_SA.gerarListaAssunto(2));
  //Objeto_SA.mostrarHeapAtenimento();

  // **** 2° funcao atender()
  Atendimento Objeto_Atendimento = Objeto_SA.atender();

  cout<<"Termino todo"<<endl;
  return 0;
}
