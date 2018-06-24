#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;

class Cliente
{
private:
    int cpf;
    string nome;
    int idade;
public:
    Cliente(){}
    Cliente(int cpf_, string nome_, int idade_) {
        cpf = cpf_;
        nome = nome_;
        idade = idade_;
    }
    inline int getCpf(){return cpf;}
    inline string getNome(){return nome;}
    inline int getIdade(){return idade;}

    inline void setCpf(int cpf_){cpf = cpf_;}
    inline void setNome(string nome_){nome = nome_;}
    inline void setIdade(int idade_){idade = idade_;}
};

#endif // CLIENTE_H
