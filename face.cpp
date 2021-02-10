#include "face.h"



Face::Face()
{

}
Face::Face(Point _P1, Point _P2, Point _P3){
    this->P1=&_P1;
    this->P2=&_P2;
    this->P3=&_P3;
    this->atNormal();
}


Face::Face(Point *_P1, Point *_P2, Point *_P3){
    this->P1=_P1;
    this->P2=_P2;
    this->P3=_P3;
    this->N = this->calcNormal();
}

Point Face::calcNormal(){

    Point p1=*(this->P1);
    Point a=*(this->P2);
    Point b=*(this->P3);
    a.operator -=(p1);
    b.operator -=(p1);

    p1.x=(a.y*b.z)-(a.z*b.y);
    p1.y=(a.z*b.x)-(a.x*b.z);
    p1.z=(a.x*b.y)-(a.y*b.x);

    return p1;

}

void Face::atNormal(){
    this->N= this->calcNormal();
}


float Face::Inter(Point P){
    float t = -1;
    float u=0,v=0,w=0;

    Point p1,p2,p3;
    p1= *(this->P1);
    p2= *(this->P2);
    p3= *(this->P3);

    Point nF = this->N;
    Point Pint = P;
    float PE = Pint.ProdutoEscalar(nF);

    this->Barycentric(P, p1,p2,p3, u,v,w);

    if(v>=0 && v<=1 && u>=0 && u<=1 && w>=0 && w<=1){
        if(PE == 0)
            t = 0;
        else
            t = (this->P1->ProdutoEscalar(nF)/PE);

    }
    return t;
}

void Face::Barycentric(Point p, Point a, Point b, Point c, float &u, float &v, float &w)
{

    Point v0 = b; Point v1 = c; Point v2 = p;
    v0.operator -=(a); v1.operator -=(a); v2.operator -=(a);

    float d00 = v0.ProdutoEscalar(v0);
    float d01 = v0.ProdutoEscalar(v1);
    float d11 = v1.ProdutoEscalar(v1);
    float d20 = v2.ProdutoEscalar(v0);
    float d21 = v2.ProdutoEscalar(v1);

    float denom = (d00 * d11) - (d01 * d01);

    v = (d11 * d20 - d01 * d21) / denom;
    w = (d00 * d21 - d01 * d20) / denom;
    u = 1-v-w;

}

float Face::Ray_intersept(Point Po, Point D){
    float t = -1;

    Point p1,p2,p3;
    p1= *(this->P1);
    p2= *(this->P2);
    p3= *(this->P3);

    Point nF = this->N;
    float PE = D.ProdutoEscalar(nF);
    if(PE<0){


        Point v1 = p2;
        Point v2 = p3;
        v1.operator -=(p1);
        v2.operator -=(p1);

        float M[3][3];
        M[0][0] = v1.x; M[1][0] = v1.y; M[2][0] = v1.z;
        M[0][1] = v2.x; M[1][1] = v2.y; M[2][1] = v2.z;
        M[0][2] = -D.x;  M[1][2] = -D.y;  M[2][2] = -D.z;
        float det = detMatrix3x3(M);
        InvMatrix3x3(M, det);
        Point b = Po;
        b.operator -=(p1);
        Point lamb = mxv(M,&b);

        float l3 = 1-(lamb.x+lamb.y);

        if(lamb.x>=0 && lamb.x<=1 && lamb.y>=0 && lamb.y<=1 && l3>=0 && l3<=1 && lamb.z>0){
            t = lamb.z;

        }

    }
    return t;
}


bool Face::EdgeIntersept(Edge *E){

    Point v = E->getVector();
    float tam = v.length();
    v.normalize();
    float d =  Ray_intersept(*E->P0, v);
    if(d>=0 && d<=tam)
        return true;
    Point invV = E->getInvVector();
    d =  Ray_intersept(*E->P1, invV);
    if(d>=0 && d<=tam)
        return true;

    return false;
}


float Face::PointIntersept(Point *P){

   Point ba = vec(this->P2, this->P1), pa = vec(P, this->P1),
         cb = vec(this->P3, this->P2), pb = vec(P, this->P2),
         ac = vec(this->P1, this->P3), pc = vec(P, this->P3);
   Point nor = cross(ba,ac);

   Point v1(ba.x, ba.y, ba.z), v2(cb.x, cb.y, cb.z), v3(ac.x, ac.y, ac.z);

   float clamp_v1 = clamp(dot(ba,pa)/dot2(ba), 0.0, 1.0),
           clamp_v2 = clamp(dot(cb,pb)/dot2(cb), 0.0, 1.0),
           clamp_v3 = clamp(dot(ac,pc)/dot2(ac), 0.0, 1.0);

   v1.operator *=(clamp_v1);
   v2.operator *=(clamp_v2);
   v3.operator *=(clamp_v3);

   v1.operator -=(pa);
   v2.operator -=(pb);
   v3.operator -=(pc);
   return sqrt(
               (std::signbit(dot(cross(ba,nor),pa)) +
                    std::signbit(dot(cross(cb,nor),pb)) +
                    std::signbit(dot(cross(ac,nor),pc))<2.0)
                    ?
                    min( min(
                             dot2(v1),
                             dot2(v2)),
                             dot2(v3)):
                   dot(nor,pa)*dot(nor,pa)/dot2(nor));
}


bool Face::CubeIntersept(Cube *C){
    bool control = false;

    std::vector<Edge*>::iterator i = C->edges.begin();
    while(!control && i!= C->edges.end()){
        Edge *e = (*i);
        control = this->EdgeIntersept(e);
        i++;
    }

//    if(!control){
//        if(C->PointClassify(this->P1)> 0 || C->PointClassify(this->P2)> 0 || C->PointClassify(this->P3)> 0 )
//            control = true;
//    }
    return control;
}

float Face::area(){
//    this->atNormal();
    return this->N.length();
}
