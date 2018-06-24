#ifndef ATENDIMIENTO_H
#define ATENDIMIENTO_H

#include "cliente.h"
#include "assunto.h"
#include "Estructuras/mylist.h"

class Atendimento
{
private:
    Cliente cliente;
    MyList<Assunto> assuntos;
    double horaChegada;
    double horaAtendimento;
    float prioridade;
public:
    Atendimento(){}
    Atendimento(Cliente cliente_, myList<Assunto> assuntos_, double horaChegada_) {
        cliente = cliente_;
        assuntos = assuntos_;
        horaChegada = horaChegada_;
        horaAtendimento = 0;
    }

    inline Cliente getCliente(){return cliente;}
    inline myList<Assunto> getAssunto(){return assuntos;}
    inline double getHoraChegada(){return horaChegada;}
    inline double getHoraAtendimento(){return horaAtendimento;}
    inline float getPrioridade(){return prioridade;}

    inline void setHoraChegada(double horaChegada_){horaChegada = horaChegada_;}
    inline void setHoraAtendimento(int horaAtendimento_){horaAtendimento = horaAtendimento_;}

    // Tiempo de espera esta en MINUTOS
    void calcularPrioridade(){
        float edade_media = cliente.getAge()/65.0;
        float espera_media = (horaAtendimento-horaChegada)/15.0;
        float assuntos_media = assuntos.mediaUrgencias();

        prioridade = (edade_media+espera_media+assuntos_media)/3.0;
    }
};

#endif // ATENDIMIENTO_H
