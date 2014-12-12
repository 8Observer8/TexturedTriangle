#version 330 core

in vec2 tex;
out vec4 color;
uniform sampler2D textureUniform;

void main()
{
    color = texture( textureUniform, tex );
}
