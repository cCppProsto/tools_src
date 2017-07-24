#ifndef FPSTOOL_H
#define FPSTOOL_H

#include <chrono>

namespace cpp_prosto
{
namespace graphical
{

class fpstool
{
    using clock = std::chrono::high_resolution_clock;

public:
    fpstool();
    ~fpstool() = default;

    void setFps(unsigned);
    void start();
    void delay();

    fpstool(const fpstool&) = delete;
    fpstool(const fpstool&&) = delete;
    fpstool &operator=(const fpstool&) = delete;
    fpstool &operator=(const fpstool&&) = delete;

private:
    unsigned                  mFps;
    unsigned                  mMilisecondsForFrame;

    clock::time_point         mStart;
    std::chrono::milliseconds mElapsed;
};

}
}
#endif // FPSTOOL_H
