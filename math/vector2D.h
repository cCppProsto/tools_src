#ifndef VECTOR_2D_H
#define VECTOR_2D_H

namespace cpp_prosto
{
namespace math
{

struct vector2DNorm
{
  vector2DNorm();
  vector2DNorm(float, float, float, float);
  vector2DNorm(const vector2DNorm&);
  vector2DNorm &operator = (const vector2DNorm&);

  void set_p1_p2(float, float, float, float);

  vector2DNorm operator +(const vector2DNorm &);
  vector2DNorm &operator +=(const vector2DNorm &);

  vector2DNorm operator *(float);
  vector2DNorm &operator *=(float);

  void swap(vector2DNorm&);

  void revert_x();
  void revert_y();

  const float &x()const;
  const float &y()const;

private:
  void normalize();
  void normalize(const float&, const float&, const float&, const float&);

private:
  float mX;
  float mY;
};

}
}
#endif // VECTOR_2D_H
