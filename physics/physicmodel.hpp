#ifndef PHYSICMODEL_HPP
#define PHYSICMODEL_HPP

#include <vector>

#include "point.hpp"
#include "vector.hpp"
#include "force.hpp"

namespace geo2D
{

struct physicModel
{
  physicModel();

  void tick();

  void addForce(force);
  void removeForce(force);

  void setFrictionCoefficient(float);
  void setMassa(float);
  void setPosition(point);
  void setVelocityV(vector);
  void setAccelerationV(vector);

  const float &frictionCoefficient()const;
  const float &massa()const;
  const point &position()const;
  const vector &velocityV()const;
  const vector &accelerationV()const;

  void bottom_border_collision();

private:
  float  mFrictionCoeff{0.f};
  vector mvFriction;

  float  mMassa{10.f};
  point  mPosition;

  vector mvVelocity;

  vector mAcceleration;
  force  mResForce;

  std::vector<force> mForces;
};

}

#endif // PHYSICMODEL_HPP
