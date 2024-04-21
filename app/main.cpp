#include "lib/vector2.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

static unsigned int CompileShader(unsigned int type, const std::string& source){
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    int result{0};
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE){
        int messageLength{0};
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &messageLength);
        char* message = (char*)alloca(messageLength * sizeof (char ));
        glGetShaderInfoLog(id, messageLength, &messageLength, message);
        std::cout << "Failed to compile shader type: " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }
    return id;
}

static unsigned int CreateShaderProgram(const std::string& vertexSrc, const std::string& fragmentSrc){
    unsigned int program = glCreateProgram();
    unsigned int vertex = CompileShader(GL_VERTEX_SHADER, vertexSrc);
    unsigned int fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentSrc);
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return program;
}

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

    const std::string vertexShaderSource = "#version 330 core\n"
                                           "layout (location = 0) in vec4 position;\n"
                                           "void main()\n"
                                           "{\n"
                                           "   gl_Position = position;\n"
                                           "}\n";

    const std::string fragmentShaderSource = "#version 330 core\n"
                                             "out vec4 color;\n"
                                             "void main()\n"
                                             "{\n"
                                             "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
                                             "}\n";


    unsigned int shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);
    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window)){
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
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