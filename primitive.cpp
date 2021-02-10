#include "primitive.h"

Primitive::Primitive()
{

}

//Primitive::Primitive(QString name, float size){
//    this->type=0;
//    this->name=name;
//    this->size=size;

//    this->sizeX=size;
//    this->sizeY=size;
//    this->sizeZ=size;
//    float f = size/2;
//    Point P0(f,f,f);
//    this->radius=P0.length();


//}
//Primitive::Primitive(QString name, float radius, float slices, float stacks){
//    this->name=name;
//    this->type=1;
//    this->radius=radius;
//    this->slices=slices;
//    this->stacks=stacks;
//}
//Primitive::Primitive(QString name, float base, float height, float slices, float stacks){
//    this->name=name;
//    this->type=2;
//    this->base=base;
//    this->height=height;
//    this->slices=slices;
//    this->stacks=stacks;
//}
//Primitive::Primitive(QString name, float sizeX, float sizeY, float sizeZ, int add){
//    this->type=4;
//    this->name=name;
//    this->sizeX = sizeX;
//    this->sizeY = sizeY;
//    this->sizeZ = sizeZ;
//    add=0;
//}

Primitive::Primitive(QString name, int type, float size,float sizeX,float sizeY,float sizeZ, float radius, float base, float height, float slices, float stacks, float R, float G, float B){
    this->name = name;
    this->type=type;
    this->size=size;
    this->sizeX=sizeX;
    this->sizeY=sizeY;
    this->sizeZ=sizeZ;
    this->radius=radius;
    this->base = base;
    this->height=height;
    this->slices=slices;
    this->stacks=stacks;
    this->color->R=R;
    this->color->G=G;
    this->color->B=B;
}
void Primitive::Translate(float fX, float fY, float fZ){
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
void Primitive::Scale(float fX, float fY, float fZ){
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
void Primitive::Rotate(int axis, float angle){
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

void Primitive::setToWordMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->toWordMatrix[i][j] = M[i][j];
}
void Primitive::getToWordMatrix(float *temp_vector){
    int c=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            temp_vector[c]=this->toWordMatrix[j][i];
            c++;
        }
}
float Primitive::getVolume(){
    float volume = 0;
    switch (this->type) {
    case 0:
        volume = this->size*this->size*this->size;
        break;
    case 1:
        volume = (4*PI*(this->radius*this->radius*this->radius))/3;
        break;
    case 2:
        volume = (PI*(this->base*this->base)*this->height)/3;
        break;
    case 3:
        volume = (this->height*PI*(this->base*this->base));
        break;
    case 4:
        volume = this->sizeX*this->sizeY*this->sizeZ;
        break;
    default:
        break;
    }
    return volume;
}
float Primitive::getArea(){
    float area = 0;
    float g=0;
    switch (this->type) {
    case 0:
        area = 6*(this->size*this->size);
        break;
    case 1:
        area = 4*PI*(this->radius*this->radius);
        break;
    case 2:
        g = sqrt((this->base*this->base)+(this->height*this->height));
        area = PI*this->base*(g+this->base);
        break;
    case 3:
        area = 2*PI*this->base*(this->base+this->height);
        break;
    case 4:
        area = (2*sizeX*sizeZ)+(2*sizeX*sizeY)+(2*sizeY*sizeZ);
        break;
    default:
        break;
    }
    return area;
}
float Primitive::PointInCone(Point *P){


    Vec2 Pxy(P->x, P->y);

    if(Pxy.length() > this->base || P->z > this->height || P->z < 0)
        return 0;

    else
        return 1;



//    float hip=0, sin=0, cos=0;
//    float k=0, d=0, s=0;

//    Vec2 Pxz(P->x, P->z);

//     float q = Pxz.length();
//     return max(dot(Vec2(),Vec2(q,P->y)),-this->height-P->y);

//    Vec2 *q, *w, *a, *b, *temp;
//    hip = sqrt((this->base*this->base)+(this->height*this->height));
//    sin = this->base/hip;
//    cos = this->height/hip;
//    q = new Vec2(sin/cos, -1); q->operator *=(this->height);
//    w = new Vec2(Pxz.length(), P->y);
//    temp = new Vec2(q->x, q->y);
//    temp->operator *=(clamp(dot(*w,*q)/dot(*q,*q), 0.0, 1.0));
//    a = new Vec2(w->x, w->y);
//    a->operator -=(*temp);
//    b = new Vec2(w->x, w->y);
//    free(temp);
//    temp = new Vec2(q->x*clamp(w->x/q->x, 0.0, 1.0), q->y);
//    b->operator -=(*temp);

//    k = signbit(q->y);
//    d = min(dot(*a,*a), dot(*b,*b));
//    s = max(k*(w->x*q->y-w->y*q->x),k*(w->y-q->y));
//    return sqrt(d)*signbit(s);

}
int Primitive::PointClassify(Point *P){

    int intersect = 0;

    Vec2 Pxy(P->x, P->y);
    float Plength = P->length();
    float fx =0, fy =0, fz =0;
    float Rl = 0, Hl=0, V=0, v=0;

    switch (this->type) {
    case 0:
        fx = fy = fz = this->size/2;
        if(P->x <= fx && P->y <= fy  && P->z <= fz && P->x >= -fx && P->y >= -fy  && P->z >= -fz){
            if(P->x == fx || P->y == fy  || P->z == fz || P->x == -fx || P->y == -fy  || P->z == -fz)
                intersect = 1;
            else
                intersect = 2;
        }
        else
            intersect = 0;
        break;
    case 1:
        if(Plength<this->radius)
            intersect = 2;
        else if(Plength == this->radius)
            intersect = 1;
        else
            intersect = 0;
        break;
    case 2:
        Plength = Pxy.length();
        if(P->z > this->height || P->z < 0 || Plength > this->base)
            intersect = 0;
        else if(P->z == 0 && Plength <= this->base)
            intersect = 1;
        else if((P->z == this->height && Plength>0)||(P->z==0 && Plength>this->base))
                intersect = 0;
        else
        {
            // Verifico o volume do cone superior (Como se um plano no eixo Z, onde o ponto P está localizado, cortasse o cubo em 2: Cone Superior e Tronco de Cone - inferior);
            //O volume do cone superior é calculado a partir do volume total, Lembrando que a razão entre sólidos semelhantes é igual ao cubo da razão de semelhança; v/V = (razão)³
            V = (PI*(this->base*this->base)*this->height)/3; //Volume Total;
            Hl=this->height-P->z; // Altura do Cone superior
            v = ((Hl*Hl*Hl)/(this->height*this->height*this->height))*V; // v = Razão ao Cubo vezes o Volume Total;
            //Dado o Volume do cone superior, encontro o respectivo Raio (Rl) e verifico se o ponto está dentro do "círculo" da respectiva fatia do Cone;
            Rl = sqrt((3*v)/(PI*Hl));
            if(Plength > Rl)
                return 0;
            if(Plength == Rl)
                return 1;
            else
            intersect = 2;
        }break;
    case 3:
        Plength = Pxy.length();
        if(P->z > this->height || P->z < 0 || Plength > this->base)
            intersect = 0;
        else if(P->z == this->height || P->z < 0 || Plength == this->base)
            intersect = 1;
        else
            intersect = 2;
        break;
    case 4:
        fx = this->sizeX/2;
        fy = this->sizeY/2;
        fz = this->sizeZ/2;
        if(P->x <= fx && P->y <= fy  && P->z <= fz && P->x >= -fx && P->y >= -fy  && P->z >= -fz){
            if(P->x == fx || P->y == fy  || P->z == fz || P->x == -fx || P->y == -fy  || P->z == -fz)
                intersect = 1;
            else
                intersect = 2;
        }
        else
            intersect = 0;
        break;
    default:
        break;
    }
    return intersect;
}
bool Primitive::PointIntersect(Point *P){
    bool intersect = false;
    Point *p_teste;


//    Vec2()



    switch (this->type) {
    case 0:
        p_teste = new Point(this->size/2,this->size/2,this->size/2);
        if(P->length()<=p_teste->length())
            intersect = true;
        break;
    case 1:
        if(P->length()<=this->radius)
            intersect = true;
        break;
    case 2:

        intersect = PointInCone(P);
        break;
    case 4:
        intersect = false;
        break;
    default:
        break;
    }
    return intersect;
}
bool Primitive::PointInBorder(Point *P){
    bool intersect = false;
    Point *p_teste;



    switch (this->type) {
    case 0:
        p_teste = new Point(this->size/2,this->size/2,this->size/2);
        if(P->length()==p_teste->length())
            intersect = true;
        break;
    case 1:
        if(P->length()==this->radius)
            intersect = true;
        break;
    case 2:
        intersect = false;
        break;
    case 4:
        intersect = false;
        break;
    default:
        break;
    }
    return intersect;
}
Cube* Primitive::getWrap(){
    float cubeSize = 0;
    float cX = 0, cY=0, cZ=0;

    switch (this->type) {
    case 0:
        cubeSize=this->size;
        break;
    case 1:
        cubeSize=this->radius*2;
        break;

    case 2:
        if((this->base*2)>this->height)
            cubeSize=this->base*2;
        else
            cubeSize=this->height;
        cZ=this->height/2;
        break;

    case 3:
        if((this->base*2)>this->height)
            cubeSize=this->base*2;
        else
            cubeSize=this->height;
        cZ=this->height/2;
        break;
    case 4:
        cubeSize = max(sizeX,max(sizeY,sizeZ));
        break;
    default:
        break;
    }

    return new Cube("",cX,cY,cZ,cubeSize);
}
bool Primitive::CubeIntersect(Cube *Cube){
    bool intersect = false;
    switch (this->type) {
    case 0:
        intersect = true;
        break;
    case 1:
        if(Cube->center->length()<=this->radius)
            intersect = true;
        else{
            std::vector<Point*>::iterator i = Cube->vertices.begin();
            while(!intersect && i!= Cube->vertices.end()){
                intersect = this->PointIntersect(*i);
                i++;
            }
        }
        break;
    case 2:
        intersect = false;
        break;
    case 4:
        intersect = false;
        break;
    default:
        break;
    }
    return intersect;
}
