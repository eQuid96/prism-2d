#ifndef __PRISM_APPLICATION
#define __PRISM_APPLICATION

#include "prism/log.h"

// Forward Declaration
class GLFWwindow;

namespace prism
{

struct ApplicationStartUpArgs
{
    int Width;
    int Height;
    const char* Name;
};

class Application
{
   private:
    GLFWwindow* window = nullptr;
    ApplicationStartUpArgs appArgs{};

   public:
    Application(ApplicationStartUpArgs args) : appArgs(args) {}
    void run();

    int get_window_width() const
    {
        return appArgs.Width;
    }

    int get_window_height() const
    {
        return appArgs.Height;
    }

    const char* get_window_name() const
    {
        return appArgs.Name;
    }
};

};  // namespace prism
#endif