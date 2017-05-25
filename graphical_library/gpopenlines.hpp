#ifndef GPOPENLINES_H
#define GPOPENLINES_H

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpOpenLines : gPrimitive
{
    gpOpenLines();
    gpOpenLines(std::initializer_list<point2D>);
    void add(point2D);
    void draw() const override;
};


}
}
#endif // GPOPENLINES_H
