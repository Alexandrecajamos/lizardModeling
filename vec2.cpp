#include "vec2.h"

Vec2::Vec2()
{

}
Vec2::Vec2(float x, float y){
    this->x=x;
    this->y=y;
}

float Vec2::length(){
    return sqrt((this->x*this->x)+(this->y*this->y));
}
