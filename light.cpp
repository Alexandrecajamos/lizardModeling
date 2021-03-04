#include "light.h"

Light::Light()
{

}

Light::Light(ColorRGB color, Point *pos)
{
    this->fontColor = color;
    this->Pos = pos;
}
