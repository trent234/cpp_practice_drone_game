/* trent wilson
 * cs202 project 1: drone simulator
 * 2019_04_17
 * node class = pure virtual 
 */

#include "node.h"
#include <iostream>

//**** node

node::node():next(nullptr), prev(nullptr)
{}
 
node& node::get_next(){
  return *next;
}

node& node::get_prev(){
  return *prev;
}

int node::set_next(node* in){
  next = in;
  return 0;
}

int node::set_prev(node* in){
  prev = in;
  return 0;
}


//**** drone

drone::drone()
{}

int drone::action(){
  std::cout<<"i'm a drone!\n"; 
  return 0;
}

//**** black_hole

black_hole::black_hole()
{}


int black_hole::action(){
  std::cout<<"i'm a black_hole!\n"; 
  return 0;
}

//****loop 

loop::loop()
{}


int loop::action(){
  std::cout<<"I'm a loop!\n"; 
  return 0;
}

//****finish 

finish::finish()
{}


int finish::action(){
  std::cout<<"i'm the finish line!\n"; 
  return 0;
}
