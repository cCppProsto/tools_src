#include <GL/gl.h>
#include "gpgrid.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpGrid::gpGrid()
{
    addPoint({0,0});
}
//------------------------------------------------------------------------------
gpGrid::gpGrid(point2D aPos,
               int aWidth,
               int aHeight,
               int aRows,
               int aColumns)
    :mWidth(aWidth)
    ,mHeight(aHeight)
    ,mLines(aRows)
    ,mRows(aColumns)
{
    set(aPos, mWidth, mHeight, mLines, mRows);
}
//------------------------------------------------------------------------------
void gpGrid::set(point2D aPos,
                 int aWidth,
                 int aHeight,
                 int aLines,
                 int aRows)
{
    mWidth = aWidth;
    mHeight = aHeight;
    mLines = aLines;
    mRows = aRows;

    mPoints.clear();

    int width  = mWidth  * (mRows);
    int height = mHeight * (mLines);

    for(int r = 0; r <= mLines; ++r)
    {
        addPoint({aPos.x, aPos.y + mHeight*r});
        addPoint({aPos.x + width, aPos.y + mHeight*r});
    }

    for(int c = 0; c <= mRows; ++c)
    {
        addPoint({aPos.x + mWidth*c, aPos.y });
        addPoint({aPos.x + mWidth*c, aPos.y + height});
    }
}
//------------------------------------------------------------------------------
void gpGrid::draw() const
{
    const sRGB &c = mColor.color();

    if(mIsFilledColor)
    {
        const sRGB &c = mFillColor.color();
        glColor3ub(c.mR, c.mG, c.mB);

        glBegin(GL_QUADS);
            glVertex2i(mPoints[0].x, mPoints[0].y);
            glVertex2i(mPoints[0].x + mWidth*mRows, mPoints[0].y);
            glVertex2i(mPoints[0].x + mWidth*mRows, mPoints[0].y + mHeight*mLines);
            glVertex2i(mPoints[0].x, mPoints[0].y + mHeight*mLines);
        glEnd();
    }

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
//------------------------------------------------------------------------------
const point2D &gpGrid::pos()const
{
    return mPoints[0];
}
//------------------------------------------------------------------------------
const int &gpGrid::width()const
{
    return mWidth;
}
//------------------------------------------------------------------------------
const int &gpGrid::height()const
{
    return mHeight;
}
//------------------------------------------------------------------------------
const int &gpGrid::columns()const
{
    return mRows;
}
//------------------------------------------------------------------------------
const int &gpGrid::rows()const
{
    return mLines;
}


}
}
