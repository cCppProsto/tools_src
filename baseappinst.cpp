#include "baseappinst.hpp"
namespace cpp_prosto
{
namespace application
{

//------------------------------------------------------------------------------
baseAppInst::baseAppInst(std::string aAppName) : glfw_engine2D(aAppName)
{
}
//------------------------------------------------------------------------------
void baseAppInst::drawGLFW()
{
  switch(mState)
  {
    case eAppState::INIT:
    {
      v_init();
      break;
    }
    case eAppState::MENU:
    {
      v_menu();
      break;
    }
    case eAppState::APP:
    {
      v_application();
      break;
    }
    case eAppState::EXIT:
    {
      v_exit();
      break;
    }
  }
}
}
}
