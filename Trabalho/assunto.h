#ifndef ASUNTO_H
#define ASUNTO_H

class TipoAssunto
{
private:
    int tipo;
    string titulo;
    int urgencia;
public:
    TipoAssunto(){}

    TipoAssunto(int tipo_, string titulo_, int urgencia_) {
        tipo = tipo_;
        titulo = titulo_;
        urgencia = urgencia_;
    }

    inline int getTipo(){return tipo;}
    inline string getTitulo(){return titulo;}
    inline int getUrgencia(){return urgencia;}

    inline void setType(int tipo_){tipo = tipo_;}
    inline void setTitle(string titulo_){titulo = titulo_;}
    inline void setUrgency(int urgencia_){urgencia = urgencia_;}
};


class Assunto
{
private:
    TipoAssunto tipo;
    string descricao;
    float *providencias;
    double duracaoAtendimento;
public:
    Assunto(){}
    Assunto(TipoAssunto tipo_, string descricao_, float *prov=0, double durationA=0) {
        tipo = tipo_;
        descricao = descricao_;
        providencias = prov;
        duracaoAtendimento = durationA;
    }

    inline string getDescricao(){return descricao;}
    inline double getDuracaoAtendimento(){return duracaoAtendimento;}
    inline float* getProvidencias(){return providencias;}
    inline TipoAssunto getTipo(){return tipo;}

    inline void setDescricao(string d){descricao = d;}
    inline void setDuracaoAtendimento(double da){duracaoAtendimento = da;}
    inline void setProvidencias(float *prov){providencias = prov;}
};

#endif // ASUNTO_H