#include "GL/gl.h"

#include "gppoint.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpPoint::gpPoint()
{
    addPoint(point2D{0,0});
}
//------------------------------------------------------------------------------
gpPoint::gpPoint(point2D aPoint, size_t aSize)
{
    addPoint(aPoint);
    set_point_size(aSize);
}
//------------------------------------------------------------------------------
void gpPoint::set(point2D aPoint)
{
    set_point(aPoint, 0);
}
//------------------------------------------------------------------------------
void gpPoint::draw()const
{
    const point2D &p = point(0);
    const sRGB    &c = mColor.color();

    glPointSize(point_size());
    glColor3ub(c.mR, c.mG, c.mB);
    glBegin(GL_POINTS);
        glVertex2i(p.x, p.y);
    glEnd();
}

}
}
