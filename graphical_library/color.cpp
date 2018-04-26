#include "color.hpp"

namespace cpp_prosto
{
namespace graphical
{

Color::Color()
{
}
//------------------------------------------------------------------------------
Color::Color(sRGB aColor)
    :mColor(aColor)
{
}
//------------------------------------------------------------------------------
Color::Color(sRGB &&aColor)
    :mColor(aColor)
{
}
//------------------------------------------------------------------------------
Color::Color(eColorType aColor)
    :mColor(color_common::eColorToRGB(aColor))
{
}
//------------------------------------------------------------------------------
void Color::set(eColorType aColor)
{
    mColor = color_common::eColorToRGB(aColor);
}
//------------------------------------------------------------------------------
void Color::setRGB(const sRGB &arColor)
{
    mColor = arColor;
}
//------------------------------------------------------------------------------
const sRGB &Color::color()const
{
    return mColor;
}

namespace  color_common
{
    //--------------------------------------------------------------------------
    sRGB eColorToRGB(eColorType aColor)
    {
        switch(aColor)
        {
            case eColorType::Aqua:      return {0x00, 0xFF, 0xFF};
            case eColorType::Black:     return {0x00, 0x00, 0x00};
            case eColorType::Blue:      return {0x00, 0x00, 0xFF};
            case eColorType::Fuchsia:   return {0xFF, 0x00, 0xFF};
            case eColorType::Gray:      return {0x80, 0x80, 0x80};
            case eColorType::Green:     return {0x00, 0x80, 0x00};
            case eColorType::Lime:      return {0x00, 0xFF, 0x00};
            case eColorType::Maroon:    return {0x80, 0x00, 0x00};
            case eColorType::Navy:      return {0x00, 0x00, 0x80};
            case eColorType::Olive:     return {0x80, 0x80, 0x00};
            case eColorType::Purple:    return {0x80, 0x00, 0x80};
            case eColorType::Red:       return {0xFF, 0x00, 0x00};
            case eColorType::Silver:    return {0xC0, 0xC0, 0xC0};
            case eColorType::Teal:      return {0x00, 0x80, 0x80};
            case eColorType::White:     return {0xFF, 0xFF, 0xFF};
            case eColorType::Yellow:    return {0xFF, 0xFF, 0x00};
        }
        return {0x00, 0xFF, 0xFF};
    }
}

}
}
