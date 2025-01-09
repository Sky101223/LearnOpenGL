#include "VertexArray.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_ID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_ID);
}

void VertexArray::addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout)
{
    bind();
    vb.bind();
    const auto &elements = layout.getElements();
    GLuint offset = 0;
    for (GLuint i = 0; i < elements.size(); i++)
    {
        const auto &element = elements[i];
        glVertexAttribPointer(i, element.count, element.type, element.normalized,
            layout.getStride(), (const void*)(offset));
        glEnableVertexAttribArray(i);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }
}

void VertexArray::bind() const
{
    glBindVertexArray(m_ID);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}