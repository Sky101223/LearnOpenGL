#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer(const void *data, unsigned int size);

    void bind() const;
    void unbind() const;

    ~VertexBuffer();
private:
    unsigned int m_RendererID;
};

#endif