#include <cmath>
#include "angle.hpp"

namespace geo2D
{

angle::angle()
{
}
//------------------------------------------------------------------------------
void angle::setDegree(float aDegree)
{
  mDegree = aDegree;
  mRadian = mDegree*M_PI/180.f;

  mCosinus = std::cos(mRadian);
  mSinus   = std::sin(mRadian);
}
//------------------------------------------------------------------------------
void angle::setRadian(float aRadian)
{
  mRadian = aRadian;
  mDegree = mRadian*180.f/M_PI;

  mCosinus = std::cos(mRadian);
  mSinus   = std::sin(mRadian);
}
//------------------------------------------------------------------------------
const float &angle::radian()const
{
  return mRadian;
}
//------------------------------------------------------------------------------
const float &angle::degree()const
{
  return mDegree;
}
//------------------------------------------------------------------------------
const float &angle::cos()const
{
  return mCosinus;
}
//------------------------------------------------------------------------------
const float &angle::sin()const
{
  return mSinus;
}

}
