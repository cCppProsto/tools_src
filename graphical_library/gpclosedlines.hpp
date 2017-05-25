#ifndef GPCLOSEDLINES_H
#define GPCLOSEDLINES_H

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpClosedLines : gPrimitive
{
    gpClosedLines();
    gpClosedLines(std::initializer_list<point2D>);
    void add(point2D);
    void draw() const override;
};

}
}
#endif // GPCLOSEDLINES_H
