#version 330 core

in vec2 texture;
out vec4 color;
uniform sampler2D textureUniform;

void main()
{
    color = texture( textureUniform, texture );
}
