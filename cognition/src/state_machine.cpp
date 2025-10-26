#include "state_machine.h"

StateMachine::StateMachine() : state(State::Idle) {}

void StateMachine::transitionTo(State newState) {
  state = newState;
}

StateMachine::State StateMachine::currentState() const {
  return state;
}
