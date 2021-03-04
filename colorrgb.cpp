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

void ColorRGB::normalize(){
    if(this->R>1)
        this->R=1;
    if(this->G>1)
        this->G=1;
    if(this->B>1)
        this->B=1;
}
