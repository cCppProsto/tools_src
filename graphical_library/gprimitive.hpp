#ifndef GPRIMITIVE_H
#define GPRIMITIVE_H

#include <vector>
#include <cstddef>
#include "color.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct point2D
{
    point2D(){}
    point2D(int aX, int aY) :x(aX),y(aY){}
    int x{0};
    int y{0};
};

class gPrimitive
{
public:
    gPrimitive();
    gPrimitive(const gPrimitive&) = default;
    gPrimitive &operator=(const gPrimitive&) = default;
    virtual ~gPrimitive(){}

    void set_point(point2D, size_t);
    void set_color(Color);
    void set_fill_color(Color);
    void set_point_size(size_t);

    void move(int, int);

    const point2D &point(size_t) const;
    const Color   &color()       const;
    const Color   &fill_color()  const;
    const float   &point_size()  const;
    size_t point_counts() const;

    virtual void draw() const = 0;

protected:
    gPrimitive(std::initializer_list<point2D>);
    void addPoint(const point2D&);

protected:
    float                mPointSize{1.0f};
    bool                 mIsFilledColor = false;
    Color                mColor;
    Color                mFillColor;
    std::vector<point2D> mPoints;
};

}
}
#endif // GPRIMITIVE_H
