#include "Renderer.hpp"
#include <glad/glad.h>

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::setClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::setRenderBufferSize(int w, int h) {
    glViewport(0, 0, w, h);
}

void Renderer::drawArrays(int count) {
    glDrawArrays(GL_TRIANGLES, 0, count);
}

void Renderer::drawIndexed(int count) {
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
}