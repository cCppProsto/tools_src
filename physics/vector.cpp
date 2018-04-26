#include <cmath>
#include "vector.hpp"

namespace geo2D
{

//------------------------------------------------------------------------------
vector::vector()
  :mValue({0, 0})
  ,mLength(0.f)
{

}
//------------------------------------------------------------------------------
vector::vector(point ap1)
  :mValue({ap1.x(), ap1.y()})
  ,mLength(sqrt(mValue.x()* mValue.x() + mValue.y()*mValue.y()))
{

}
//------------------------------------------------------------------------------
vector::vector(point ap1, point ap2)
  :mValue({ap2.x() - ap1.x(), ap2.y() - ap1.y()})
  ,mLength(sqrt(mValue.x()* mValue.x() + mValue.y()*mValue.y()))
{
}
//------------------------------------------------------------------------------
void vector::setX(float aX)
{
  mValue.setX(aX);
}
//------------------------------------------------------------------------------
void vector::setY(float aY)
{
  mValue.setY(aY);
}
//------------------------------------------------------------------------------
void vector::_length_calculate()
{
  mLength = sqrt(mValue.x()* mValue.x() + mValue.y()*mValue.y());
}
//------------------------------------------------------------------------------
vector vector::operator +(const vector &aValue)
{
  vector tmp(*this);
  tmp.mValue.mX += aValue.mValue.mX;
  tmp.mValue.mY += aValue.mValue.mY;
  tmp._length_calculate();
  return tmp;
}
//------------------------------------------------------------------------------
vector &vector::operator +=(const vector &aValue)
{
  *this = *this + aValue;
  return *this;
}
//------------------------------------------------------------------------------
vector vector::operator -(const vector &aValue)
{
  vector tmp(*this);
  tmp.mValue.mX -= aValue.mValue.mX;
  tmp.mValue.mY -= aValue.mValue.mY;
  tmp._length_calculate();
  return tmp;
}
//------------------------------------------------------------------------------
vector &vector::operator -=(const vector &aValue)
{
  *this = *this - aValue;
  return *this;
}
//------------------------------------------------------------------------------
vector vector::operator *(float aValue)
{
  point p(mValue.mX, mValue.mY);
  p.mX *= aValue;
  p.mY *= aValue;
  return vector({0,0},p);
}
//------------------------------------------------------------------------------
vector &vector::operator *=(float aValue)
{
  *this = *this * aValue;
  return *this;
}
//------------------------------------------------------------------------------
bool vector::operator==(const vector &a1)const
{
  return    this->mLength    == a1.mLength
         && this->mValue.x() == a1.mValue.x()
         && this->mValue.y() == a1.mValue.y();
}
//------------------------------------------------------------------------------
void vector::invert()
{
  mValue.invert();
}
//------------------------------------------------------------------------------
void vector::invert_x()
{
  mValue.x_invert();
}
//------------------------------------------------------------------------------
void vector::invert_y()
{
  mValue.y_invert();
}
//------------------------------------------------------------------------------
const float &vector::x()const
{
  return mValue.x();
}
//------------------------------------------------------------------------------
const float &vector::y()const
{
  return mValue.y();
}
//------------------------------------------------------------------------------
const point &vector::value()const
{
  return mValue;
}
//------------------------------------------------------------------------------
const float &vector::length()const
{
  return mLength;
}
}
