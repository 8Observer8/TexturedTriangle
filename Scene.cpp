#include <QDebug>
#include <QMatrix4x4>
#include <QPixmap>
#include "Scene.h"
#include "glFunctions.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    m_program( 0 )
{
}

Scene::~Scene()
{
    delete m_texture;
}

void Scene::initializeGL()
{
    glFunctions.initializeOpenGLFunctions();
    m_program = new QOpenGLShaderProgram( this );
    m_program->addShaderFromSourceFile( QOpenGLShader::Vertex, ":/Shaders/vShader.glsl" );
    m_program->addShaderFromSourceFile( QOpenGLShader::Fragment, ":/Shaders/fShader.glsl" );
    if ( !m_program->link() )
    {
        qWarning( "Error: unable to link a shader program" );
        return;
    }
    m_posAttr = m_program->attributeLocation( "posAttr" );
    m_texAttr = m_program->attributeLocation( "textureAttr" );
    m_textureUniform = m_program->uniformLocation( "textureUniform" );
    m_matrixUniform = m_program->uniformLocation( "matrix" );


//    // Устанавливает режим проверки глубины пикселей
//    glEnable( GL_DEPTH_TEST );

//    // Отключает режим сглаживания цветов
//    glShadeModel( GL_FLAT );

//    // Устанавливаем режим, когда строятся только внешние поверхности
//    glEnable( GL_CULL_FACE );

//    glEnable( GL_TEXTURE_2D );


    // Generate the textures
    m_textureID = bindTexture( QPixmap( QString( ":/Textures/Stub.jpg" ) ), GL_TEXTURE_2D );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );


    // Активизация массива вершин
    //glEnableClientState( GL_VERTEX_ARRAY );

    // Активизация массива текстурных координат
    //glEnableClientState( GL_TEXTURE_COORD_ARRAY );


//    m_texture = new QOpenGLTexture( QOpenGLTexture::Target2D );
//    m_texture->setData( QImage( ":Textures/Stub.jpg" ) );
//    m_texture->setWrapMode( QOpenGLTexture::DirectionS, QOpenGLTexture::ClampToEdge );
//    m_texture->setWrapMode( QOpenGLTexture::DirectionT, QOpenGLTexture::ClampToEdge );

//    m_texture->setMinificationFilter( QOpenGLTexture::LinearMipMapLinear );
//    m_texture->setMagnificationFilter( QOpenGLTexture::Linear );
//    m_texture->bind();
//    m_textureID = QOpenGLTexture::boundTextureId( QOpenGLTexture::BindingTarget2D );
//    if ( !m_texture->isBound() )
//    {
//        qWarning( "Error: unable to bound a texture" );
//        return;
//    }
    //int id = m_texture->boundTextureId()
}

void Scene::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    if ( !m_program->bind() )
        return;

    QMatrix4x4 matrix;
    matrix.perspective( 60.0f, 4.0f/3.0f, 0.1f, 100.0f );
    matrix.translate( 0.0f, 0.0f, -2.0f );
    m_program->setUniformValue( m_matrixUniform, matrix );

    glFunctions.glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, m_textureID );
    m_program->setUniformValue( m_textureUniform, 0 );

    m_triangle.draw( m_posAttr, m_texAttr );

    m_program->release();
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}
