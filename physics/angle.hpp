#ifndef ANGLE_HPP
#define ANGLE_HPP

namespace geo2D
{

struct angle
{
  angle();

  void setDegree(float aDegree);

  void setRadian(float aRadian);

  const float &radian()const;
  const float &degree()const;

  const float &cos()const;
  const float &sin()const;

private:
  float mDegree{0};
  float mRadian{0};
  float mCosinus;
  float mSinus;
};

}
#endif // ANGLE_HPP
