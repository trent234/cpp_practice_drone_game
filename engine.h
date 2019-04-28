/* trent wilson
 * cs202 project 1: drone simulator
 * 2019_04_17
 * engine is the class that runs the game
 */

#ifndef engine_h
#define engine_h

#include "data_structures.h"

class engine {
  public:
    engine();
    ~engine();
    //this is what starts the simulation
    int run(); 
     
  protected:

  private:
    graph course;
    //have yet to implement/use this
    int turn_count; 
};

#endif //engine_h
