#include "vector2D.h"

#include <cmath>
#include <utility>

namespace cpp_prosto
{
namespace math
{

vector2DNorm::vector2DNorm()
  :mX{.0f}
  ,mY{.0f}
{
}
//------------------------------------------------------------------------------
vector2DNorm::vector2DNorm(float aX1, float aY1, float aX2, float aY2)
  :mX{.0f}
  ,mY{.0f}
{
  normalize(aX1, aY1, aX2, aY2);
}
//------------------------------------------------------------------------------
vector2DNorm::vector2DNorm(const vector2DNorm &aObj)
  :mX(aObj.mX)
  ,mY(aObj.mY)
{
}
vector2DNorm &vector2DNorm::operator =(const vector2DNorm &aRhs)
{
  if(&aRhs == this)
    return *this;
  mX = aRhs.mX;
  mY = aRhs.mY;
  return *this;
}
//------------------------------------------------------------------------------
void vector2DNorm::set_p1_p2(float aX1, float aY1, float aX2, float aY2)
{
  normalize(aX1, aY1, aX2, aY2);
}
//------------------------------------------------------------------------------
void vector2DNorm::normalize()
{
  normalize(0.f, 0.f, mX, mY);
}
//------------------------------------------------------------------------------
void vector2DNorm::normalize(const float &aX1, const float &aY1, const float &aX2, const float &aY2)
{
  float t1 = aX2 - aX1;
  float t2 = aY2 - aY1;
  float l = sqrt(t1*t1 + t2*t2);

  mX = t1/l;
  mY = t2/l;
}
//------------------------------------------------------------------------------
vector2DNorm vector2DNorm::operator+(const vector2DNorm &aValue)
{
  vector2DNorm tmp(*this);
  tmp.mX += aValue.mX;
  tmp.mY += aValue.mY;
  tmp.normalize();
  return tmp;
}
//------------------------------------------------------------------------------
vector2DNorm &vector2DNorm::operator+=(const vector2DNorm &aValue)
{
  *this = *this + aValue;
  normalize(0, 0, mX, mY);
  return *this;
}
//------------------------------------------------------------------------------
vector2DNorm vector2DNorm::operator*(float aValue)
{
  vector2DNorm res(*this);
  res.mX *= aValue;
  res.mY *= aValue;
  return res;
}
//------------------------------------------------------------------------------
vector2DNorm &vector2DNorm::operator *=(float aValue)
{
  *this = *this * aValue;
  return *this;
}
//------------------------------------------------------------------------------
const float &vector2DNorm::x()const
{
  return mX;
}
//------------------------------------------------------------------------------
const float &vector2DNorm::y()const
{
  return mY;
}
//------------------------------------------------------------------------------
void vector2DNorm::revert_x()
{
  mX *= -1.f;
}
//------------------------------------------------------------------------------
void vector2DNorm::revert_y()
{
  mY *= -1.f;
}
//------------------------------------------------------------------------------
void vector2DNorm::swap(vector2DNorm &aObj)
{
  std::swap(*this, aObj);
}




}
}
