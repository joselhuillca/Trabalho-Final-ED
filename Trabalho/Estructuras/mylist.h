#ifndef MYLIST_H
#define MYLIST_H


class myList{
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
    int size;

  public:
    myList(){p_start=0;p_insert=0;size=0;}
    void myInsert(int dato);
    void remove_(int dato);
    void myprint();
};


#endif
