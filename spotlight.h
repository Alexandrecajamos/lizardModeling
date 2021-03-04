#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H
#include "light.h"

class SpotLight
{
public:
    SpotLight();
    SpotLight(Point *D, Light *L, float OA);

    Point *direction;
    Light *light;
    float openingAngle;

};

#endif // SPOTLIGHT_H
