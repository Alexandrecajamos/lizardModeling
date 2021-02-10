#include "colorrgb.h"

ColorRGB::ColorRGB()
{

}

ColorRGB::ColorRGB(float R, float G, float B){
    this->R=R;
    this->G=G;
    this->B=B;
}

void ColorRGB::setValues(float R, float G, float B){
    this->R=R;
    this->G=G;
    this->B=B;
}
