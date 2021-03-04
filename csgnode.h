#ifndef CSGNODE_H
#define CSGNODE_H
#include "primitive.h"
#include "intersection.h"

class CSGnode
{
public:
    CSGnode();
    CSGnode(QString name, CSGnode *L, CSGnode *R, int BoolOpr);
    CSGnode(Primitive *P);

    QString name = "";
    CSGnode *left;
    CSGnode *right;
    Primitive *primitive;
    bool isLeaf;
    int boolOpr; // 0 - União, 1 - Interseção ou 2 - Diferença;

//    bool Ray_intersept(Point Po, Point D);
    bool PointIntersect(Point *P);

    QString getEquation();


    int PointClassify(Point *P);
    Cube* getWrap();


    float toWordMatrix[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };

    float Wl[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };

    void Scale(float fX, float fY, float fZ);
    void Translate(float fX, float fY, float fZ);
    void Rotate(int axis, float angle);

    void setToWordMatrix(float M[4][4]);
    void setWlMatrix(float M[4][4]);
    void getToWordMatrix(float *temp_vector);



    bool Ray_intersept(Point Po, Point D, float &tmin0, float &tmin1, float &tmax0, float &tmax1);

    std::vector<Intersection*> Ray_intersept(Point Po, Point D);

};

#endif // CSGNODE_H
