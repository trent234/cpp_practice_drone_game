//trent wilson
//doubly linked list
//2019_04_22


#ifndef DLL_H
#define DLL_H

#include "interactive_objects.h"

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
    
    int announce_neighbors();
    int prepend(node* in);

  private:
    node* head;
  
    int announce_neighbors(node* head, int count);
};

class graph{

  public:
    graph();
    void read_in_course();
    void build_list(lll& individ_adj_list, int* connecting_nodes, int count);
    interactive_obj* create_interactive_obj(char in);

    void traverse(int start_index); 
  private:
    int adjacency_list_length;
    lll* adjacency_list;
    interactive_obj** graph_arr;
};

#endif //DLL_H
