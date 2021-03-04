#ifndef COLORRGB_H
#define COLORRGB_H


class ColorRGB
{
public:
    ColorRGB();
    ColorRGB(float R,float G,float B);
    float R=0.5,G=0.5,B=0.5;

    void setValues(float R, float G, float B);
    void normalize();
};

#endif // COLORRGB_H
