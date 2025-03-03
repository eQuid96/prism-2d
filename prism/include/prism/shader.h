#ifndef SHADER_H
#define SHADER_H

#include <cstdint>
#include <string>

class Shader
{
   public:
    enum Type
    {
        VERTEX = 0,
        FRAGMENT = 1,
    };

    struct ShaderCompilationResult
    {
        bool HasCompiled;
        unsigned int Id;
    };
    ~Shader();
    static Shader FromFile(const std::string &vertexPath, const std::string &fragmentPath);
    void Use();
    void SetUniform(const std::string &uniform, bool value) const;
    void SetUniform(const std::string &uniform, float value) const;
    void SetUniform(const std::string &uniform, int value) const;

   private:
    Shader(unsigned int id) : m_Id(id) {}
    static ShaderCompilationResult CompileShader(const std::string &src, const Shader::Type type);

    uint32_t m_Id;
};

#endif
