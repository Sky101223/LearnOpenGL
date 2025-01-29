#ifndef LOAD_SHADER_H
#define LOAD_SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

#include <glad/glad.h>

#define VERTEX_S "VERTEX"
#define VERTEX 0
#define FRAGMENT_S "FRAGMENT"
#define FRAGMENT 1
#define PROGRAM_S "PROGRAM"

class Shader
{
public:
    Shader(std::array<const char*, 2>& path);

    void bind() const;
    void unbind() const;

    // uniform
    void setBool(const std::string& name, bool value) const;
    void setInt(const std::string& name, int value) const;
    void setFloat(const std::string& name, float value) const;
    void setFloat(const std::string& name, float red, float green, float bule) const;
    void setFloat(const std::string& name, float red, float green, float bule, float alpha) const;

    ~Shader();

    inline unsigned int getRendererID() { return m_RendererID; }
private:
    void closeAllFiles(std::array<std::ifstream, 2>& files);
    void checkCompileErrors(unsigned int& shader, std::string type);
    void deleteAllShaders(std::array<unsigned int, 2>& shaders);

    unsigned int m_RendererID;
};

#endif