#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

using namespace std;

template<typename T>
class myList{
private:
    struct node{
      T cont;
      node *p_next;
      ~node(){
        if(p_next)
          delete[] p_next;
      }
    };
private:
    int size;
    node *p_start;
    node *p_insert;

public:
    myList(){p_start=0;p_insert=0;size=0;}
    void insert(T dato);
    void remove_(T dato);
    void myprint();

    inline int getSize(){return size;}

    float mediaUrgencias();
};

/** ------------------ FUNCTIONS ------------------------ **/
template<typename T>
void myList<T>::insert(T dato){
    node *new_node = new node;
    new_node->cont = dato;
    new_node->p_next = 0;

    if(p_start == 0){
        p_start = new_node;
        p_insert = new_node;
        size += 1;
    }
    else{
        p_insert->p_next = new_node;
        p_insert = p_insert->p_next;
        size += 1;
    }
}

template<typename T>
void myList<T>::remove_(T dato){
  if(p_start != 0){
    node *p_node = p_start;
    node *p_temp;
    while (p_node != 0) {
      if(p_node->cont == dato){
        p_temp->p_next = p_node->p_next;
        p_node = p_node->p_next;
      }
      else{
        p_temp = p_node;
        p_node = p_node->p_next;
      }
    }
  }
  else{
    cout<<"Lista vacia"<<endl;
  }
}

template<typename T>
void myList<T>::myprint(){
  if(p_start != 0){
    cout<<"lista: ";
    node *p_node = p_start;
    while (p_node != 0) {
      cout<<p_node->cont<<" ";
      p_node = p_node->p_next;
    }
    cout<<endl;
  }
  else{
    cout<<"Lista vacia"<<endl;
  }
}

template<typename T>
float myList<T>::mediaUrgencias(){
    int aux = 0;
    node *p_node = p_start;
    for (int i=0; i<size; i++) {
        aux += p_node->cont.getType().getUrgency();
    }
    return aux/size*1.0;
}

#endif
