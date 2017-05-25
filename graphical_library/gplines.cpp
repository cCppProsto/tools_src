#include <GL/gl.h>
#include "gplines.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpLines::gpLines()
{
}
//------------------------------------------------------------------------------
gpLines::gpLines(std::initializer_list<gpLine> aInitList)
{
    for(auto l : aInitList)
    {
        addPoint(l.p1());
        addPoint(l.p2());
    }
}
//------------------------------------------------------------------------------
void gpLines::add(gpLine aLine)
{
    addPoint(aLine.p1());
    addPoint(aLine.p2());
}
//------------------------------------------------------------------------------
void gpLines::draw() const
{
    const sRGB &c = mColor.color();

    glLineWidth(mPointSize);
    glColor3ub(c.mR, c.mG, c.mB);
    for(size_t i = 0; i< mPoints.size(); i += 2)
    {
        const point2D &p1 = mPoints[i];
        const point2D &p2 = mPoints[i+1];
        glBegin(GL_LINES);
            glVertex2i(p1.x, p1.y);
            glVertex2i(p2.x, p2.y);
        glEnd();
    }
}

}
}
