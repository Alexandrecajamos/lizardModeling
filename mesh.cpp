#include "mesh.h"

Mesh::Mesh()
{
    this->center= new Point(0,0,0);
    this->sphere = new Sphere(this->name+"_sphere", 0,0,0,1);

}


Mesh::Mesh(QString name)
{
    this->name = name;
    this->center= new Point(0,0,0);
    this->sphere = new Sphere(this->name+"_sphere", 0,0,0,1);
}

void Mesh::addPoint(float x, float y, float z){
   Point *p = new Point(x,y,z);
   this->points.push_back(p);
//    if(this->points.size() == 0){
//        this->mX = x;this->MX = x;
//        this->mY = y;this->MY = y;
//        this->mZ = z;this->MZ = z;
//        this->center->x=x; this->center->y=y; this->center->z=z;
//    }else{

//        if(x<this->mX)
//            this->mX = x;
//        if(x>this->MX)
//            this->MX = x;
//        if(y<this->mY)
//            this->mY = y;
//        if(y>this->MY)
//            this->MY = y;
//        if(z<this->mZ)
//            this->mZ = z;
//        if(z>this->MZ)
//            this->MZ = z;

//        this->center->x = (this->MX+this->mX)/2;
//        this->center->y = (this->MY+this->mY)/2;
//        this->center->z = (this->MZ+this->mZ)/2;

//    }



}
void Mesh::addFace(int iP1, int iP2, int iP3){
    Face *F = new Face(this->points.at(iP1),this->points.at(iP2),this->points.at(iP3));
    this->faces.push_back(F);
}

void Mesh::attSphere(){

    this->sphere->center->x=this->center->x;
    this->sphere->center->y=this->center->y;
    this->sphere->center->z=this->center->z;

    float dx = std::abs(this->MX)+std::abs(this->mX);
    float dy = std::abs(this->MY)+std::abs(this->mY);
    float dz = std::abs(this->MZ)+std::abs(this->mZ);

    float d = 0;
    if(dx>dy && dx>dz)
            d = dx;
        else if(dy>dz)
            d = dy;
        else
            d = dz;

    this->sphere->radius=d/2;

}

void Mesh::attBBox(){

    float mX=this->points.at(0)->x;
    float mY=this->points.at(0)->y;
    float mZ=this->points.at(0)->z;
    float MX=mX;float MY=mY;float MZ=mZ;
    for(std::vector<Point*>::iterator i = this->points.begin(); i!= this->points.end(); i++)
    {
        float x = (*i)->x;float y = (*i)->y;float z = (*i)->z;
        if(x<mX)
            mX = x;
        if(x>MX)
            MX = x;
        if(y<mY)
            mY = y;
        if(y>MY)
            MY = y;
        if(z<mZ)
            mZ = z;
        if(z>MZ)
            MZ = z;
    }
    this->mX=mX;
    this->mY=mY;
    this->mZ=mZ;
    this->MX=MX;
    this->MY=MY;
    this->MZ=MZ;

    this->center->x = (this->MX+this->mX)/2;
    this->center->y = (this->MY+this->mY)/2;
    this->center->z = (this->MZ+this->mZ)/2;
}


Cube* Mesh::getCube(){
//    std::cout << "\nTeste abs: "<< std::abs(this->MX)<<", " <<std::abs(this->mX);
    float dx = (std::abs(this->MX)+std::abs(this->mX));
    float dy = (std::abs(this->MY)+std::abs(this->mY));
    float dz = (std::abs(this->MZ)+std::abs(this->mZ));
//    std::cout <<"\nTeste: "<< dx << ", " << dy << ", " << dz;
    this->center->ImpPoint();
    float d = 0;
    if(dx>dy && dx>dz)
            d = dx;
        else if(dy>dz)
            d = dy;
        else
            d = dz;

    return new Cube("",this->center->x,this->center->y,this->center->z, d);
}

