#ifndef BASEAPPINST_H
#define BASEAPPINST_H

#include <string>

#include "glfw_engine2D.hpp"

namespace cpp_prosto
{
namespace application
{

enum class eAppState
{
  INIT
 ,MENU
 ,APP
 ,EXIT
};

using namespace cpp_prosto::graphical;

struct baseAppInst : glfw_engine2D
{
  baseAppInst(std::string aAppName = "");

private:
  void drawGLFW() override;

  virtual void v_init()        = 0;
  virtual void v_menu()        = 0;
  virtual void v_application() = 0;
  virtual void v_exit()        = 0;

protected:
  eAppState mState{eAppState::INIT};
};

}
}
#endif // BASEAPPINST_H
