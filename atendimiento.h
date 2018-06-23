#ifndef ATENDIMIENTO_H
#define ATENDIMIENTO_H

#include "cliente.h"
#include "asunto.h"

class Atendimiento
{
private:
    Cliente cliente;
    Asunto *asuntos;
    double horaLlegada;
    double horaAtendimiento;
    float prioridade;
public:
    Atendimiento(Cliente cliente_, Asunto *asuntos_, double horaLlegada_) {
        cliente = cliente_;
        asuntos = asuntos_;
        horaLlegada = horaLlegada_;
        horaAtendimiento = 0;
    }

    inline Cliente getCliente(){return cliente;}
    inline Asunto* getAsunto(){return asuntos;}
    inline double getHoraLlegada(){return horaLlegada;}
    inline double getHoraAtendimiento(){return horaAtendimiento;}
    inline float getPrioridade(){return prioridade;}

    inline void setHoraLlegada(double horaLlegada_){horaLlegada = horaLlegada_;}
    inline void setHoraAtendimiento(int horaAtendimiento_){horaAtendimiento = horaAtendimiento_;}
};

#endif // ATENDIMIENTO_H
