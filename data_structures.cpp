/* trent wilson
 * data structures: 
 * nodes that point to an interactive_obj
 * linear linked list that chain together nodes
 * graph that has an array of linear linked lists to create an adjacency list
 */

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

int lll::announce_neighbors(){
  announce_neighbors(head, 0);
  return 0;
}

//recurisve traversal. goes down one adj list. so all the neighbors of the passed in node
int lll::announce_neighbors(node* head, int count){
  if(head == nullptr) return 0;
  std::cout<<count<<") ";
  if(head->get_obj() != nullptr) head->get_obj()->announce();
  else std::cout<<"there is an empty path ahead in this direction...\n";
  announce_neighbors(head->get_next());
  count++;
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
void graph::build_list(lll& individ_adj_list, int* connecting_nodes, int count){
  if(count == 0) return;
  node* new_node = new node;
  new_node->set_obj(&graph_arr[*connecting_nodes]);
  individ_adj_list.prepend(new_node);
  build_list(individ_adj_list, connecting_nodes + 1, --count);
  return; 
}

void graph::read_in_course(){
//stock course layout. ideally would input in from text file for multiple levels. thats later. 
adjacency_list_length = 11;

//dropping different interactive objs into certain parts of the course.
graph_arr = new interactive_obj*[adjacency_list_length];
for(int i = 0; i < adjacency_list_length; i++)
  graph_arr[i] = nullptr;

graph_arr[0] = create_interactive_obj('D');
graph_arr[4] = create_interactive_obj('L');
graph_arr[8] = create_interactive_obj('F');
graph_arr[9] = create_interactive_obj('B');
graph_arr[10] = create_interactive_obj('B');

//connecting nodes with edges to create a certain map via adjacecy list
adjacency_list = new lll[adjacency_list_length];
int neighbors[] = {1,2,0,2,10,1,0,3,4,5,2,4,6,2,3,5,6,2,4,6,7,3,4,6,7,8,5,6,9,6,7,1};
build_list(adjacency_list[0], neighbors, 2);
build_list(adjacency_list[1], neighbors + 2, 3);
build_list(adjacency_list[2], neighbors + 5, 5);
build_list(adjacency_list[3], neighbors + 10, 3);
build_list(adjacency_list[4], neighbors + 13, 4);
build_list(adjacency_list[5], neighbors + 17, 4);
build_list(adjacency_list[6], neighbors + 21, 5);
build_list(adjacency_list[7], neighbors + 26, 3);
build_list(adjacency_list[8], neighbors + 29, 1);
build_list(adjacency_list[9], neighbors + 30, 1);
build_list(adjacency_list[10], neighbors + 31, 1);

//then make the action function for each object
//then make a turn function in main that lets the user pick a direction 
//and then runs through all other objects actions. if connect with finish line
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

//recursive solution
void graph::traverse(int index){
    int user_input = -1; 
    if(index == adjacency_list_length) return;
    std::cout<<"adjacency_list[" << index << "]: \n";
    adjacency_list[index].announce_neighbors();
    if(graph_arr[index] != nullptr) {
      user_input = graph_arr[index]->action();
      //take user input and recursively interate to that spot and move the drone.
      //think about what happens if something is there and ya theres a lot of unanswered questions
    }
    traverse(++index);
    return;
}

