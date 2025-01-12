#include "Renderer.h"

void Renderer::draw(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const
{
    shader.bind();
    va.bind();
    ib.bind();
    glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::clear() const
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
