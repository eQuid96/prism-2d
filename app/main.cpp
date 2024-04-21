#include "lib/vector2.h"
#include "lib/Shader.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>


int main()
{
    GLFWwindow* window;
    if(!glfwInit()){
        std::cerr << "Error initializing glfw" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1280, 720, "Learn OpenGL", NULL, NULL);
    if(!window){
        std::cerr << "Error creating glfw window" << std::endl;;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Error initializing GLAD" << std::endl;
    }

    Vector2 points[3] = {
            Vector2{-0.5, -0.5f},
            Vector2{0.0f, 0.5f},
            Vector2{0.5f, -0.5f}
    };

    unsigned int buffer;
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vector2), &points, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vector2), 0);


    Shader defaultShader = Shader::FromFile("../../resources/default.vertex", "../../resources/default.frag");

    while (!glfwWindowShouldClose(window)){
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        float currTime = glfwGetTime();
        float green = sin(currTime) / 2.0f + 0.5f;

        defaultShader.Use();
        defaultShader.SetUniform("uGreen", green);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}