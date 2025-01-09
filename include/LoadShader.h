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
    Shader(std::vector<const GLchar*> &path);
    
    void bind() const;
    void unbind() const;

    void setBool(const std::string &name, GLboolean value) const;
    void setInt(const std::string &name, GLint value) const;
    void setFloat(const std::string &name, GLfloat value) const;
    void setFloat(const std::string &name, GLfloat red, GLfloat green, GLfloat bule) const;
    void setFloat(const std::string &name, GLfloat red, GLfloat green, GLfloat bule, GLfloat alpha) const;

    ~Shader();
private:
    inline void closeAllFiles(std::vector<std::ifstream> &files);
    inline void checkCompileErrors(GLuint &shader, std::string type);
    inline void deleteAllShaders(std::vector<GLuint> &shaders);

    GLuint m_RendererID;
};

#endif