float Mesh::Ray_intersept(Point Po, Point Pint, int *idx){

    float t = -1;
    float Menor_T=999;
    int cont=0;

//    if(this->sphere-.Interseccao(Pint)){
        for(std::vector<Face*>::iterator i = this->faces.begin(); i!= this->faces.end(); i++){
            float x = (*i)->Ray_intersept(Po, Pint);//Inter(Pint);
            if(x != -1 && x<Menor_T){
                Menor_T = x;
                (*idx) = cont;
            }
            cont++;
        }
        if(Menor_T != 999)
            t=Menor_T;
//    }

    return t;
}
//void Mesh::Transforoma(float A[TAM][TAM]){
//    transformacoes t;
//    for(std::vector<Point*>::iterator i = this->points.begin(); i!= this->points.end(); i++){
//        t.MxV(A,(*i));
//    }

//    //for(std::vector<Face*>::iterator f = this->faces.begin(); f!=this->faces.end();f++){
//       // (*f)->atNormal();
//    //}

//    this->calc_Esfera();
//}


void Mesh::ImpPoints(){
    std::cout << "\n Imprimindo Pontos do Objeto:"<< this->name.toStdString();
    for(std::vector<Point*>::iterator i = this->points.begin(); i!= this->points.end(); i++)
    {
        Point *P = (*i);
        std::cout << "\nx,y,z = " << P->x << ", " << P->y << ", " << P->z <<";";

    }

}


void Mesh::Libera(){
    for(std::vector<Point*>::iterator i = this->points.begin(); i!= this->points.end(); i++)
    {
        free(*i);
        (*i)=NULL;
    }
    for(std::vector<Face*>::iterator i = this->faces.begin(); i!= this->faces.end(); i++){
        //(*i)->M=NULL;
        (*i)->P1=NULL;
        (*i)->P2=NULL;
        (*i)->P3=NULL;
        //(*i)->N=NULL;
        free(*i);
        (*i)=NULL;
    }
}


void Mesh::getToWordMatrix(float *temp_vector){
    int c=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            temp_vector[c]=this->toWordMatrix[j][i];
            c++;
        }
}


void Mesh::Translate(float fX, float fY, float fZ){
    float translateMatrix[4][4] = { {1.0f, 0.0f, 0.0f, fX},
                                    {0.0f, 1.0f, 0.0f, fY},
                                    {0.0f, 0.0f, 1.0f, fZ},
                                    {0.0f, 0.0f, 0.0f, 1.0f }};

    float tempMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                               {0.0f, 1.0f, 0.0f, 0.0f},
                               {0.0f, 0.0f, 1.0f, 0.0f},
                               {0.0f, 0.0f, 0.0f, 1.0f }};
   for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            tempMatrix[i][j] = this->toWordMatrix[i][j];

    multiplyMatrix(tempMatrix, translateMatrix,this->toWordMatrix);
}
void Mesh::Scale(float fX, float fY, float fZ){
    float scaleMatrix[4][4] = { {fX, 0.0f, 0.0f, 0.0f},
                                {0.0f, fY, 0.0f, 0.0f},
                                {0.0f, 0.0f, fZ, 0.0f},
                                {0.0f, 0.0f, 0.0f, 1.0f}};

    float tempMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                               {0.0f, 1.0f, 0.0f, 0.0f},
                               {0.0f, 0.0f, 1.0f, 0.0f},
                               {0.0f, 0.0f, 0.0f, 1.0f }};

    for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            tempMatrix[i][j] = this->toWordMatrix[i][j];

    multiplyMatrix(tempMatrix, scaleMatrix,this->toWordMatrix);
}
void Mesh::Rotate(int axis, float angle){
    float rotateMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                                {0.0f, 1.0f, 0.0f, 0.0f},
                                {0.0f, 0.0f, 1.0f, 0.0f},
                                {0.0f, 0.0f, 0.0f, 1.0f}};

    getRotation(angle, axis, rotateMatrix);

    float tempMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                               {0.0f, 1.0f, 0.0f, 0.0f},
                               {0.0f, 0.0f, 1.0f, 0.0f},
                               {0.0f, 0.0f, 0.0f, 1.0f }};
    for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            tempMatrix[i][j] = this->toWordMatrix[i][j];

    multiplyMatrix(tempMatrix, rotateMatrix,this->toWordMatrix);
}

void Mesh::setToWordMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->toWordMatrix[i][j] = M[i][j];
}

float Mesh::SurfaceArea(){
    float sA = 0;
    for(std::vector<Face*>::iterator i = this->faces.begin(); i != this->faces.end(); i++){
        sA += (*i)->area();
    }
    return sA;
}
