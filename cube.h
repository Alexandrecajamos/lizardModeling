#ifndef CUBE_H
#define CUBE_H

#include <QString>
#include "point.h"
#include "transformations.h"
#include <vector>
#include "edge.h"

class Cube
{
public:
    Cube();
    Cube(QString name, float cX, float cY, float cZ, float size);

    QString name;
    Point *center;
    std::vector<Point*> vertices;
    std::vector<Edge*> edges;

    float size=1;

    void Transform(float M[4][4]);

    void printVertices();


    int PointClassify(Point *P);
    float getVolume();
    float getArea();

    std::vector<Cube*> Divide8(); //Return 8 centroids;
    int Classified_points[8] = {0,0,0,0,0,0,0,0};




};

#endif // CUBE_H
