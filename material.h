#ifndef MATERIAL_H
#define MATERIAL_H
#include "colorrgb.h"

class Material
{
public:
    Material();
    Material(ColorRGB A, ColorRGB D, ColorRGB E, int m);

    ColorRGB A,D,E;
    int m;
};

#endif // MATERIAL_H
