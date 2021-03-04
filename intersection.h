#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "point.h"

class Primitive;
#include "primitive.h"

class Intersection
{
public:
    Intersection();

    Intersection(float t, Point *n, Point *Pint, Primitive *P);

    float t;
    Point *normal;
    Primitive *p;

    Point *Pintersection;


    bool operator <(Intersection *I) const {
        return (t < I->t);
    }

    bool operator >(Intersection *I) const {
        return (t > I->t);
    }

    bool operator ==(Intersection *I) const {
        return (t == I->t);
    }

};

#endif // INTERSECTION_H
