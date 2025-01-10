#ifndef LOAD_SHADER_H
#define LOAD_SHADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <glad/glad.h>

#define VERTEX_S "VERTEX"
#define VERTEX 0
#define FRAGMENT_S "FRAGMENT"
#define FRAGMENT 1
#define PROGRAM_S "PROGRAM"

class Shader
{
public:
    Shader(std::vector<const char*> &path);
    
    void bind() const;
    void unbind() const;

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setFloat(const std::string &name, float red, float green, float bule) const;
    void setFloat(const std::string &name, float red, float green, float bule, float alpha) const;

    ~Shader();
private:
    inline void closeAllFiles(std::vector<std::ifstream> &files);
    inline void checkCompileErrors(unsigned int &shader, std::string type);
    inline void deleteAllShaders(std::vector<unsigned int> &shaders);

    unsigned int m_RendererID;
};

#endif