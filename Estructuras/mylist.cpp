#include <iostream>
#include "mylist.h"

using namespace std;

void list::insert(int x){
  node *new_node = new node;
  new_node->cont = x;
  new_node->p_next = NULL;

  if(p_start == NULL){
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

void list::remove_(int x){
  if(p_start != NULL){
    node *p_node = p_start;
    node *p_temp;
    while (p_node != NULL) {
      if(p_node->cont == x){
        p_temp->p_next = p_node->p_next;
        p_node = p_node->p_next;
      }
      else{
        p_temp = p_node;
        p_node = p_node->p_next;
      }
    }
  }
  else
    cout<<"Lista vacia"<<endl;
}

void list::print(){
  if(p_start != NULL){
    cout<<"lista: ";
    node *p_node = p_start;
    while (p_node != NULL) {
      cout<<p_node->cont<<" ";
      p_node = p_node->p_next;
    }
    cout<<endl;
  }
  else
    cout<<"Lista vacia"<<endl;
}
