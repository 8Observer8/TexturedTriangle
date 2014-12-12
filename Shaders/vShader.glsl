#version 330 core

in vec4 posAttr;
uniform mat4 matrix;
in vec2 textureAttr;
out vec2 texture;

void main()
{
    texture = textureAttr;
    gl_Position = matrix * posAttr;
}
