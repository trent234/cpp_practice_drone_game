/* trent wilson
 * cs202 project 1: drone simulator
 * 2019_04_17
 * engine is the class that runs the game
 */

#include "engine.h"
//#include <fstream> 
//#include <iostream> 

engine::engine()
{
  course.read_in_course();
}

engine::~engine()
{}

int engine::run(){

  course.traverse(0);

  return 0; 
}


    
