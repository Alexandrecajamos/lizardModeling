#ifndef LIGHT_H
#define LIGHT_H
#include "point.h"
#include "colorrgb.h"

class Light
{
public:
    Light();
    Light(ColorRGB Color, Point *Pos);
    ColorRGB fontColor;
    Point *Pos;
};

#endif // LIGHT_H
