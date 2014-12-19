#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QTimer>
#include <QTime>
#include "Triangle.h"

class Scene : public QOpenGLWidget
{
    Q_OBJECT
public:
    Scene( QWidget *parent = 0 );
    ~Scene();

private slots:
    void slotUpdate();

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void drawTriangle();

    QOpenGLShaderProgram m_program;
    int m_vertexAttr;
    int m_texCoordAttr;
    int m_matrixUniform;
    int m_texUniform;
    float m_scale;
    Triangle m_triangle;
    QTimer m_timer;
    int m_angle;
    int m_frames;
    QTime m_time;
    QOpenGLTexture *m_texture;
};

#endif // SCENE_H
