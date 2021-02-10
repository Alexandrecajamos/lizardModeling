#ifndef VEC2_H
#define VEC2_H

#include "cmath"

class Vec2
{
public:
    Vec2();
    Vec2(float x, float y);


    Vec2 operator+(Vec2 P) const {
              return Vec2(x + P.x, y + P.y);
    }
    Vec2& operator+=(Vec2 P) {
              x += P.x; y += P.y;
              return *this;
          }
    Vec2& operator*=(float Esc) {
              x *= Esc; y *= Esc;
              return *this;
          }
    Vec2& operator-=(Vec2 P){
              x -= P.x; y -= P.y;
              return *this;
          }
    Vec2 operator/(float div) const {
              return Vec2(x/div, y/div);
          }
    Vec2& operator/=(float div) {
              x /= div; y/= div;
              return *this;
          }

    void normalize(){
        float len = sqrt(x*x + y*y);
        x/=len; y /= len;
    }

    float length();


    float x=0, y=0;


};

#endif // VEC2_H
