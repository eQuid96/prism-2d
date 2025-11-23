#ifndef __PRISM_APPLICATION
#define __PRISM_APPLICATION

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
    bool m_IsRunning = false;
    float m_LastFrameTime = 0.0f;

   public:
    Application(ApplicationConfig config) : m_AppConfig(config) {}
    ~Application();

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

    float GetTime();

    bool IsRunning()
    {
        return m_IsRunning;
    }

   private:
    void ShutDown();
};

};  // namespace prism
#endif