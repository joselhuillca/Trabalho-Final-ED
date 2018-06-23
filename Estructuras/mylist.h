#ifndef MYLIST_H
#define MYLIST_H

class list{
  private:
    struct node{
      int cont;
      node *p_next;
      ~node(){
        if(p_next)
          delete[] p_next;
      }
    };
    node *p_start;
    node *p_insert;
    node *p_remove;
    int size;

  public:
    list(){p_start=NULL;size=0;}
    void insert(int);
    void remove_(int);
    void print();
};

#endif
