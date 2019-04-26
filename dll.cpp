

#include "dll.h"
#include <fstream>
#include <iostream>

//*****dll

dll::dll()
{}

int dll::traverse(){
  traverse(head);
  return 0;
}
int dll::traverse(node* head){
  if(head == nullptr) return 0;  
  head->action();
  traverse(&(head->get_next()));
  return 0; 

}

//head == nullptr only when tail == nullptr too
int dll::prepend(node* in){
  if(in == nullptr) return 1; 
  if(head == nullptr) {
    head = in;
    tail = in;
  }
  else {
    in->set_next(head);
    head->set_prev(in);
  }
    head = in;
  return 0;
}

//*****graph

graph::graph(){

//stock obstacle course stuff change this to be dynamic based on obst course when the time comes
  adjacency_list = nullptr;

}

void graph::read_in_course(char* in_file){
  char read_in[9];
  std::fstream fs;
  fs.open(in_file, std::fstream::in);
  if(!fs.is_open()) {
    fprintf(stdout, "Error opening map file.\n");
  }
  else{ 
    fs.getline(read_in, 9);
    adjacency_list_length = atoi(read_in);
    obj_arr = new Node[adjacency_list_length];
    fs.getline(read_in, 9);
    int course_object_qty = atoi(read_in);
    for(int i = 0; i < course_obj; i++){
      fs.getline(read_in, 9);
      obj_arr[strtok(read_in, ',')]
    }
    fs.get(read_in,2,','); 
    adjacency_list = new dll[adjacency_list_length];
    for(int y = 0; y < adjacency_list_length; y++){
      while(c != '\n'){
        fs.get(c);
        adjacency_list[y].prepend(create_node_obj(c));
      } 
    }
    fs.close();
    }
}

node* graph::create_node_obj(char in){
  node* new_node = nullptr;
  switch(in){
    case('1'):
      new_node = new drone;
      break;
    case('B'):
      new_node = new black_hole;
      break;
    /*case('F'):
      new_node = new finish_line; 
      break;*/
  }
  return new_node;
}


void graph::traverse(){
  for(int y = 0; y < adjacency_list_length; y++) {
    std::cout<<"adjacency_list[" << y << "]: \n";
    adjacency_list[y].traverse();
  }
}




 
