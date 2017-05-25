#ifndef GPLINE_H
#define GPLINE_H

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpLine : gPrimitive
{
    gpLine();
    gpLine(point2D, point2D);

    void set(point2D, point2D);

    const point2D &p1()const;
    const point2D &p2()const;

    void draw()const override;
};

}
}

#endif // GPLINE_H
