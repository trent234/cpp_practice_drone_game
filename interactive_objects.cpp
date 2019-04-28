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

int drone::announce(){
  std::cout<<"i'm a drone!\n"; 
  return 0;
}

int drone::action(){
  int user_choice; 
  std::cout<<"drone- action!\n"; 
  std::cout<<"where do you want to move?\n";
  std::cin>>user_choice;
  return user_choice;
}

//**** black_hole

black_hole::black_hole()
{}

int black_hole::announce(){
  std::cout<<"i'm a black_hole!\n"; 
  return 0;
}

int black_hole::action(){
  std::cout<<"black_hole- action!\n"; 
  return 0;
}

//****loop 

loop::loop()
{}

 
int loop::announce(){
  std::cout<<"i'm a loop!\n"; 
  return 0;
}
 
int loop::action(){
  std::cout<<"loop- action!\n"; 
  return 0;
}

//****finish 

finish::finish()
{}

int finish::announce(){
  std::cout<<"i'm a finish!\n"; 
  return 0;
}
int finish::action(){
  std::cout<<"finish line- action!\n"; 
  return 0;
}
