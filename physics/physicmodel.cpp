#include "common.hpp"
#include "physicmodel.hpp"
#include <cmath>
namespace geo2D
{

//------------------------------------------------------------------------------
physicModel::physicModel()
{
}
//------------------------------------------------------------------------------
void physicModel::tick()
{
  float x = mPosition.x();
  float y = mPosition.y();

  if(mResForce.forceV().length() > 0.f)
  {
    x += mResForce.forceV().x() + mvVelocity.x();
    y += mResForce.forceV().y() + mvVelocity.y();
    mvVelocity += mResForce.forceV();
  }
  else
  {
    if(mvVelocity.length() > 0.5f)
    {
      mvVelocity -= mFrictionCoeff;
      x += mvVelocity.x();
      y += mvVelocity.y();
    }
  }
  mPosition.setX(x);
  mPosition.setY(y);
}
//------------------------------------------------------------------------------
void physicModel::bottom_border_collision()
{
  float P = mMassa * mvVelocity.length();
  if(P < mMassa)
    return;
  if(mForces.empty())
  {
    mvVelocity.invert_y();
  }
  else
  {
    mvVelocity = geo2D::vector({0, P/15});
    mvVelocity.invert_y();
  }
}
//------------------------------------------------------------------------------
void physicModel::addForce(force aForce)
{
  mForces.push_back(aForce);

  vector v;
  v =  aForce.forceV();
  v += mResForce.forceV();
  mResForce.setForce(v);
}
//------------------------------------------------------------------------------
void physicModel::removeForce(force aForce)
{
  auto it  = mForces.begin();
  auto end = mForces.end();

  while(it != end)
  {
    if(*it == aForce)
    {
      mForces.erase(it);

      vector v;
      v =  mResForce.forceV();
      v -= aForce.forceV();
      mResForce.setForce(v);

      return;
    }
    ++it;
  }

}
//------------------------------------------------------------------------------
void physicModel::setFrictionCoefficient(float aCoeff)
{
  mFrictionCoeff = aCoeff;
  mvFriction = geo2D::vector({aCoeff, aCoeff});
}
//------------------------------------------------------------------------------
const float &physicModel::frictionCoefficient()const
{
  return mFrictionCoeff;
}
//------------------------------------------------------------------------------
void physicModel::setMassa(float aMassa)
{
  mMassa = aMassa;
}
//------------------------------------------------------------------------------
const float &physicModel::massa()const
{
  return mMassa;
}
//------------------------------------------------------------------------------
void physicModel::setPosition(point aPos)
{
  mPosition = aPos;
}
//------------------------------------------------------------------------------
const point &physicModel::position()const
{
  return mPosition;
}
//------------------------------------------------------------------------------
void physicModel::setVelocityV(vector aVector)
{
  mvVelocity = aVector;
}
//------------------------------------------------------------------------------
const vector &physicModel::velocityV()const
{
  return mvVelocity;
}
//------------------------------------------------------------------------------
void physicModel::setAccelerationV(vector aVector)
{
  mAcceleration = aVector;
}
//------------------------------------------------------------------------------
const vector &physicModel::accelerationV()const
{
  return mAcceleration;
}

}
