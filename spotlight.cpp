#include "spotlight.h"

SpotLight::SpotLight()
{

    this->direction = new Point(0,0,-1);
    this->light = new Light(ColorRGB(1,1,1), new Point(100,100,100));
    this->openingAngle = 45;

}
SpotLight::SpotLight(Point *D, Light *L, float OA){
    this->direction = D;
    this->light = L;
    this->openingAngle = OA;
}
