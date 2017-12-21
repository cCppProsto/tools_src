#include <sstream>

#include "glut.h"
#include "GL/gl.h"
#include "gpnumber.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpNumber::gpNumber()
{
}
//------------------------------------------------------------------------------
gpNumber::gpNumber(point2D aPoint)
{
  addPoint(aPoint);
}
//------------------------------------------------------------------------------
void gpNumber::setValue(int aValue)
{
  mValue = aValue;

  std::stringstream ss;
  ss << aValue;
  mTextValue = ss.str();
}
//------------------------------------------------------------------------------
void gpNumber::draw()const
{
  const sRGB &c = mColor.color();
  const point2D &p1 = point(0);

  glColor3ub(c.mR, c.mG, c.mB);

  for(size_t i = 0; i < mTextValue.size(); ++i)
  {
      glRasterPos2i( p1.x + (i*8), p1.y);
      glutBitmapCharacter(GLUT_BITMAP_8_BY_13, mTextValue[i]);
  }
}

}
}
