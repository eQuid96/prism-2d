

#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <cstdint>
#include <string>

class Texture
{
   public:
    enum TextureFormat : char
    {
        RGB = 0,
        RGBA,
    };

   private:
    uint32_t m_Width = 0;
    uint32_t m_Height = 0;
    uint32_t m_Channels = 0;
    uint32_t m_Id = 0;
    TextureFormat m_Format;

    Texture(uint32_t width, uint32_t height, uint32_t channels, uint32_t id, TextureFormat format)
        : m_Width(width), m_Height(height), m_Channels(channels), m_Id(id), m_Format(format)
    {
    }

   public:
    uint32_t GetWidth() const
    {
        return m_Width;
    }
    uint32_t GetHeight() const
    {
        return m_Height;
    }
    static Texture FromFile(const std::string &filePath, bool withMipmap, TextureFormat format);
    void Bind();
};

#endif  // _TEXTURE_H
