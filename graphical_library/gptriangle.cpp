#include <GL/gl.h>
#include "gptriangle.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpTriangle::gpTriangle()
{
    addPoint(point2D{0, 0});
    addPoint(point2D{0, 0});
    addPoint(point2D{0, 0});
}
//------------------------------------------------------------------------------
gpTriangle::gpTriangle(point2D aP1, point2D aP2, point2D aP3)
{
    addPoint(aP1);
    addPoint(aP2);
    addPoint(aP3);
}
//------------------------------------------------------------------------------
void gpTriangle::set(point2D aP1, point2D aP2, point2D aP3)
{
    mPoints[0] = aP1;
    mPoints[1] = aP2;
    mPoints[2] = aP3;
}
//------------------------------------------------------------------------------
const point2D &gpTriangle::p1()const
{
    return mPoints[0];
}
//------------------------------------------------------------------------------
const point2D &gpTriangle::p2()const
{
    return mPoints[1];
}
//------------------------------------------------------------------------------
const point2D &gpTriangle::p3()const
{
    return mPoints[2];
}
//------------------------------------------------------------------------------
void gpTriangle::draw() const
{
    const point2D &p1 = mPoints[0];
    const point2D &p2 = mPoints[1];
    const point2D &p3 = mPoints[2];

    if(mIsFilledColor)
    {
        const sRGB &c = mFillColor.color();
        glColor3ub(c.mR, c.mG, c.mB);
        glBegin(GL_POLYGON);
            glVertex2i(p1.x, p1.y);
            glVertex2i(p2.x, p2.y);
            glVertex2i(p3.x, p3.y);
        glEnd();
    }

    const sRGB &c = mColor.color();

    glColor3ub(c.mR, c.mG, c.mB);
    glLineWidth(point_size());
    glBegin(GL_LINE_LOOP);
        glVertex2i(p1.x, p1.y);
        glVertex2i(p2.x, p2.y);
        glVertex2i(p3.x, p3.y);
    glEnd();
}

}
}
