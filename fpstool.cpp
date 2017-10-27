#include <cstdlib>
#include "fpstool.hpp"
#include <chrono>
#include <thread>

namespace cpp_prosto
{
namespace graphical
{

using namespace std::chrono;

//------------------------------------------------------------------------------
fpstool::fpstool()
    :mFps(30)
   ,mMilisecondsForFrame(1000 / mFps)
{
}
//------------------------------------------------------------------------------
void fpstool::setFps(unsigned aFps)
{
    mFps = aFps;
    mMilisecondsForFrame = 1000 / mFps;
}
//------------------------------------------------------------------------------
void fpstool::start()
{
    mStart = clock::now();
}
//------------------------------------------------------------------------------
void fpstool::delay()
{
    static unsigned miliseconds = 0;
    mElapsed    = duration_cast<milliseconds>(clock::now() - mStart);
    miliseconds = std::abs(mMilisecondsForFrame - mElapsed.count());

    while (duration_cast<milliseconds>(clock::now() - mStart).count() < miliseconds)
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

}
}
