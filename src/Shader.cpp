#include "lib/Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>

Shader Shader::FromFile(const std::string &vertexPath, const std::string &fragmentPath) {
    std::ifstream vertexStream;
    std::ifstream fragmentStream;
    vertexStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    std::string vertexSource, fragmentSource;
    try {
        std::stringstream vSourceStream, fSourceStream;
        vertexStream.open(vertexPath);
        fragmentStream.open(fragmentPath);

        vSourceStream << vertexStream.rdbuf();
        fSourceStream << fragmentStream.rdbuf();

        vertexSource = vSourceStream.str();
        fragmentSource = fSourceStream.str();

        vertexStream.close();
        fragmentStream.close();
    }
    catch (std::ifstream::failure& error) {
        std::cout << "Error loading shader file: " << error.what() << std::endl;
        return Shader(0);
    }


    ShaderCompilationResult vertexResult = CompileShader(vertexSource, Shader::Type::VERTEX);
    ShaderCompilationResult fragmentResult = CompileShader(fragmentSource, Shader::Type::FRAGMENT);
    //error compiling vertex or fragment shader abort shader program linking
    if(!vertexResult.HasCompiled || !fragmentResult.HasCompiled){
        return Shader(0);
    }
    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexResult.Id);
    glAttachShader(program, fragmentResult.Id);
    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vertexResult.Id);
    glDeleteShader(fragmentResult.Id);

    return Shader(program);
}

Shader::ShaderCompilationResult Shader::CompileShader(const std::string &src, const Shader::Type type) {
    unsigned int shaderId = glCreateShader(type == Shader::Type::VERTEX ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    const char* source = src.c_str();
    glShaderSource(shaderId, 1, &source, nullptr);
    glCompileShader(shaderId);
    int result{0};

    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
    if(!result){
        int errorLength{0};
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &errorLength);
        const char* message = (const char*) alloca(sizeof(char )* errorLength);
        std::cout << "Error compiling " << (type == Shader::Type::VERTEX ? "vertex shader" : "fragment shader") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(shaderId);
        return {false, 0};
    }

    return {true, shaderId};
}

void Shader::Use() {
    if(id != 0){
        glUseProgram(id);
    }
}

void Shader::SetUniform(const std::string &uniform, bool value) const {
    int location = glGetUniformLocation(id, uniform.c_str());
    glUniform1i(location, (int)value);
}

void Shader::SetUniform(const std::string &uniform, int value) const {
    int location = glGetUniformLocation(id, uniform.c_str());
    glUniform1i(location, value);
}

void Shader::SetUniform(const std::string &uniform, float value) const {
    int location = glGetUniformLocation(id, uniform.c_str());
    glUniform1f(location, value);
}

Shader::~Shader(){
    glDeleteProgram(id);
}



