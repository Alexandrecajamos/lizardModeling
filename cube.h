#ifndef CUBE_H
#define CUBE_H

#include <QString>
//#include "point.h"


#include "transformations.h"
#include <vector>
#include "edge.h"

class Cube
{
public:
    Cube();
    Cube(QString name, float cX, float cY, float cZ, float size);


    Cube(QString name, Point *Pmin, Point* Pmax);

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


    Point * getPmin();
    Point * getPmax();

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

    void setToWordMatrix(float M[4][4]);
    void setWlMatrix(float M[4][4]);
    void getToWordMatrix(float *temp_vector);


};

#endif // CUBE_H
