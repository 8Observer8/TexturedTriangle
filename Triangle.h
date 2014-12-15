#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <vector>

class Triangle
{
public:
    Triangle();
    void initVertices();
    void initTexCoords();

    std::vector<float> vertices;
    std::vector<float> texCoords;
};

#endif // TRIANGLE_H
