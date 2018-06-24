#ifndef ATENDIMIENTO_H
#define ATENDIMIENTO_H

#include "cliente.h"
#include "asunto.h"
#include "Estructuras/mylist.h"

class Atendimiento
{
private:
    Cliente cliente;
    myList<Asunto> asuntos;
    double horaLlegada;
    double horaAtendimiento;
    float prioridade;
public:
    Atendimiento(){}
    Atendimiento(Cliente cliente_, myList<Asunto> asuntos_, double horaLlegada_) {
        cliente = cliente_;
        asuntos = asuntos_;
        horaLlegada = horaLlegada_;
        horaAtendimiento = 0;
    }

    inline Cliente getCliente(){return cliente;}
    inline myList<Asunto> getAsunto(){return asuntos;}
    inline double getHoraLlegada(){return horaLlegada;}
    inline double getHoraAtendimiento(){return horaAtendimiento;}
    inline float getPrioridade(){return prioridade;}

    inline void setHoraLlegada(double horaLlegada_){horaLlegada = horaLlegada_;}
    inline void setHoraAtendimiento(int horaAtendimiento_){horaAtendimiento = horaAtendimiento_;}

    // Tiempo de espera esta en MINUTOS
    void calcularPrioridade(){
        float edad_media = cliente.getAge()/65.0;
        float espera_media = (horaAtendimiento-horaLlegada)/15.0;
        float asuntos_media = 0;
        Asunto *asuntoList = asuntos.toList();
        for (int i=0; i < asuntos.getSize(); i++) {
          asuntos_media += asuntoList[i].getType().getUrgency();
        }
        asuntos_media = asuntos_media/asuntos.getSize()*1.0;

        prioridade = (edad_media+espera_media+asuntos_media)/3.0;
    }
};

#endif // ATENDIMIENTO_H
