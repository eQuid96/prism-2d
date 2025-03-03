

#ifndef _TEXTURE_H
#define _TEXTURE_H

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
    int width = 0;
    int height = 0;
    int channels = 0;
    unsigned int id = 0;
    TextureFormat format;

    Texture(int width, int height, int channels, unsigned int id, TextureFormat format)
        : width(width), height(height), channels(channels), id(id), format(format)
    {
    }

   public:
    int GetWidth() const
    {
        return width;
    }
    int GetHeight() const
    {
        return height;
    }
    static Texture FromFile(const std::string &filePath, bool withMipmap, TextureFormat format);
    void Bind();
};

#endif  // _TEXTURE_H
