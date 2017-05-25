#include "glfw_engine2D.hpp"
#include "glut.h"
#include "fpstool.hpp"


namespace cpp_prosto
{
namespace graphical
{

glfw_engine2D *glfw_engine2D::spmEventHandling = nullptr;

//------------------------------------------------------------------------------
glfw_engine2D::glfw_engine2D(std::string aCaption)
    :mCaption(aCaption)
{
}
//------------------------------------------------------------------------------
void glfw_engine2D::setEventHandling()
{
    spmEventHandling = this;
}
//------------------------------------------------------------------------------
void glfw_engine2D::run()
{
    initializeGLFW();
    setEventHandling();

    if(!mIsInited)
        return;

    while (!glfwWindowShouldClose(mpGLFWWin))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        static fpstool fps;

        fps.start();
        drawGLFW();
        fps.delay();

        glfwSwapBuffers(mpGLFWWin);             // Swap front and back buffers
        glfwPollEvents();                       // Poll for and process events
    }

    glfwTerminate();
}
//------------------------------------------------------------------------------
void glfw_engine2D::drawText(float aX, float aY, std::string aText)
{
    glColor3ub(254, 254, 254);
    for(size_t i = 0; i < aText.size(); ++i)
    {
        glRasterPos2i( aX + (i*15), aY);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, aText[i]);
    };
}
//------------------------------------------------------------------------------
void glfw_engine2D::keyCallback(GLFWwindow *apWin,
                             int aKey,
                             int aScan,
                             int aAction,
                             int aMods)
{
    if(spmEventHandling)
        spmEventHandling->keyEvent(apWin, aKey, aScan, aAction, aMods);
}
//------------------------------------------------------------------------------
void glfw_engine2D::mouseKeyCallback(GLFWwindow *apWin,
                                     int aBtn,
                                     int aAction,
                                     int aMods)
{
    if(spmEventHandling)
        spmEventHandling->mouseKeyEvent(apWin, aBtn, aAction, aMods);
}
//------------------------------------------------------------------------------
void glfw_engine2D::resizeCallback(GLFWwindow *apWin,
                                   int aWidth,
                                   int aHeigth)
{
    glViewport(0, 0, aWidth, aHeigth);

    if(spmEventHandling)
    {
        int scr_width = 0;
        int scr_height = 0;

        glfwGetWindowSize(apWin, &scr_width, &scr_height);

        spmEventHandling->mWRatio = (float)scr_width  / (float)spmEventHandling->mWidth;
        spmEventHandling->mHRatio = (float)scr_height / (float)spmEventHandling->mHeight;

        spmEventHandling->resizeEvent(apWin, aWidth, aHeigth);
    }
}
//------------------------------------------------------------------------------
void glfw_engine2D::initializeGLFW()
{
    if (!glfwInit())
    {
        mIsInited = false;
        return;
    }

    mpGLFWWin = glfwCreateWindow(mWidth,
                                 mHeight,
                                 mCaption.c_str(),
                                 mIsFullScreen ? glfwGetPrimaryMonitor() : NULL,
                                 NULL);

    glfwSetWindowPos(mpGLFWWin, 0, 20);

    int scr_width = 0;
    int scr_height = 0;

    glfwGetWindowSize(mpGLFWWin, &scr_width, &scr_height);
    mWRatio = (float)scr_width  / (float)mWidth;
    mHRatio = (float)scr_height / (float)mHeight;

    if (!mpGLFWWin)
    {
        glfwTerminate();
        mIsInited = false;
        return;
    }
    glfwMakeContextCurrent(mpGLFWWin);

    glfwSetKeyCallback(mpGLFWWin,         glfw_engine2D::keyCallback);
    glfwSetMouseButtonCallback(mpGLFWWin, glfw_engine2D::mouseKeyCallback);
    glfwSetWindowSizeCallback (mpGLFWWin, glfw_engine2D::resizeCallback);

    glViewport(0, 0, (GLsizei)mWidth, (GLsizei)mHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, mWidth, mHeight, 0, 0, 1);
    glfwSwapInterval(1);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);

    glPointSize(1);
    mIsInited = true;
}
//------------------------------------------------------------------------------
void glfw_engine2D::resizeEvent(GLFWwindow *, int, int)
{
}
//------------------------------------------------------------------------------
const int  &glfw_engine2D::width()const
{
    return mWidth;
}
//------------------------------------------------------------------------------
const int  &glfw_engine2D::height()const
{
    return mHeight;
}
//------------------------------------------------------------------------------
const bool &glfw_engine2D::isFullScreen()const
{
    return mIsFullScreen;
}
//------------------------------------------------------------------------------
const std::string &glfw_engine2D::caption()const
{
    return mCaption;
}

}
}
