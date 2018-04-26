#include "common.hpp"
#include "physicmodel.hpp"

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

  x += mResForce.forceV().x() + mVelocity.x();
  y += mResForce.forceV().y() + mVelocity.y();

  mVelocity += mResForce.forceV();

  mPosition.setX(x);
  mPosition.setY(y);
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
  mVelocity = aVector;
}
//------------------------------------------------------------------------------
const vector &physicModel::velocityV()const
{
  return mVelocity;
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
