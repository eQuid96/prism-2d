// #include "prism/shader.h"
// #include "prism/vector2.h"
// #include <GLFW/glfw3.h>
// #include <glad/glad.h>
// #include <iostream>
// #include <math.h>

// int main()
// {
//     GLFWwindow *window;
//     if (!glfwInit())
//     {
//         std::cerr << "Error initializing glfw" << std::endl;
//         return -1;
//     }

//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     window = glfwCreateWindow(1280, 720, "Learn OpenGL", NULL, NULL);
//     if (!window)
//     {
//         std::cerr << "Error creating glfw window" << std::endl;
//         ;
//     }

//     glfwMakeContextCurrent(window);

//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cerr << "Error initializing GLAD" << std::endl;
//     }

//     float vertices[] = {
//         // positions          // colors                         // texture coords
//         0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,  // top right
//         0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
//         -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom left
//         -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
//     };

//     unsigned int indices[] = {0, 1, 3, 1, 2, 3};

//     unsigned int buffer;
//     unsigned int VAO;
//     unsigned int EBO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &buffer);
//     glGenBuffers(1, &EBO);

//     glBindVertexArray(VAO);
//     glBindBuffer(GL_ARRAY_BUFFER, buffer);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);

//     glEnableVertexAttribArray(1);
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 *
//     sizeof(float)));

//     glEnableVertexAttribArray(2);
//     glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 *
//     sizeof(float)));

//     glBindVertexArray(0);
//     glBindBuffer(GL_ARRAY_BUFFER, 0);

//     Shader defaultShader =
//         Shader::FromFile("../../resources/default.vertex", "../../resources/default.frag");

//     while (!glfwWindowShouldClose(window))
//     {
//         /* Render here */
//         glClear(GL_COLOR_BUFFER_BIT);

//         float currTime = glfwGetTime();
//         float green = sin(currTime) / 2.0f + 0.5f;

//         defaultShader.Use();
//         defaultShader.SetUniform("uGreen", green);

//         glBindVertexArray(VAO);
//         // glDrawArrays(GL_TRIANGLES, 0, 3);
//         glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//         /* Swap front and back buffers */
//         glfwSwapBuffers(window);

//         /* Poll for and process events */
//         glfwPollEvents();
//     }

//     glfwTerminate();
//     return 0;
// }

#include "prism/application.h"

using namespace prism;
int main(void)
{
    Application app = prism::Application(
        ApplicationStartUpArgs{.Width = 1280, .Height = 720, .Name = "Prism App"});

    app.run();
    return 0;
}