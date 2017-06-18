#ifndef GPPOINT_H
#define GPPOINT_H

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpPoint : gPrimitive
{
    gpPoint();
    gpPoint(point2D, size_t);
    void draw()const;
};

}
}

#endif // GPPOINT_H
