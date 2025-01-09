#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexBufferLayout;

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout);

    void bind() const;
    void unbind() const;
private:
    GLuint m_ID;
};

#endif