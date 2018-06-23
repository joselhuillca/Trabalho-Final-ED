#include <iostream>
#include "mylist.h"

using namespace std;

void myList::myInsert(int dato){
    cout<<dato<<endl;
    /*node *new_node = new node;
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
    }*/
}

void myList::remove_(int dato){
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

void myList::myprint(){
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
