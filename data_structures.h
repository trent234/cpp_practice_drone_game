//trent wilson
//doubly linked list
//2019_04_22


#ifndef DLL_H
#define DLL_H

#include "interavtive_objects.h"

class node{
  public:
    node();
    interactive_obj*& get_obj(); 
    void set_obj(interactive_obj** in);
    node* get_next();
    void set_next(node* in);

  private:
    interactive_obj** containing_obj;
    node* next;
};

class lll{
  
  public:
    lll(); 
    int traverse();
    int prepend(node* in);

  private:
    node* head;
//    node* tail;
  
    int traverse(node* head);
};

class graph{

  public:
    graph();
    //void read_in_course();
    void build_list(lll& adjacency_list, int* connecting_nodes);
    void read_in_course(char* in_file);
    interactive_obj* create_interactive_obj(char in);

   //this is probs temporary
    void traverse(); 
  private:
    int adjacency_list_length;
    lll* adjacency_list;
    interactive_obj** graph_arr;

};

#endif //DLL_H
