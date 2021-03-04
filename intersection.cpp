#include "intersection.h"

Intersection::Intersection()
{

}

Intersection::Intersection(float t, Point *n, Point *Pint, Primitive *P){
    this->t=t;
    this->normal=n;
    this->p=P;
    this->Pintersection = Pint;
}
