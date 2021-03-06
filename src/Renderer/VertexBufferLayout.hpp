//
//  VertexBufferLayout.hpp
//  Neverland
//
//  Created by Admin on 14.07.2021.
//

#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex {
    // position
    glm::vec3 Position;
    // texCoords
    glm::vec2 TexCoords;

    Vertex(glm::vec3 aPosition, glm::vec2 aTexCoords)
        : Position(aPosition)
        , TexCoords(aTexCoords){};
};

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:
                return 4;
            case GL_UNSIGNED_INT:
                return 4;
            case GL_UNSIGNED_BYTE:
                return 1;
        }
        assert(false);
        return 0;
    }
};

class VertexBufferLayout {
private:
    std::vector<VertexBufferElement> m_Elements;
    unsigned int m_Stride;

public:
    VertexBufferLayout()
        : m_Stride(0) {}
    ~VertexBufferLayout(){};

    void pushFloat(unsigned int count) {
        VertexBufferElement element = {GL_FLOAT, count, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
    }

    void pushUInt(unsigned int count) {
        VertexBufferElement element = {GL_UNSIGNED_INT, count, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
    }

    void pushChar(unsigned int count) {
        VertexBufferElement element = {GL_UNSIGNED_BYTE, count, GL_TRUE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
    }

    void pushVec3F(unsigned int count) {
        VertexBufferElement element = {GL_FLOAT, count * 3, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT) * 3;
    }

    void pushVec2F(unsigned int count) {
        VertexBufferElement element = {GL_FLOAT, count * 2, GL_FALSE};
        m_Elements.push_back(element);
        m_Stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT) * 2;
    }

    void pushVertex(unsigned int count) {
        pushVec3F(1);
        pushVec2F(1);
    }

    inline const std::vector<VertexBufferElement> getElements() const {
        return m_Elements;
    }
    inline unsigned int getStride() const {
        return m_Stride;
    }
};
