#include "prism/texture.h"
#include "vendor/glad/glad.h"

#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"

static inline GLint GetOpenGLFormat(Texture::TextureFormat format)
{
    switch (format)
    {
        case Texture::TextureFormat::RGB:
            return GL_RGB;
        case Texture::TextureFormat::RGBA:
            return GL_RGBA;
        default:
            return GL_RGB;
    }
}
Texture Texture::FromFile(const std::string &filePath, bool withMipMap, TextureFormat format)
{
    int width, height, channels;
    unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &channels, 0);
    if (!data)
    {
        throw std::runtime_error("Error loading texture at path: " + filePath);
    }

    uint32_t id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    // SETTING DEFAULT TEXTURE WRAP FOR X AND Y AXIS
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // SETTING MINIFY AND MAGNIFY DEFAULT TEXTURE FILTERING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLint glFormat = GetOpenGLFormat(format);
    glTexImage2D(GL_TEXTURE_2D, 0, glFormat, width, height, 0, glFormat, GL_UNSIGNED_BYTE, data);
    if (withMipMap)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    stbi_image_free(data);
    return Texture{(uint32_t)width, (uint32_t)height, (uint32_t)channels, id, format};
}

void Texture::Bind()
{
    if (m_Id != 0)
    {
        glBindTexture(GL_TEXTURE_2D, m_Id);
    }
}
