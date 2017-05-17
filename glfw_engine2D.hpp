#ifndef _GLFW_ENGINE_H_
#define _GLFW_ENGINE_H_

#include <string>
#include "glfw3.h"

namespace cpp_prosto
{
namespace graphical
{

class glfw_engine2D
{
    glfw_engine2D(const glfw_engine2D&) = delete;
    glfw_engine2D(const glfw_engine2D&&) = delete;
    glfw_engine2D &operator=(const glfw_engine2D&) = delete;
    glfw_engine2D &operator=(const glfw_engine2D&&) = delete;

public:
    glfw_engine2D(std::string = "");
    ~glfw_engine2D() = default;

    const std::string &caption()const;

    const int  &width()const;
    const int  &height()const;
    const bool &isFullScreen()const;

    void run();

    static void drawText(float, float, std::string);

protected:
    virtual void initializeGLFW();

    virtual void drawGLFW() = 0;
    virtual void keyEvent(GLFWwindow *, int, int, int, int) = 0;
    virtual void mouseKeyEvent(GLFWwindow *, int, int, int) = 0;
    virtual void resizeEvent(GLFWwindow *, int, int);

private:
    virtual void setEventHandling();

    static void keyCallback(GLFWwindow *, int, int, int, int);
    static void mouseKeyCallback(GLFWwindow *,int, int, int);
    static void resizeCallback(GLFWwindow *, int, int);

protected:
    int         mWidth          = 1024;
    int         mHeight         = 768;
    bool        mIsFullScreen   = false;
    std::string mCaption;

private:
    GLFWwindow  *mpGLFWWin  = nullptr;
    float        mWRatio    = 1.f;
    float        mHRatio    = 1.f;
    bool         mIsInited  = false;

private:
    static glfw_engine2D *spmEventHandling;
};


/*
 * http://stackoverflow.com/questions/7676971/pointing-to-a-function-that-is-a-class-member-glfw-setkeycallback
 * https://www.gamedev.net/topic/675377-glfw-call-fails/
 * http://stackoverflow.com/questions/27596861/give-static-function-access-to-data-without-passing-the-data-as-a-parameter
 * http://stackoverflow.com/questions/21799746/how-to-glfwsetkeycallback-for-different-classes
 * https://www.gamedev.net/topic/675377-glfw-call-fails/

typedef void (* key_func_clbk)(GLFWwindow*,int,int,int,int);
typedef void (* mouse_btn_fun_clbk)(GLFWwindow*,int,int,int);
typedef void (* main_loop_fun_clbk)();

class glfw_engine2D
{
    static glfw_engine2D *eventHandlingInstance;
    static void keyEvent(GLFWwindow *,int ,int ,int ,int);

    friend void resize_clb(GLFWwindow *, int, int);

    static constexpr unsigned int cScreenWidth  = 1024;
    static constexpr unsigned int cScreenHeight = 768;
    static constexpr bool         cIsFullScreen = false;

public:
    static glfw_engine2D &instance();

    bool init(std::string aCaption = "",
              unsigned int aWidth  = cScreenWidth,
              unsigned int aHeight = cScreenHeight,
              bool aIsFullScreen   = cIsFullScreen);

    virtual void draw();

    void setKeyCallBack(key_func_clbk);
    void setMouseCallBack(mouse_btn_fun_clbk);
    void setMainLoopCallBack(main_loop_fun_clbk);

    void run();

    glfw_engine2D(const glfw_engine2D&) = delete;
    glfw_engine2D(const glfw_engine2D&&) = delete;
    glfw_engine2D &operator=(const glfw_engine2D&) = delete;
    glfw_engine2D &operator=(const glfw_engine2D&&) = delete;

protected:
    glfw_engine2D();
    ~glfw_engine2D() = default;
    void resize(GLFWwindow*,int,int);

    virtual void keycallback(
        GLFWwindow *window,
        int key,
        int scancode,
        int action,
        int mods){}; // purely abstract function

    virtual void setEventHandling();

private:
  GLFWwindow  *mpGLFW_Win    = nullptr;
  unsigned int mWidth        = cScreenWidth;
  unsigned int mHeight       = cScreenHeight;
  bool         mIsFullScreen = cIsFullScreen;
  float        mWRatio       = 1.f;
  float        mHRatio       = 1.f;
};
*/
}
}

#endif /* _GLFW_ENGINE_H_ */
