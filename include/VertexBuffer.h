#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer(const void *data, GLuint size);

    void bind() const;
    void unbind() const;

    ~VertexBuffer();
private:
    GLuint m_RendererID;
};

#endif