#ifndef __PRISM_APPLICATION
#define __PRISM_APPLICATION

#include <_types/_uint32_t.h>
#include <cstdint>
#include "prism/log.h"
#include <string>

// Forward Declarations
class GLFWwindow;

namespace prism
{

struct ApplicationConfig
{
    uint32_t Width = 1280;
    uint32_t Height = 720;
    std::string Name = "Prism App";
};

class Application
{
   private:
    GLFWwindow* m_Window = nullptr;
    ApplicationConfig m_AppConfig{};

   public:
    Application(ApplicationConfig config) : m_AppConfig(config) {}

    void Run();

    uint32_t GetWindowWidth() const
    {
        return m_AppConfig.Width;
    }

    uint32_t GetWindowHeight() const
    {
        return m_AppConfig.Height;
    }

    const std::string& GetWindowName() const
    {
        return m_AppConfig.Name;
    }
};

};  // namespace prism
#endif