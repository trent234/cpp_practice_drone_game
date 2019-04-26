/* trent wilson
 * cs202 project 1: drone simulator
 * 2019_04_17
 * engine is the class that runs the game
 */

#ifndef engine_h
#define engine_h

#include "dll.h"

class engine {
  public:
    engine(char* in);
    ~engine();
    int run(); //this is what kicks it off
     
  protected:

  private:
    graph course;
    //have yet to implement/use this
    int turn count; 
};

#endif //engine_h
