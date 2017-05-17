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
    for(int i = 0; i < aText.size(); ++i)
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
/*

static bool g_isInited = false;

static main_loop_fun_clbk   main_clbk      = nullptr;
static key_func_clbk        key_clbk       = nullptr;
static mouse_btn_fun_clbk   mouse_btn_clbk = nullptr;

glfw_engine2D *glfw_engine2D::eventHandlingInstance = nullptr;

void resize_clb(GLFWwindow *, int, int);
//------------------------------------------------------------------------------
glfw_engine2D::glfw_engine2D()
{
}
//------------------------------------------------------------------------------
glfw_engine2D &glfw_engine2D::instance()
{
    static glfw_engine2D res;
    return res;
}
//------------------------------------------------------------------------------
void glfw_engine2D::setEventHandling()
{
    eventHandlingInstance = this;
}
//------------------------------------------------------------------------------
bool glfw_engine2D::init(std::string aCaption,
                         unsigned int aWidth,
                         unsigned int aHeight,
                         bool aIsFullScreen)
{
    g_isInited = true;

    mWidth        = aWidth;
    mHeight       = aHeight;
    mIsFullScreen = aIsFullScreen;

    if (!glfwInit())
    {
        g_isInited = false;
        return g_isInited;
    }

    mpGLFW_Win = glfwCreateWindow(mWidth,
                                  mHeight,
                                  aCaption.c_str(),
                                  mIsFullScreen ? glfwGetPrimaryMonitor() : NULL,
                                  NULL);

    glfwSetWindowPos(mpGLFW_Win, 0, 20);

    int scr_width = 0;
    int scr_height = 0;

    glfwGetWindowSize(mpGLFW_Win, &scr_width, &scr_height);
    mWRatio = (float)scr_width  / (float)mWidth;
    mHRatio = (float)scr_height / (float)mHeight;

    if (!mpGLFW_Win)
    {
        glfwTerminate();
        g_isInited = false;
        return g_isInited;
    }
    glfwMakeContextCurrent(mpGLFW_Win);

    glfwSetKeyCallback(mpGLFW_Win, glfw_engine2D::keyEvent);

    //glfwSetKeyCallback        (mpGLFW_Win, key_clbk);
    glfwSetMouseButtonCallback(mpGLFW_Win, mouse_btn_clbk);
    glfwSetWindowSizeCallback (mpGLFW_Win, resize_clb);

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

    return g_isInited;
}
//------------------------------------------------------------------------------
void glfw_engine2D::draw()
{
}
void glfw_engine2D::keyEvent(GLFWwindow *,int ,int ,int ,int)
{
}
//------------------------------------------------------------------------------
void glfw_engine2D::setKeyCallBack(key_func_clbk aClbk)
{
    key_clbk = aClbk;
}
//------------------------------------------------------------------------------
void glfw_engine2D::setMouseCallBack(mouse_btn_fun_clbk aClbk)
{
    mouse_btn_clbk = aClbk;
}
//------------------------------------------------------------------------------
void glfw_engine2D::setMainLoopCallBack(main_loop_fun_clbk aClbk)
{
    main_clbk = aClbk;
}
//------------------------------------------------------------------------------
void glfw_engine2D::run()
{
    static fpstool &fps = fpstool::instance();

    if(!g_isInited)
        init();

    if(!g_isInited)
        return;

    if(main_clbk == nullptr)
    {
        glfwTerminate();
        return;
    }

    while (!glfwWindowShouldClose(mpGLFW_Win))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        fps.start();
        (main_clbk)();
        fps.delay();

        // Swap front and back buffers
        glfwSwapBuffers(mpGLFW_Win);
        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
}
//------------------------------------------------------------------------------
void resize_clb(GLFWwindow *apWindow, int aWidth, int aHeight)
{
    glfw_engine2D &res = glfw_engine2D::instance();
    int scr_width = 0;
    int scr_height = 0;

    glViewport(0, 0, aWidth, aHeight);
    glfwGetWindowSize(apWindow, &scr_width, &scr_height);

    res.mWRatio = (float)scr_width  / (float)res.mWidth;
    res.mHRatio = (float)scr_height / (float)res.mHeight;
}
*/
}
}
