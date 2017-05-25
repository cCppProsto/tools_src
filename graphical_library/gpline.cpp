#include <GL/gl.h>
#include "gpline.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpLine::gpLine()
{
    addPoint(point2D{0, 0});
    addPoint(point2D{0, 0});
}
//------------------------------------------------------------------------------
gpLine::gpLine(point2D aP1, point2D aP2)
{
    addPoint(aP1);
    addPoint(aP2);
}
//------------------------------------------------------------------------------
void gpLine::set(point2D aP1, point2D aP2)
{
    set_point(aP1, 0);
    set_point(aP2, 1);
}
//------------------------------------------------------------------------------
void gpLine::draw()const
{
    const point2D &p1 = point(0);
    const point2D &p2 = point(1);
    const sRGB    &c = mColor.color();

    glLineWidth(point_size());
    glColor3ub(c.mR, c.mG, c.mB);
    glBegin(GL_LINES);
        glVertex2i(p1.x, p1.y);
        glVertex2i(p2.x, p2.y);
    glEnd();
}
//------------------------------------------------------------------------------
const point2D &gpLine::p1()const
{
    const point2D &p = point(0);
    return p;
}
//------------------------------------------------------------------------------
const point2D &gpLine::p2()const
{
    const point2D &p = point(1);
    return p;
}

}
}
