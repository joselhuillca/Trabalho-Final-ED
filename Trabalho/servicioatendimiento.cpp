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
    urgenciaRand = rand() % GRAU_URGENCIA + 1;
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
  heapAtendimento.inserir(Objeto_Atendimento);
}

MyList<Assunto> servicioAtendimento::gerarListaAssunto(int cantidade)
{
  MyList<Assunto> lista_Assunto;
  for(int i=0; i<cantidade; i++){
    ostringstream str1;
    str1<<i+1;
    tipoAssuntoRand = rand() % MAX_SIZE_LIST + 1;
    Assunto Objecto_Assunto(listaTipoAssunto[tipoAssuntoRand], "testDescripcion "+str1.str());
    lista_Assunto.inserir(Objecto_Assunto);
  }
  return lista_Assunto;
}

int main(){
  servicioAtendimento Objeto_SA;
  MyList<Assunto> lista_Assuntos;
  // Create Cliente
  int cpf = 064;
  string nome = "Jordan";
  int edade = 26;
  Cliente cliente(cpf, nome, edade);
  // Create lista_Assuntos
  lista_Assuntos = Objeto_SA.gerarListaAssunto(3);

  // **** 1° funcao recepcionar
  Objeto_SA.recepcionar(cliente, lista_Assuntos);

  return 0;
}
