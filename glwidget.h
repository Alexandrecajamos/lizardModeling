#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <time.h>
#include <sstream>

#include <QGLWidget>
#include <QTimer>
#include "scene.h"
#include "QString"
#include "transformations.h"
#include "cube.h"
#include "face.h"
#include "mesh.h"


#include "intersection.h"

#include "QTextBrowser"
#include <fstream>
#include "intersection.h"

using namespace std;


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    QString scene_name = QString();
    Scene *scene = new Scene(scene_name);

    float Ex=10, Ey=10, Ez=10;
    float Lox=0, Loy=0, Loz=0;
    float Avx=0, Avy=1, Avz=0;

//    CSGnode *csg;
    Point *p = new Point(0,0,0);

    void LoadLizard();
    void LoadClassicCSG();
    void LoadExemploSlide();



private:
    QTimer timer;


signals:

public slots:
    void paintLocalAxis(float X, float Y, float Z);

    void paintPrimitives();
    void paintOctrees();
    void paintMeshes();

    void paintFace(Face *f);
    void paintMesh(Mesh *M);

    void paintOctreeNode(Octree *octree, OctreeNode *node);
    std::vector<Mesh*> ReadMeshes(std::string filepath);




    void Eye_X(double);
    void Eye_Y(double);
    void Eye_Z(double);
    void Lo_X(double);
    void Lo_Y(double);
    void Lo_Z(double);
    void Av_X(double);
    void Av_Y(double);
    void Av_Z(double);
};

#endif // GLWIDGET_H
