#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "point.hpp"

namespace geo2D
{

struct vector
{
  vector();
  vector(point);
  vector(point, point);

  void clear();
  void setX(float);
  void setY(float);

  const float &x()const;
  const float &y()const;
  const float &length()const;
  const point &value()const;
  void invert();
  void invert_x();
  void invert_y();

  vector operator +(const vector &);
  vector &operator +=(const vector &);

  vector operator -(const vector &);
  vector &operator -=(const vector &);

  vector operator -(const float &);
  vector &operator -=(const float &);

  vector operator *(float);
  vector &operator *=(float);

  bool operator==(const vector&)const;

private:
  void _length_calculate();

private:
  point mValue;
  float mLength{0.f};
};

}
#endif // VECTOR_HPP
