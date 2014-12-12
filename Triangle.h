#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>
#include <cstddef>
#include "glFunctions.h"

class Triangle
{
public:
    Triangle();
    void initVertices();
    void initColors();
    void initTexture();
    size_t numOfVertices() const;
    void draw( int posAttr, int textureAttr ) const;

    std::vector<float> vertices;
    std::vector<float> textureCoords;
    GLuint textureID;
};

#endif // TRIANGLE_H
