#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "transformations.h"
#include <QString>
#include "colorrgb.h"
#include "point.h"
#include<vector>
#include "cube.h"
#include "vec2.h"
class Primitive
{
public:
    Primitive();

//    Primitive(QString name, float size);

//    Primitive(QString name, float radius, float slices, float stacks);
//    Primitive(QString name, float base, float height, float slices, float stacks);

//    Primitive(QString name, float sizeX, float sizeY, float sizeZ, int add);

    Primitive(QString name, int type, float size,float sizeX, float sizeY,float sizeZ, float radius, float base, float height,float slices, float stacks, float R, float G, float B);

//    Primitive(QString name, Point* VMin, Point* vMax);

    QString name = "";
    ColorRGB *color = new ColorRGB(0.5,0.5,0.5);

    void Scale(float fX, float fY, float fZ);
    void Translate(float fX, float fY, float fZ);
    void Rotate(int axis, float angle);
    void setToWordMatrix(float M[4][4]);
    void getToWordMatrix(float *temp_vector);



    float getVolume();
    float getArea();

    bool PointIntersect(float COx, float COy, float COz);
    bool PointIntersect(Point *P);
    bool PointInBorder(Point *P);

    float PointInCone(Point *P);
    int PointInCylinder(Point *P);

    int PointClassify(Point *P);

    bool CubeIntersect(Cube *Cube);

    bool IsInnerPoint(Point *P);


    Cube* getWrap();

//    int CubeClassify(Cube *Cube); //0 - in; 1 - on; 2 - out;


    int type = 0; // 0 - Cube; 1 - Sphere; 2 - Cone; 3 - Cylinder; 4 - Box;
    float size = 0, radius = 0, base=0, height=0, sizeX=0, sizeY=0, sizeZ=0;
    int slices=0, stacks=0;

    float toWordMatrix[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
};

#endif // PRIMITIVE_H
