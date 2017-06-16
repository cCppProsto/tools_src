#ifndef GPTRIANGLE_H
#define GPTRIANGLE_H

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpTriangle : gPrimitive
{
    gpTriangle();
    gpTriangle(point2D, point2D, point2D);

    void set(point2D, point2D, point2D);

    const point2D &p1()const;
    const point2D &p2()const;
    const point2D &p3()const;

    void draw() const;
};

}
}
#endif // GPTRIANGLE_H
