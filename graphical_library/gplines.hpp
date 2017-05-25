#ifndef GPLINES_H
#define GPLINES_H

#include "gprimitive.hpp"
#include "gpline.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpLines : gPrimitive
{
    gpLines();
    gpLines(std::initializer_list<gpLine>);
    void add(gpLine);
    void draw() const override;
};

}
}
#endif // GPLINES_H
