#ifndef GPNUMBER_HPP
#define GPNUMBER_HPP

#include <string>
#include "gprimitive.hpp"

namespace cpp_prosto
{
namespace graphical
{

struct gpNumber : gPrimitive
{
  gpNumber();
  gpNumber(point2D);

  void setValue(int);
  void draw()const;

private:
  int mValue{0};
  std::string mTextValue{"0"};
};

}
}

#endif // GPNUMBER_HPP
