#include "sphere.h"

Sphere::Sphere()
{

}
Sphere::Sphere(QString name, float cX, float cY, float cZ, float radius){
    this->name = name;
    this->center = new Point(cX, cY, cZ);
    this->radius=radius;
    this->slices=10;
    this->stacks=10;
    this->color = new ColorRGB(0.5,0.5,0.5);
}
Sphere::Sphere(QString name, float cX, float cY, float cZ, float radius, int slices, int stacks, ColorRGB *color){
    this->name = name;
    this->center = new Point(cX, cY, cZ);
    this->radius=radius;
    this->slices=slices;
    this->stacks=stacks;
    this->color=color;
}
