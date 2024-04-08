#include "particle.hpp"

#include <cmath>

namespace Particle {

void MovableParticle::calcNewState(float dt, std::array<float, 3> pbc) {
  applyNewtonEq(dt);
  applyPBC(pbc);
}

void MovableParticle::setAcc(const std::array<float, 3> &newAcc) {
  acc[0] = newAcc[0];
  acc[1] = newAcc[1];
  acc[2] = newAcc[2];
}
std::array<float, 3> MovableParticle::getPos() const {
  return {pos[0], pos[1], pos[2]};
}

std::array<float, 3> MovableParticle::getVel() const {
  return {vel[0], vel[1], vel[2]};
}

std::array<float, 3> MovableParticle::getAcc() const {
  return {acc[0], acc[1], acc[2]};
}

void MovableParticle::applyNewtonEq(float dt) {
  for (int i = 0; i < 3; i++) {
    pos[i] += vel[i] * dt + 0.5 * acc[i] * dt * dt;
    vel[i] += acc[i] * dt;
  }
}

void MovableParticle::applyPBC(std::array<float, 3> pbc) {
  for (int i = 0; i < 3; i++) {
    pos[i] = std::fmod(pos[i], pbc[i]);
  }
}
} // namespace Particle
