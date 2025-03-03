#include "prism/application.h"
#include <sys/_types/_null.h>
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace prism
{

void Application::run()
{
    if (!glfwInit())
    {
        prism_log_error("Unable initializing glfw");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window =
        glfwCreateWindow(get_window_width(), get_window_height(), get_window_name(), NULL, NULL);
    if (!window)
    {
        prism_log_error("Unable to create window");
    }

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        prism_log_error("Error initializing GLAD");
    }

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        float currTime = glfwGetTime();

        std::cout << "Prism is running: " << currTime << std::endl;
        glfwPollEvents();
    }
}

}  // namespace prism