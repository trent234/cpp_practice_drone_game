/* trent wilson
 * cs202 project 1: drone simulator
 * 2019_04_17
 * interactive_obj class = pure virtual 
 */

#include "interactive_objects.h"
#include <iostream>

//**** interactive_obj

interactive_obj::interactive_obj()
{}

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
