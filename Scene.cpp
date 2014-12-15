#include <QImage>
#include <QPainter>
#include <QMatrix4x4>
#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    m_scale( 10.0f ),
    m_angle( 0 ),
    m_frames( 0 )
{
    setAttribute( Qt::WA_PaintOnScreen );
    setAttribute( Qt::WA_NoSystemBackground );
    setAutoBufferSwap( false );

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );
    m_timer.start( 10 );
}

void Scene::slotUpdate()
{
    ++m_angle;

    if ( m_angle >= 360 )
        m_angle = 0;

    updateGL();
}

void Scene::initializeGL()
{
    glClearColor( 0.1f, 0.1f, 0.2f, 1.0f );

    glGenTextures( 1, &m_texID );
    m_texID = bindTexture( QImage( ":/Textures/Blocks.jpg" ) );

    QOpenGLShader vShader( QOpenGLShader::Vertex );
    vShader.compileSourceFile( ":/Shaders/vShader.glsl" );

    QOpenGLShader fShader( QOpenGLShader::Fragment );
    fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

    m_program.addShader( &vShader );
    m_program.addShader( &fShader );
    m_program.link();

    m_vertexAttr = m_program.attributeLocation( "vertex" );
    m_texCoordAttr = m_program.attributeLocation( "texCoord" );
    m_matrixUniform = m_program.uniformLocation( "matrix" );
    m_texUniform = m_program.uniformLocation( "tex" );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    glEnable( GL_DEPTH_TEST );
}

void Scene::paintGL()
{
    QPainter painter;

    painter.begin( this );
    painter.beginNativePainting();

    glClearColor( 0.1f, 0.1f, 0.2f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    QMatrix4x4 modelView;
    modelView.perspective( 60.0f, ( GLfloat ) width() / ( GLfloat ) height() , 1.0f, 400.0f );
    modelView.translate( 0.0f, 0.0f, -20.0f );
    modelView.scale( m_scale );
    modelView.rotate( m_angle, 0.0f, 1.0f, 0.0f );
    if ( !m_program.bind() )
        return;
    m_program.setUniformValue( m_matrixUniform, modelView );

    drawTriangle();

    m_program.release();

    painter.endNativePainting();

    if ( const int elapsed = m_time.elapsed() )
    {
        QString framesPerSecond;
        framesPerSecond.setNum( m_frames / ( elapsed / 1000.0 ), 'f', 2 );
        painter.setPen( Qt::white );
        painter.drawText( 20, 40, framesPerSecond + " fps" );
    }

    painter.end();

    swapBuffers();

    if ( !( m_frames % 100 ) )
    {
        m_time.start();
        m_frames = 0;
    }
//    m_fAngle += 1.0f;
    ++m_frames;
}

void Scene::resizeGL( int w, int h )
{
    glViewport( 0, 0, w, h );
}

void Scene::drawTriangle()
{
    glBindTexture( GL_TEXTURE_2D, m_texID );

    m_program.setAttributeArray( m_vertexAttr, m_triangle.vertices.data(), 3 );
    m_program.setAttributeArray( m_texCoordAttr, m_triangle.texCoords.data(), 2 );
    m_program.setUniformValue( m_texUniform, 0 );

    m_program.enableAttributeArray( m_vertexAttr );
    m_program.enableAttributeArray( m_texCoordAttr );

    glDrawArrays( GL_TRIANGLES, 0, 3 );

    m_program.disableAttributeArray( m_vertexAttr );
    m_program.disableAttributeArray( m_texCoordAttr );
}
