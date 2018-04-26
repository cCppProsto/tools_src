#include <cmath>

#include "force.hpp"
#include "angle.hpp"

namespace geo2D
{

force::force()
{
}
//------------------------------------------------------------------------------
force::force(float aValue, float aAngle)
{
  setValue(aValue, aAngle);
}
//------------------------------------------------------------------------------
void force::setForce(vector aForce)
{
  mVector = aForce;
  mForce  = sqrt(mVector.x()*mVector.x() + mVector.y()*mVector.y());
}
//------------------------------------------------------------------------------
void force::setValue(float aValue, float aAngle)
{
  angle ang;
  ang.setDegree(aAngle);

  mVector = geo2D::vector({aValue*std::sin(ang.radian()), aValue*std::cos(ang.radian())});
  mVector.invert_y();

  if(abs(mVector.x()) < 0.0001)
    mVector.setX(0.f);

  if(abs(mVector.y()) < 0.0001)
    mVector.setY(0.f);

  mForce = aValue;
}
//------------------------------------------------------------------------------
const float &force::value()const
{
  return mForce;
}
//------------------------------------------------------------------------------
const vector &force::forceV()const
{
  return mVector;
}
//------------------------------------------------------------------------------
bool force::operator==(const force &aObj)const
{
  return    this->mForce  == aObj.mForce
         && this->mVector == aObj.mVector;
}




}
