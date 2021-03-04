#include "observer.h"


Observer::Observer()
{
    Point _pos(0,0,0);
    this->Pos = _pos;
    Point _i(1,0,0);
    this->i=i;
    Point _j(0,1,0);
    this->j=_j;
    Point _k(0,0,1);
    this->k=_k;

}

Observer::Observer(Point _pos, Point Look_At, Point A_View_UP){

    this->Pos=_pos;
    Point pk = _pos;
    pk.operator -=(Look_At);
    pk.normalize();
    this->k=pk;
    Point px= A_View_UP;
    px.operator -=(this->Pos);
    Point _x = normal(px,pk);
    _x.normalize();

    this->i=_x;
    this->j=normal(this->k, this->i);

}


void Observer::Cam_Word(float A[TAM][TAM]){

    float I[3] = {i.x,i.y, i.z};
    float J[3] = {j.x,j.y, j.z};
    float K[3] = {k.x,k.y, k.z};
    float P[3] = {Pos.x,Pos.y, Pos.z};
    getIdentity(A);

    for(int i=0;i<3;i++){
        A[i][0]=I[i];
        A[i][1]=J[i];
        A[i][2]=K[i];
        A[i][3]=P[i];

    }

}

void Observer::Word_Cam(float A[TAM][TAM]){

    float I[3] = {i.x,i.y, i.z};
    float J[3] = {j.x,j.y, j.z};
    float K[3] = {k.x,k.y, k.z};
    getIdentity(A);
    for(int i=0;i<3;i++){
        A[0][i]=I[i];
        A[1][i]=J[i];
        A[2][i]=K[i];
    }
    float x = this->i.ProdutoEscalar(this->Pos);
    float y = this->j.ProdutoEscalar(this->Pos);
    float z = this->k.ProdutoEscalar(this->Pos);
    A[0][3]=-x;
    A[1][3]=-y;
    A[2][3]=-z;
}
