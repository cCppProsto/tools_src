#ifndef GPGRID_H
#define GPGRID_H

#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpGrid : gPrimitive
{
    gpGrid();
    gpGrid(point2D, int, int, int, int);

    void set(point2D, int, int, int, int);

    const point2D &pos()const;
    const int &width()const;
    const int &height()const;
    const int &columns()const;
    const int &rows()const;

    void draw() const override;

private:
    int mWidth{0};
    int mHeight{0};
    int mRows{0};
    int mColumns{0};
};

}
}

#endif // GPGRID_H
