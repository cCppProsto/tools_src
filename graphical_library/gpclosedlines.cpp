#include <GL/gl.h>

#include "gpclosedlines.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpClosedLines::gpClosedLines()
{
}
//------------------------------------------------------------------------------
gpClosedLines::gpClosedLines(std::initializer_list<point2D> aInitList)
{
    for(auto p : aInitList)
        addPoint(p);
}
//------------------------------------------------------------------------------
void gpClosedLines::add(point2D aPoint)
{
    addPoint(aPoint);
}
//------------------------------------------------------------------------------
void gpClosedLines::draw() const
{
    const sRGB &c = mColor.color();

    glLineWidth(point_size());
    glColor3ub(c.mR, c.mG, c.mB);
    glBegin(GL_LINE_LOOP);
    for(size_t i = 0; i< mPoints.size(); ++i)
    {
        const point2D &p1 = mPoints[i];
        glVertex2i(p1.x, p1.y);
    }
    glEnd();
}

}
}
