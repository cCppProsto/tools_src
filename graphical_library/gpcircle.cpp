#include <GL/gl.h>
#include "gpcircle.hpp"

namespace cpp_prosto
{
namespace graphical
{

//------------------------------------------------------------------------------
gpCircle::gpCircle()
{
    addPoint(point2D{0, 0});
}
//------------------------------------------------------------------------------
gpCircle::gpCircle(int aRadius, int aSegments, point2D aPoint)
    :mRadius(aRadius)
    ,mSegments(aSegments)
{
    addPoint(aPoint);

    mTheta = (2.f * M_PI / float(mSegments));
    mCosTheta = std::cos(mTheta);
    mSinTheta = std::sin(mTheta);
}
//------------------------------------------------------------------------------
void gpCircle::set_radius(int aRadius)
{
    mRadius = aRadius;
}
//------------------------------------------------------------------------------
void gpCircle::set_segments(int aSegments)
{
    mSegments = aSegments;
    mTheta = (2.f * M_PI / float(mSegments));
    mCosTheta = std::cos(mTheta);
    mSinTheta = std::sin(mTheta);
}
//------------------------------------------------------------------------------
const point2D &gpCircle::center()const
{
    return mPoints[0];
}
//------------------------------------------------------------------------------
const int &gpCircle::radius()const
{
    return mRadius;
}
//------------------------------------------------------------------------------
const int &gpCircle::segments()const
{
    return mSegments;
}
//------------------------------------------------------------------------------
void gpCircle::draw() const
{
    const point2D &p1 = point(0);

    if(mIsFilledColor)
    {
        float t = 0.f;
        float x = mRadius;
        float y = 0.f;

        const sRGB &c = mFillColor.color();
        glColor3ub(c.mR, c.mG, c.mB);

        glBegin(GL_TRIANGLE_FAN);
        for(int i = 0; i < mSegments; i++)
        {
            t = x;
            x = mCosTheta * x - mSinTheta * y;
            y = mSinTheta * t + mCosTheta * y;
            glVertex2i(p1.x + x, p1.y + y);
        }
        glEnd();
    }

    float t = 0.0f;
    float x = mRadius;
    float y = 0;
    const sRGB &c = mColor.color();

    glLineWidth(point_size());
    glColor3ub(c.mR, c.mG, c.mB);

    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < mSegments; i++)
    {
        t = x;
        x = mCosTheta * x - mSinTheta * y;
        y = mSinTheta * t + mCosTheta * y;
        glVertex2i(p1.x + x, p1.y + y);
    }
    glEnd();
}

}
}
