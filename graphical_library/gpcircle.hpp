#ifndef GPCIRCLE_H
#define GPCIRCLE_H

#define _USE_MATH_DEFINES
#include <cmath>

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpCircle : gPrimitive
{
public:
    gpCircle();
    gpCircle(int, int, point2D);

    void set(point2D);
    void set_radius(int);
    void set_segments(int);

    const point2D &center()const;
    const int &radius()const;
    const int &segments()const;

    void draw() const;

private:
    int mRadius     = 0;
    int mSegments   = 11;
    float mTheta    = (2.f * M_PI / float(mSegments));
    float mCosTheta = std::cos(mTheta);
    float mSinTheta = std::sin(mTheta);
};

}
}

#endif // GPCIRCLE_H
