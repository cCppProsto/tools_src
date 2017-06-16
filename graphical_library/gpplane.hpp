#ifndef GPPLANE_HPP
#define GPPLANE_HPP

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpPlane : gPrimitive
{
    gpPlane();
    gpPlane(point2D, int, int);

    const point2D &pos()const;

    void set(point2D);
    void set_width(int);
    void set_height(int);

    void draw() const;

private:
    int mWidth  = 0;
    int mHeight = 0;
};

}
}
#endif // GPPLANE_HPP
