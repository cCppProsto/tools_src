#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gPrimitive::gPrimitive()
{
}
//------------------------------------------------------------------------------
gPrimitive::gPrimitive(std::initializer_list<point2D> aInitList)
    :mPointSize{1.0f}
    ,mIsFilledColor{false}
{
    for( auto point : aInitList)
        addPoint(point);
}
//------------------------------------------------------------------------------
const point2D &gPrimitive::point(size_t aIndex) const
{
    static point2D res;

    if(aIndex < mPoints.size())
        return mPoints[aIndex];
    return res;
}
//------------------------------------------------------------------------------
size_t gPrimitive::point_counts() const
{
    return mPoints.size();
}
//------------------------------------------------------------------------------
void gPrimitive::set_point(point2D aPoint, size_t aIndex)
{
    if(aIndex >= mPoints.size())
        return;
    mPoints[aIndex] = aPoint;
}
//------------------------------------------------------------------------------
void gPrimitive::set_color(Color aColor)
{
    mColor = aColor;
}
//------------------------------------------------------------------------------
void gPrimitive::set_fill_color(Color aFillColor)
{
    mFillColor = aFillColor;
    mIsFilledColor = true;
}
//------------------------------------------------------------------------------
void gPrimitive::move(int aDx, int aDy)
{
    for( auto &point : mPoints)
    {
        point.x += aDx;
        point.y += aDy;
    }
}
//------------------------------------------------------------------------------
void gPrimitive::enableFill()
{
  mIsFilledColor = true;
}
//------------------------------------------------------------------------------
void gPrimitive::disableFill()
{
  mIsFilledColor = false;
}
//------------------------------------------------------------------------------
const bool &gPrimitive::isFilled()const
{
  return mIsFilledColor;
}
//------------------------------------------------------------------------------
const Color &gPrimitive::color()const
{
    return mColor;
}
//------------------------------------------------------------------------------
const Color &gPrimitive::fill_color()const
{
    return mFillColor;
}
//------------------------------------------------------------------------------
void gPrimitive::set_point_size(size_t aPointSize)
{
    mPointSize = aPointSize;
}
//------------------------------------------------------------------------------
const float &gPrimitive::point_size()const
{
    return mPointSize;
}
//------------------------------------------------------------------------------
void gPrimitive::addPoint(const point2D &aPoint)
{
    mPoints.push_back(aPoint);
}
//------------------------------------------------------------------------------
void gPrimitive::draw() const
{

}

}
}
