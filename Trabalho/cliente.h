#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;

class Cliente
{
private:
    int cpf;
    string name;
    int age;
public:
    Cliente(){}
    Cliente(int cpf_, string name_, int age_) {
        cpf = cpf_;
        name = name_;
        age = age_;
    }
    inline int getCpf(){return cpf;}
    inline string getName(){return name;}
    inline int getAge(){return age;}

    inline void setCpf(int cpf_){cpf = cpf_;}
    inline void setName(string name_){name = name_;}
    inline void setAge(int age_){age = age_;}
};

#endif // CLIENTE_H
