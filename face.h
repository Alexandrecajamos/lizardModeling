#ifndef FACE_H
#define FACE_H
#include "point.h"
#include "transformations.h"
#include "edge.h"
#include "cube.h"
#include "cmath"

class Face
{
public:
    Face();
    Face(Point P1, Point P2, Point P3);
    Face(Point *P1, Point *P2, Point *P3);
    Point calcNormal();
    void atNormal();
    float Inter(Point P);
    Point *P1,*P2,*P3, N;
    void Barycentric(Point p, Point a, Point b, Point c, float &u, float &v, float &w);
    bool Obstaculo(Point Pint, Point ls);
    float Ray_intersept(Point Po, Point D);

    bool EdgeIntersept(Edge *E);
    float PointIntersept(Point *P);

    bool CubeIntersept(Cube *C);

    float area();
};

#endif // FACE_H
