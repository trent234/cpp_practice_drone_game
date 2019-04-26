//trent wilson
//doubly linked list
//2019_04_22


#ifndef DLL_H
#define DLL_H

#include "node.h"

class dll{
  
  public:
    dll(); 
    int traverse();
    int prepend(node* in);

  private:
    node* head;
    node* tail;
  
    int traverse(node* head);
};

class graph{

  public:
    graph();
    void read_in_course();
    void read_in_course(char* in_file);
    node* create_node_obj(char in);

   //this is probs temporary
    void traverse(); 

  private:
    int adjacency_list_length;
    dll** adjacency_list;
    dll* obj_arr 
};

#endif //DLL_H
