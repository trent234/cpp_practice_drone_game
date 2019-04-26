

#include "data_structures.h"
#include <fstream>
#include <iostream>

//*****node

node::node():containing_obj(nullptr), next(nullptr)
{}

interactive_obj*& node::get_obj(){
  return *containing_obj;
} 

void node::set_obj(interactive_obj** in){
  containing_obj = in; 
}

node* node::get_next(){
  return next;
}

void node::set_next(node* in){
  next = in;
}

//*****lll

lll::lll()
{}

int lll::traverse(){
  traverse(head);
  return 0;
}
//recurisve traversal!
int lll::traverse(node* head){
  if(head == nullptr) return 0;  
  (head->get_obj())->action();
  traverse(head->get_next());
  return 0; 
}

int lll::prepend(node* in){
  if(in == nullptr) return 1; 
  in->set_next(head);
  head = in;
  return 0;
}

//*****graph

graph::graph(){

  adjacency_list = nullptr;

}

//recursive solution
void graph::build_list(lll& adjacency_list, int* connecting_nodes){
  if(connecting_nodes == nullptr) return;
  adjacency_list.prepend(*connecting_nodes);
  build_list(adjacency_list&, connecting_nodes + 1);
  return; 
}

void graph::read_in_course(char* in_file){

//stock course layout. ideally would input in from text file for multiple levels. thats later. 
adjacency_list_length = 11;

adjacency_list = new lll[adjacency_list_length];
graph_arr = new interactive_obj*[adjacency_list_length];
graph_arr[0] = create_interactive_obj('D');
graph_arr[5] = create_interactive_obj('L');
graph_arr[11] = create_interactive_obj('F');
graph_arr[12] = create_interactive_obj('B');
graph_arr[13] = create_interactive_obj('B');

//figure out a nice way to get a string of ints into the build list, and create 
//the map i have drawn out

//then make the action function for each object
//then make a turn function in main that lets the user pick a direction 
//and then runs through all other objects actions. if connect with finish line
//check that loop requirement is met. if so finish congrats!

node* node1 = new node;
//node points to ref of array index because we point to arr index not what index is pting to
node1->set_obj(&graph_arr[0]);
adjacency_list[0].prepend(node1);

node* node2 = new node;
node2->set_obj(&graph_arr[1]);
adjacency_list[1].prepend(node2);



/*
  char read_in[9];
  char c = '\0';
  std::fstream fs;
  fs.open(in_file, std::fstream::in);
  if(!fs.is_open()) {
    fprintf(stdout, "Error opening map file.\n");
  }
  else{ 
    fs.getline(read_in, 9);
    adjacency_list_length = atoi(read_in);
    adjacency_list = new lll[adjacency_list_length];
    for(int y = 0; y < adjacency_list_length; y++){
      c = '0';
      while(c != '\n'){
        fs.get(c);
        adjacency_list[y].prepend(create_node_obj(c));
      } 
    }
    fs.close();
    }
*/
}

interactive_obj* graph::create_interactive_obj(char in){
  interactive_obj* new_obj = nullptr;
  switch(in){
    case('D'):
      new_obj = new drone;
      break;
    case('B'):
      new_obj = new black_hole;
      break;
    case('F'):
      new_obj = new finish; 
      break;
    case('L'):
      new_obj = new loop;
  }
  return new_obj;
}


void graph::traverse(){
  for(int y = 0; y < adjacency_list_length; y++) {
    std::cout<<"adjacency_list[" << y << "]: \n";
    adjacency_list[y].traverse();
  }
}




 
