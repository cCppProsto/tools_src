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
    void glfw_close();

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
    GLFWwindow  *mpGLFWWin      = nullptr;
    std::string mCaption;

private:
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
*/
}
}

#endif /* _GLFW_ENGINE_H_ */
