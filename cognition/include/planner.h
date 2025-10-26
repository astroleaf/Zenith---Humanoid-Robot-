#ifndef PLANNER_H
#define PLANNER_H

#include "state_machine.h"

class Planner {
  public:
    Planner();
    void update();
    void setTarget(int x, int y);
    bool hasReachedTarget();

  private:
    int targetX;
    int targetY;
    StateMachine stateMachine;
};

#endif
