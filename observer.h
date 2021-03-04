#ifndef OBSERVER_H
#define OBSERVER_H
#include "point.h"
#include "transformations.h"
class Observer
{
public:
    Observer();
    Observer(Point Pos, Point Look_At, Point A_View_UP);

    Point Pos,i,j,k;
    void Word_Cam(float M[TAM][TAM]);
    void Cam_Word(float M[TAM][TAM]);
};

#endif // OBSERVER_H
