#include "planner.h"

Planner::Planner() : targetX(0), targetY(0) {}

void Planner::setTarget(int x, int y) {
  targetX = x;
  targetY = y;
}

bool Planner::hasReachedTarget() {
  // Implement logic comparing current position and target
  return false;  // placeholder
}

void Planner::update() {
  if (hasReachedTarget()) {
    stateMachine.transitionTo(StateMachine::State::Idle);
  } else {
    stateMachine.transitionTo(StateMachine::State::Navigate);
  }
}
