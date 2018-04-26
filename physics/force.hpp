#ifndef FORCE_HPP
#define FORCE_HPP

#include "vector.hpp"

namespace geo2D
{

struct force
{
  //      0
  //      ^
  // 270- . -> 90
  //      |
  //     180

  force();
  force(float, float);
  void setValue(float, float);
  const float &value()const;
  const vector &forceV()const;

  void setForce(vector);

  bool operator==(const force&)const;

private:
  vector mVector;
  float  mForce{0.f};
};

}

#endif // FORCE_HPP
