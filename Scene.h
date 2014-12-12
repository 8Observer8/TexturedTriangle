#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include "Triangle.h"

class Scene : public QGLWidget
{
public:
    Scene( QWidget *parent = 0 );
    ~Scene();

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    QOpenGLShaderProgram *m_program;
    QOpenGLTexture *m_texture;

    GLint m_posAttr;
    GLint m_texAttr;
    GLint m_textureUniform;
    GLint m_matrixUniform;
    GLuint m_textureID;

    Triangle m_triangle;
};

#endif // SCENE_H
