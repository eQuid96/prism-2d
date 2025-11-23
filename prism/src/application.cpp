#include "prism/application.h"
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace prism
{

Application::~Application()
{
    ShutDown();
}

void Application::Run()
{
    if (!glfwInit())
    {
        prism_log_error("Unable initializing glfw");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_Window =
        glfwCreateWindow(GetWindowWidth(), GetWindowHeight(), GetWindowName().c_str(), NULL, NULL);
    if (!m_Window)
    {
        prism_log_error("Unable to create window");
    }

    glfwMakeContextCurrent(m_Window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        prism_log_error("Error initializing GLAD");
    }

    m_IsRunning = true;
    while (!glfwWindowShouldClose(m_Window))
    {
        glfwPollEvents();
        float now = GetTime();
        float deltaTime = now - m_LastFrameTime;
        m_LastFrameTime = now;

        // Here we should update game logic with deltaTime

        std::cout << "Prism delta: " << deltaTime << "\n";
        std::cout << "Prism last frame time: " << m_LastFrameTime << "\n";

        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Here we should render

        glfwSwapBuffers(m_Window);
    }
}

void Application::ShutDown()
{
    m_IsRunning = false;

    if (m_Window)
    {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }

    glfwTerminate();
}

float Application::GetTime()
{
    if (m_IsRunning)
    {
        return (float)glfwGetTime();
    }
    return 0.0f;
}

}  // namespace prism