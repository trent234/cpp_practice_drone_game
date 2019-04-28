/* trent wilson
 * cs202 project 1: drone simulator
 * 2019_04_17
 * interactive_obj class = pure virtual 
 */

#ifndef interactive_obj_h
#define interactive_obj_h

class interactive_obj {
  public:
    //constructors
    interactive_obj();

    //normal functions needed
 
    //think of what pure virtual classes we will want
    virtual int announce() = 0;
    virtual int action() = 0;
    
  protected:

  private:

};

class drone: public interactive_obj {
  public:
    drone();
    int announce();
    int action();
  protected:

  private:

};

class black_hole: public interactive_obj {
  public:
    black_hole();
    int announce();
    int action();

  protected:

  private:

};

class loop: public interactive_obj {
  public:
    loop();
    int announce();
    int action();

  protected:

  private:

};

class finish: public interactive_obj {
  public:
    finish();
    int announce();
    int action();

  protected:

  private:

};

#endif //interactive_obj_h
