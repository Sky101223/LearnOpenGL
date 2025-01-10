#include "LoadShader.h"

Shader::Shader(std::vector<const char*> &path)
{
    std::vector<std::string> code;
    std::vector<std::ifstream> shaderFile(2);
    
    shaderFile[VERTEX].exceptions(std::ifstream::failbit | std::ifstream::badbit);
    shaderFile[FRAGMENT].exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        std::vector<std::stringstream> shaderStream(2);
        shaderFile[VERTEX].open(path[VERTEX]);
        shaderFile[FRAGMENT].open(path[FRAGMENT]);

        shaderStream[VERTEX] << shaderFile[VERTEX].rdbuf();
        shaderStream[FRAGMENT] << shaderFile[FRAGMENT].rdbuf();

        closeAllFiles(shaderFile);

        code.push_back(shaderStream[VERTEX].str());
        code.push_back(shaderStream[FRAGMENT].str());
    }
    catch(std::ifstream::failure fileError)
    {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ\n";
    }

    std::vector<const char*> shaderSource(2);
    shaderSource[VERTEX] = code[VERTEX].c_str();
    shaderSource[FRAGMENT] = code[FRAGMENT].c_str();

    std::vector<unsigned int> shader(2);
    shader[VERTEX] = glCreateShader(GL_VERTEX_SHADER);
    shader[FRAGMENT] = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(shader[VERTEX], 1, &shaderSource[VERTEX], NULL);
    glShaderSource(shader[FRAGMENT], 1, &shaderSource[FRAGMENT], NULL);

    glCompileShader(shader[VERTEX]);
    glCompileShader(shader[FRAGMENT]);

    checkCompileErrors(shader[VERTEX], VERTEX_S);
    checkCompileErrors(shader[FRAGMENT], FRAGMENT_S);

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, shader[VERTEX]);
    glAttachShader(m_RendererID, shader[FRAGMENT]);
    glLinkProgram(m_RendererID);
    checkCompileErrors(m_RendererID, PROGRAM_S);
}

void Shader::bind() const
{
    glUseProgram(m_RendererID);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), static_cast<int>(value));
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(m_RendererID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(m_RendererID, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float red, float green, float bule) const
{
    glUniform3f(glGetUniformLocation(m_RendererID, name.c_str()), red, green, bule);
}

void Shader::setFloat(const std::string &name, float red, float green, float bule, float alpha) const
{
    glUniform4f(glGetUniformLocation(m_RendererID, name.c_str()), red, green, bule, alpha);
}

Shader::~Shader()
{
    glDeleteProgram(m_RendererID);
}

void Shader::closeAllFiles(std::vector<std::ifstream> &files)
{
    if (files.empty()) { return; }

    for (size_t i = 0; i < files.size(); i++) { files[i].close(); }
}

void Shader::checkCompileErrors(unsigned int &shader, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if (type != PROGRAM_S)
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n"
                << infoLog
                << "\n -- --------------------------------------------------- -- " <<
            std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n"
                << infoLog <<
                "\n -- --------------------------------------------------- -- " <<
            std::endl;
        }
    }
}

void Shader::deleteAllShaders(std::vector<unsigned int> &shaders)
{
    if (shaders.empty()) { return; }

    for (auto i : shaders) { glDeleteShader(i); }
}
