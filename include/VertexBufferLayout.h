#ifndef VERTEX_BUFFER_LAYOUT_H
#define VERTEX_BUFFER_LAYOUT_H

#include <vector>

#include <glad/glad.h>

enum TYPE
{
    FLAOT,
    UNSIGNED_INT,
    UNSIGNED_BYTE
};

struct VertexBufferElement
{
    unsigned int type;
    unsigned int count;
    unsigned int normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch (type)
        {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        return 0;
    }
};

class VertexBufferLayout
{
public:
    VertexBufferLayout()
        : m_Stride(0)
    { }

    void push(TYPE type, unsigned int count)
    {
        switch (type)
        {
        case TYPE::FLAOT:
            m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
            break;

        case TYPE::UNSIGNED_INT:     
            m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
            break;
        
        case TYPE::UNSIGNED_BYTE:
            m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_FALSE });
            m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
            break;
        
        default:
            static_assert(true);
            break;
        }
    }
    
    inline const std::vector<VertexBufferElement> getElements() const { return m_Elements; }
    inline unsigned int getStride() const { return m_Stride; }
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;
};

#endif