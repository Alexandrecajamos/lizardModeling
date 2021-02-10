#include "point.h"

Point::Point()
{

}
Point::Point(float _x, float _y, float _z) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

float Point::ProdutoEscalar(Point P){
    float x= (this->x*P.x)+(this->y*P.y)+(this->z*P.z);
    return x;
}
void Point::ImpPoint(){
    std::cout << "\nCoor.: " << this->x <<", "<< this->y<<", "<< this->z <<"; ";
}

void Point::translate(float fX, float fY, float fZ){
    this->x+=fX;
    this->y+=fY;
    this->z+=fZ;
}

float Point::length(){
    return sqrt((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
}

void Point::transform(float M[4][4]){
    float vP[4]={this->x, this->y, this->z,1};
       float vPt[4]={0,0,0,0};
       for(int i=0;i<4-1;i++){
           for(int j=0;j<4;j++)
               vPt[i]+=M[i][j]*vP[j];
       }
       this->x=vPt[0];
       this->y=vPt[1];
       this->z=vPt[2];
}


