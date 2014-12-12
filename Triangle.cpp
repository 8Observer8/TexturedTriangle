#include "Triangle.h"
#include <GL/gl.h>
#include <QPixmap>

Triangle::Triangle()
{
    initVertices();
    initColors();
    initTexture();
}

void Triangle::initVertices()
{
    vertices.clear();
    vertices.resize( 6 );
    // 0
    vertices[0] = 0.0f;
    vertices[1] = 0.5f;
    // 1
    vertices[2] = -0.5f;
    vertices[3] = -0.5f;
    // 2
    vertices[4] = 0.5f;
    vertices[5] = -0.5f;
}

void Triangle::initColors()
{
//    colors.clear();
//    colors.resize( 9 );
//    // 0
//    colors[0] = 1.0f;
//    colors[1] = 0.0f;
//    colors[2] = 0.0f;
//    // 1
//    colors[3] = 0.0f;
//    colors[4] = 1.0f;
//    colors[5] = 0.0f;
//    // 2
//    colors[6] = 0.0f;
//    colors[7] = 0.0f;
//    colors[8] = 1.0f;
}

void Triangle::initTexture()
{
    textureCoords.clear();
    textureCoords.resize( 6 );
    textureCoords[0.5f];
    textureCoords[1.0f];

    textureCoords[0.0f];
    textureCoords[0.0f];

    textureCoords[1.0f];
    textureCoords[0.0f];

//    textureID = bindTexture( QPixmap( QString( ":Textures/Stub.jpg" ) ), GL_TEXTURE_2D );
//    glFunctions.glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
//    glFunctions.glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
}

size_t Triangle::numOfVertices() const
{
    return 3;
}

void Triangle::draw( int posAttr, int textureAttr ) const
{
    glFunctions.glVertexAttribPointer( posAttr, 2, GL_FLOAT, GL_FALSE, 0, vertices.data() );
    glFunctions.glVertexAttribPointer( textureAttr, 2, GL_FLOAT, GL_FALSE, 0, textureCoords.data() );

    glFunctions.glEnableVertexAttribArray( posAttr );
    glFunctions.glEnableVertexAttribArray( textureAttr );

    glFunctions.glDrawArrays( GL_TRIANGLES, 0, 3 );

    glFunctions.glDisableVertexAttribArray( textureAttr );
    glFunctions.glDisableVertexAttribArray( posAttr );
}
