#ifndef SPHERE_H
#define SPHERE_H
#include "point.h"
#include <QString>
#include "colorrgb.h"

class Sphere
{
public:
    Sphere();
    Sphere(QString name, float cX, float cY, float cZ, float radius);
    Sphere(QString name, float cX, float cY, float cZ, float radius, int slices, int stacks, ColorRGB *color);
    QString name;
    Point *center;
    float radius=1;
    int slices=10, stacks=10;
    ColorRGB *color;
};

#endif // SPHERE_H
