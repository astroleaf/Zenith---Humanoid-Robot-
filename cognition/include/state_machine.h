#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

class StateMachine {
  public:
    enum class State {
      Idle,
      Navigate,
      AvoidObstacle,
      Interact
    };

    StateMachine();
    void transitionTo(State newState);
    State currentState() const;

  private:
    State state;
};

#endif
