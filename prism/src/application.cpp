#include "prism/application.h"
#include <sys/_types/_null.h>
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace prism
{

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

    while (!glfwWindowShouldClose(m_Window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        float currTime = glfwGetTime();

        std::cout << "Prism is running: " << currTime << std::endl;
        glfwPollEvents();
    }
}

}  // namespace prism