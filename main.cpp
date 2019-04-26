//trent wilson
//cs202 program 1 - drone racing
//2019-04-22

#include "engine.h"
#include <cstring>

int main(int argc, char *argv[]) {
  char* course_file_name = nullptr;
  if(argc < 2) {  
    course_file_name = new char[8];
    strncpy(course_file_name, "course1", 8);
  }
  else course_file_name = argv[1];

  engine eng(course_file_name);
  return eng.run();
}
