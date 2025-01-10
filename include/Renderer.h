#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "LoadShader.h"

class Renderer
{
public:
    void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void clear() const;
};

#endif