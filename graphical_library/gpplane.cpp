#include <GL/gl.h>
#include "gpplane.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpPlane::gpPlane()
{
    addPoint(point2D{0, 0});
}
//------------------------------------------------------------------------------
gpPlane::gpPlane(point2D aPoint, int aWidth, int aHeight)
    :mWidth(aWidth)
    ,mHeight(aHeight)
{
    addPoint(aPoint);
}
//------------------------------------------------------------------------------
const point2D &gpPlane::pos()const
{
    return mPoints[0];
}
//------------------------------------------------------------------------------
void gpPlane::set_width(int aWidth)
{
    mWidth = aWidth;
}
//------------------------------------------------------------------------------
void gpPlane::set_height(int aHeight)
{
    mHeight = aHeight;
}
//------------------------------------------------------------------------------
void gpPlane::draw() const
{
    const point2D &p1 = point(0);

    if(mIsFilledColor)
    {
        const sRGB &c = mFillColor.color();
        glColor3ub(c.mR, c.mG, c.mB);
        glBegin(GL_QUADS);
            glVertex2i(p1.x,          p1.y);
            glVertex2i(p1.x + mWidth, p1.y);
            glVertex2i(p1.x + mWidth, p1.y + mHeight);
            glVertex2i(p1.x,          p1.y + mHeight);
        glEnd();
    }

    const sRGB &c = mColor.color();

    glColor3ub(c.mR, c.mG, c.mB);
    glLineWidth(point_size());
    glBegin(GL_LINE_LOOP);
        glVertex2i(p1.x,          p1.y);
        glVertex2i(p1.x + mWidth, p1.y);
        glVertex2i(p1.x + mWidth, p1.y + mHeight);
        glVertex2i(p1.x,          p1.y + mHeight);
    glEnd();
}

}
}
