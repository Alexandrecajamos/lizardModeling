#include "edge.h"

Edge::Edge()
{

}

Edge::Edge(Point *P0, Point *P1){
    this->P0 = P0;
    this->P1 = P1;
}

Point Edge::getVector(){
    return Point(this->P1->x-this->P0->x,this->P1->y-this->P0->y,this->P1->z-this->P0->z);
}

Point Edge::getInvVector(){
    return Point(this->P0->x-this->P1->x,this->P0->y-this->P1->y,this->P0->z-this->P1->z);
}
