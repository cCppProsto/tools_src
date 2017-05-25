#include <GL/gl.h>

#include "gpopenlines.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpOpenLines::gpOpenLines()
{
}
//------------------------------------------------------------------------------
gpOpenLines::gpOpenLines(std::initializer_list<point2D> aInitList)
{
    for(auto p : aInitList)
        addPoint(p);
}
//------------------------------------------------------------------------------
void gpOpenLines::add(point2D aPoint)
{
    addPoint(aPoint);
}
//------------------------------------------------------------------------------
void gpOpenLines::draw() const
{
    const sRGB &c = mColor.color();

    glLineWidth(point_size());
    glColor3ub(c.mR, c.mG, c.mB);
    glBegin(GL_LINE_STRIP);
    for(size_t i = 0; i< mPoints.size(); ++i)
    {
        const point2D &p1 = mPoints[i];
        glVertex2i(p1.x, p1.y);
    }
    glEnd();
}

}
}
