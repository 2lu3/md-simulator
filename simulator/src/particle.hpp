#pragma once

#include <array>

namespace Particle {

class MovableParticle {
public:
  MovableParticle() { MovableParticle({0, 0, 0}, {0, 0, 0}); }
  MovableParticle(std::array<float, 3> pos, std::array<float, 3> vel)
      : pos{pos[0], pos[1], pos[2]}, vel{vel[0], vel[1], vel[2]},
        acc{0, 0, 0} {};

  void calcNewState(float dt, std::array<float, 3> pbc);

  void setAcc(const std::array<float, 3> &newAcc);

  std::array<float, 3> getPos() const;
  std::array<float, 3> getVel() const;
  std::array<float, 3> getAcc() const;

private:
  float pos[3];
  float vel[3];
  float acc[3];

  /**
   * @brief ニュートンの運動方程式を適用する
   *
   * @param dt
   */
  void applyNewtonEq(float dt);
  /**
   * @brief 周期境界条件を適用する
   *
   * @param pbc
   */
  void applyPBC(std::array<float, 3> pbc);
};
} // namespace Particle
