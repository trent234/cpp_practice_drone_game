/* trent wilson
 * cs202 project 1: drone simulator
 * 2019_04_17
 * node class = pure virtual 
 */

#ifndef node_h
#define node_h

class node {
  public:
    //constructors
    node();

    //normal functions needed
 
    //think of what pure virtual classes we will want
    virtual int action() = 0;
    
    node& get_next();
    node& get_prev();
    int set_next(node* in);
    int set_prev(node* in);
  protected:

  private:

    node* next;
    node* prev;
};

class drone: public node {
  public:
    drone();
    int action();
  protected:

  private:

};

class black_hole: public node {
  public:
    black_hole();
    int action();

  protected:

  private:

};

class loop: public node {
  public:
    loop();
    int action();

  protected:

  private:

};

class finish: public node {
  public:
    finish();
    int action();

  protected:

  private:

};

#endif //node_h
