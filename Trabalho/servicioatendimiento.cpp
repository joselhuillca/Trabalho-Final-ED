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

void servicioAtendimento::encerrar(Atendimento &atendimento)
{
    time_t tempoProvidencias;

    int num_assuntos = atendimento.getAssuntos().getTamanho();
    string aux_providencia;
    double horaInicio = atendimento.getHoraAtendimento();

    ostringstream str0;
    str0<<num_assuntos;
    cout<<"providências tomadas para atender as "<< str0.str() <<" demandas dos clientes:"<<endl;
    for(int i=0; i<num_assuntos; i++){
        ostringstream str1;
        str1<<i+1;
        cout<<"Asunto" + str1.str()<<" - Providencias:";
        cin>>aux_providencia;

        atendimento.getAssuntos().get(i).setProvidencias(aux_providencia);
        time(&tempoProvidencias);
        double duracaoAtendimento = tempoProvidencias-horaInicio;
        atendimento.getAssuntos().get(i).setDuracaoAtendimento(duracaoAtendimento);
        horaInicio += duracaoAtendimento;
    }

    listaEncerrar.inserir(atendimento);
}

void servicioAtendimento::gerarEstatística()
{
    cout<<"Gerando estatísticas da minha listaEncerrar:"<<endl;

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
