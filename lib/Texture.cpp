#include "Texture.h"

#include <vendor/stb_image/stb_image.h>

Texture::Texture(const std::string &filePath)
    : m_LoadBuffer(nullptr),
    m_Height(0),
    m_Width(0),
    m_BPP(0)
{
    stbi_set_flip_vertically_on_load(true);
    m_LoadBuffer = stbi_load(filePath.c_str(), &m_Width, &m_Height, &m_BPP, 0);

    glGenTextures(1, &m_RendererID);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_LoadBuffer);
    glGenerateMipmap(GL_TEXTURE_2D);   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (!m_LoadBuffer)
    {
        std::cerr << "Failed to load texture\n";
        stbi_image_free(m_LoadBuffer);
    }
}

Texture::~Texture()
{
    glDeleteTextures(1, &m_RendererID);
}

void Texture::bind(unsigned int solt /*= 0*/) const
{
    glActiveTexture(GL_TEXTURE0 + solt);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
