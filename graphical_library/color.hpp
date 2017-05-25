#ifndef COLOR_H
#define COLOR_H


namespace cpp_prosto
{
namespace graphical
{

enum class eColorType : unsigned int
{
    Aqua     = 0x00FFFF  // 000, 255, 255
   ,Black    = 0x000000  // 000, 000, 000
   ,Blue     = 0x0000FF  // 000, 000, 255
   ,Fuchsia  = 0xFF00FF  // 255, 000, 255
   ,Gray     = 0x808080  // 128, 128, 128
   ,Green    = 0x008000  // 000, 128, 000
   ,Lime     = 0x00FF00  // 000, 255, 000
   ,Maroon   = 0x800000  // 128, 000, 000
   ,Navy     = 0x000080  // 000, 000, 128
   ,Olive    = 0x808000  // 128, 128, 000
   ,Purple   = 0x800080  // 128, 000, 128
   ,Red      = 0xFF0000  // 255, 000, 000
   ,Silver   = 0xC0C0C0  // 192, 192, 192
   ,Teal     = 0x008080  // 000, 128, 128
   ,White    = 0xFFFFFF  // 255, 255, 255
   ,Yellow   = 0xFFFF00  // 255, 255, 000
};

struct sRGB
{
    unsigned char mR;
    unsigned char mG;
    unsigned char mB;
};

struct Color
{
    Color();
    Color(sRGB);
    Color(sRGB&&);
    Color(eColorType);

    ~Color() = default;
    Color(const Color&) = default;
    Color &operator=(const Color&) = default;

    void set(eColorType);
    void setRGB(const sRGB&);

    const sRGB &color()const;

private:
    sRGB mColor{0x00, 0x00, 0x00};
};

namespace color_common
{
    sRGB eColorToRGB(eColorType);
}


}
}

#endif // COLOR_H
