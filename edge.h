#ifndef EDGE_H
#define EDGE_H
#include "point.h"

class Edge
{
public:
    Edge();
    Edge(Point *P0, Point *P1);

    Point *P0, *P1;

    Point getVector();
    Point getInvVector();

};

#endif // EDGE_H
