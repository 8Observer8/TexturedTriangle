#include "Triangle.h"

Triangle::Triangle()
{
    initVertices();
    initTexCoords();
}

void Triangle::initVertices()
{
    vertices.clear();
    vertices.resize( 9 );
    // 0
    vertices[0] = 0.0f;
    vertices[1] = 0.5f;
    vertices[2] = 0.0f;
    // 1
    vertices[3] = -0.5f;
    vertices[4] = -0.5f;
    vertices[5] = 0.0f;
    // 2
    vertices[6] = 0.5f;
    vertices[7] = -0.5f;
    vertices[8] = 0.0f;
}

void Triangle::initTexCoords()
{
    texCoords.clear();
    texCoords.resize( 6 );
    // 0
    texCoords[0] = 0.5f;
    texCoords[1] = 1.0f;
    // 1
    texCoords[2] = 0.0f;
    texCoords[3] = 0.0f;
    // 2
    texCoords[4] = 1.0f;
    texCoords[5] = 0.0f;
}
