#ifndef MESH_H
#define MESH_H

#include "point.h"
#include "face.h"
#include "sphere.h"
#include "cube.h"

class Mesh
{
public:
    Mesh();

    Mesh(QString name);

    void addPoint(float x, float y, float z);
    void addFace(int iP1, int iP2, int iP3);

    float Ray_intersept(Point Po, Point Pint, int *ind);
    void attSphere();



    void ImpPoints();

    void attBBox();
    Cube* getCube();
    float mX = 0, MX =0, mY=0, MY=0, mZ=0, MZ=0;

    void Libera();

    QString name = "";
    Sphere *sphere;
    Point *center;
    std::vector<Point*> points;
    std::vector<Face*> faces;

    ColorRGB *color = new ColorRGB(0.5,0.5,0.5);

    void Scale(float fX, float fY, float fZ);
    void Translate(float fX, float fY, float fZ);
    void Rotate(int axis, float angle);
    void setToWordMatrix(float M[4][4]);
    void getToWordMatrix(float *temp_vector);


    float SurfaceArea();

    float toWordMatrix[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };

};

#endif // MESH_H
