#include "material.h"

Material::Material()
{
    this->A = ColorRGB(0.4196,0.5568,0.1372);
    this->D = ColorRGB(0.4196,0.5568,0.1372);
    this->E = ColorRGB(0.4196,0.5568,0.1372);
    this->m = 1;

}
Material::Material(ColorRGB _A, ColorRGB _D, ColorRGB _E, int _m){
    this->A=_A;
    this->D=_D;
    this->E=_E;
    this->m=_m;

}
