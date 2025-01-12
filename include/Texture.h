#ifndef TEXTURE_H
#define TEXTURE_H

enum Level
{
    RGB,
    RGBA
};

#include <glad/glad.h>
#include <iostream>

class Texture
{
public:
    Texture(const std::string &filePath, Level level);
    ~Texture();

    void bind(unsigned int solt) const;
    void unbind() const;

    inline int getWidth() const { return m_Width; }
    inline int getHeight() const { return m_Height; }
private:
    unsigned int m_RendererID;
    unsigned char *m_LoadBuffer;
    int m_Width, m_Height, m_BPP;
};

#endif