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

    this->material = new Material(*this->color, *this->color, *this->color, 1);

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


    // Now att Wl:

    float Tl[4][4] = { {1.0f, 0.0f, 0.0f, -fX},
                                    {0.0f, 1.0f, 0.0f, -fY},
                                    {0.0f, 0.0f, 1.0f, -fZ},
                                    {0.0f, 0.0f, 0.0f, 1.0f }};

    float aux[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                               {0.0f, 1.0f, 0.0f, 0.0f},
                               {0.0f, 0.0f, 1.0f, 0.0f},
                               {0.0f, 0.0f, 0.0f, 1.0f }};
   for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            aux[i][j] = this->Wl[i][j];

    multiplyMatrix(Tl, aux,this->Wl);
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

    // Now get Wl:

    float sl[4][4] = { {1/fX, 0.0f, 0.0f, 0.0f},
                       {0.0f, 1/fY, 0.0f, 0.0f},
                       {0.0f, 0.0f, 1/fZ, 0.0f},
                       {0.0f, 0.0f, 0.0f, 1.0f}};

    float aux[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                               {0.0f, 1.0f, 0.0f, 0.0f},
                               {0.0f, 0.0f, 1.0f, 0.0f},
                               {0.0f, 0.0f, 0.0f, 1.0f }};

    for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            aux[i][j] = this->Wl[i][j];

    multiplyMatrix(sl, aux,this->Wl);


//    this->center->transform(this->toWordMatrix);
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

    //Now get Wl:

    float Rl[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                               {0.0f, 1.0f, 0.0f, 0.0f},
                               {0.0f, 0.0f, 1.0f, 0.0f},
                               {0.0f, 0.0f, 0.0f, 1.0f }};
    for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            Rl[i][j] = rotateMatrix[j][i];


    float aux[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
                               {0.0f, 1.0f, 0.0f, 0.0f},
                               {0.0f, 0.0f, 1.0f, 0.0f},
                               {0.0f, 0.0f, 0.0f, 1.0f }};

    for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            aux[i][j] = this->Wl[i][j];

    multiplyMatrix(Rl, aux,this->Wl);

}
void Primitive::setToWordMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->toWordMatrix[i][j] = M[i][j];
}
void Primitive::setWlMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->Wl[i][j] = M[i][j];
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


bool Primitive::Ray_intersept(Point Po, Point D,float &t0, float &t1){

    bool result = false;

    float a=0, b=0, c=0, d=0;

    switch (this->type) {
    case 0:
        //Cube;
        t0=-1;
        t1=-1;
        break;
    case 1:
        a = dot(D, D);
        b = 2*dot(Po,D);
        c = dot(Po,Po) - (this->radius*this->radius);
        d = b*b-4*a*c;
        if(d >= 0){
            t0= (-b - sqrt(d))/(2*a);
            t1= (-b + sqrt(d))/(2*a);
            result = true;
        }
        break;
    case 2:
        //Cone;
        t0=-1;
        t1=-1;
        break;
    case 3:
        //Cylinder;
        t0=-1;
        t1=-1;
        break;
    case 4:
        //Box;
        t0=-1;
        t1=-1;
        break;
    default:
        break;
    }

    return result;
}
bool Primitive::Ray_intersept(Point Po, Point D, Intersection *t0, Intersection *t1){
    bool result = false;

    float a=0, b=0, c=0, d=0;

    switch (this->type) {
    case 0:
        //Cube;
        t0=NULL;
        t1=NULL;
        break;
    case 1:
        a = dot(D, D);
        b = 2*dot(Po,D);
        c = dot(Po,Po) - (this->radius*this->radius);
        d = b*b-4*a*c;
        if(d >= 0){
//            Point *n = new Point(0,1,1);
//            t0 = new Intersection(((-b - sqrt(d))/(2*a)), n, 0);
//            t1 = new Intersection(((-b + sqrt(d))/(2*a)), n, 0);
//            std::cout << "\n\n\n Teste --- " << t0->t;


            result = true;
        }
        break;
    case 2:
        //Cone;
        t0=NULL;
        t1=NULL;
        break;
    case 3:
        //Cylinder;
        t0=NULL;
        t1=NULL;
        break;
    case 4:
        //Box;
        t0=NULL;
        t1=NULL;
        break;
    default:
        break;
    }

    return result;
}



std::vector<Intersection*> Primitive::InfityCylinder(Point ro, Point rd){
    std::vector<Intersection*> I;
    Point v(0,0,1);

    Point p1ro = ro;

    Point drd = rd;
    drd.operator -=(Point(0,0,1).operator *=(dot(v,rd)));
    Point dro = p1ro;
    dro.operator -=(Point(0,0,1).operator *=(dot(p1ro, v)));

    float a = dot(drd, drd);
    float b = dot(drd, dro);
    float c = dot(dro, dro)-this->base*this->base;

    float d = b*b - a*c;

    if(d >= 0){

        float t0 = (-b-sqrt(d))/a;
        float t1 = (-b+sqrt(d))/a;

        Point *P0 = new Point(rd.x, rd.y, rd.z);
        P0->operator *=(t0);
        P0->operator +(ro);

        Point *P1 = new Point(rd.x, rd.y, rd.z);
        P1->operator *=(t1);
        P1->operator +=(ro);

        I.push_back(new Intersection(t0, new Point(0,0,1), P0, this));
        I.push_back(new Intersection(t1, new Point(0,0,1), P1, this));




    }
    return I;

}


std::vector<Intersection*> Primitive::Ray_intersept(Point Po, Point D){


    float vPo[4] = {Po.x, Po.y, Po.z, 1};
    float vD[4] = {D.x, D.y, D.z, 0};
    Point PoL = Mxv(this->Wl, vPo), DL = Mxv(this->Wl, vD);

    //    Point PoL = Po;
    //    Point DL = D;


    //Cube:
    Point Pmin(0,0,0), Pmax(0,0,0), Tmin(0,0,0), Tmax(0,0,0), sc(0,0,0), sf(0,0,0);

    //Sphere
    float a=0, b=0, c=0, d=0;

    //Cylinder:
    std::vector<Intersection*> infCy_list;
//    Point p1(0,0,0),p2(0,0,0),v(0,0,0), p1Po(0,0,0), dD(0,0,0), dPo(0,0,0), aux(0,0,0), aux2(0,0,0);
//    float r=0;
//    Primitive *p; std::vector<Intersection*> listBBox;

    std::vector<Intersection*> I;


    float t0=-1, t1=-1;

    switch (this->type) {
    case 0:
        Pmin.x = Pmin.y = Pmin.z = -this->size/2;
        Pmax.x = Pmax.y = Pmax.z = this->size/2;

        Tmin.x = (Pmin.x-PoL.x)/DL.x;
        Tmin.y = (Pmin.y-PoL.y)/DL.y,
        Tmin.z = (Pmin.z-PoL.z)/DL.z;

        Tmax.x = (Pmax.x-PoL.x)/DL.x;
        Tmax.y = (Pmax.y-PoL.y)/DL.y,
        Tmax.z = (Pmax.z-PoL.z)/DL.z;

        sc = min(&Tmin, &Tmax);
        sf = max(&Tmin, &Tmax);

        t0   = max(max(sc.x,sc.y),sc.z);
        t1   = min(min(sf.x,sf.y),sf.z);

        if(!(t0 > t1 || t1 < 0.0)){

            Point *P_intersection0 = new Point(DL.x, DL.y, DL.z);
            P_intersection0->operator *=(t0);
            P_intersection0->operator +(PoL);

            Point *Pint1 = new Point(DL.x, DL.y, DL.z);
            Pint1->operator *=(t1);

            Pint1->operator +(PoL);

            I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
            I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));
        }

        break;

    case 1:
        a = dot(DL, DL);
        b = 2*dot(PoL,DL);
        c = dot(PoL,PoL) - (this->radius*this->radius);
        d = b*b-4*a*c;
        if(d >= 0){

            t0 = ((-b - sqrt(d))/(2*a));
            t1 = ((-b + sqrt(d))/(2*a));
            Point *P_intersection0 = new Point(DL.x, DL.y, DL.z);
            P_intersection0->operator *=(t0);
            P_intersection0->operator +(PoL);

            Point *Pint1 = new Point(DL.x, DL.y, DL.z);
            Pint1->operator *=(t1);
            Pint1->operator +(PoL);

            I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
            I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));
        }
        break;
    case 2:
        //Cone;

        break;
    case 3:
        //Cylinder;

        infCy_list = this->InfityCylinder(PoL, DL);
        I = infCy_list;
//        if(infCy_list.size()>0){

//            bool T0 = (infCy_list.at(0)->Pintersection->z >0 && infCy_list.at(0)->Pintersection->z < this->height );
//            bool T1 = (infCy_list.at(1)->Pintersection->z >0 && infCy_list.at(1)->Pintersection->z < this->height );

//            if(T0 && T1){
//                I.push_back(infCy_list.at(0));
//                I.push_back(infCy_list.at(1));
//            }else{
//                if(T0){
//                   I.push_back(infCy_list.at(0));
//                   I.push_back(infCy_list.at(0));
//                }else{
//                    I.push_back(infCy_list.at(1));
//                    I.push_back(infCy_list.at(1));
//                }
//            }

//        }


//        a = DL.x*DL.x + DL.y *DL.y;
//        b = 2*(DL.x*PoL.x + DL.y * DL.y);
//        c = PoL.x*PoL.x + PoL.y*PoL.y - this->base*this->base;

//        d = b*b - 4*a*c;

//        if(d > 0){

//            t0 = ((-b - sqrt(d))/(2*a));
//            t1 = ((-b + sqrt(d))/(2*a));
//            Point *P_intersection0 = new Point(DL.x, DL.y, DL.z);
//            P_intersection0->operator *=(t0);
//            P_intersection0->operator +(PoL);

//            Point *Pint1 = new Point(DL.x, DL.y, DL.z);
//            Pint1->operator *=(t1);
//            Pint1->operator +(PoL);

//            I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
//            I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));

//            bool P0 = P_intersection0->z >= 0 && P_intersection0->z <= this->height;
//            bool P1 = Pint1->z >= 0 && Pint1->z <= this->height;


//            if(P0 && P1){
//                I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
//                I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));
//            }else{
//                if(P0){
//                    I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
//                    I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
//                }
//                if(P1){
//                    I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));
//                    I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));
//                }
//            }




//            float t;
//                //choose the smallest and >=0 t
//                if (x1 > x2)
//                {
//                    t=x2;
//                }

//                if (t < 0)
//                {
//                    t=x1;
//                }


//                // if both solution are <0 => NO INTERSECTION!
//                if (t>0)
//                {
//                    Point *P_intersection0 = new Point(DL.x, DL.y, DL.z);
//                    P_intersection0->operator *=(t0);
//                    P_intersection0->operator +(PoL);

//                    if(P_intersection0->z > 0 && P_intersection0->z < this->height)
//                    {
//                        if(dD.z != 0){
//                            float t3 = (0-PoL.z)/DL.z;
//                            float t4 = (this->height-PoL.z)/DL.z;
//                            float t2 = min(t3,t4);

//                            if(t2<0)
//                                t2 = max(t3,t4);

//                            if(t2>=0){
//                                P_intersection0 = new Point(DL.x, DL.y, DL.z);
//                                P_intersection0->operator *=(t2);
//                                P_intersection0->operator +(PoL);

//                                if(P_intersection0->x*P_intersection0->x+P_intersection0->y*P_intersection0->y <= this->base*this->base+0.9f){
////                                    t = min(t,t2);
////                                    if(t == t3){
//                                    I.push_back(new Intersection(t, new Point(0,1,1), P_intersection0, this));
//                                    I.push_back(new Intersection(t, new Point(0,1,1), P_intersection0, this));

//                                    //                                    }

//                                }
//                            }else{
//                                I.push_back(new Intersection(t, new Point(0,1,1), P_intersection0, this));
//                                I.push_back(new Intersection(t, new Point(0,1,1), P_intersection0, this));
//                            }


//                        }else{
//                            I.push_back(new Intersection(t, new Point(0,1,1), P_intersection0, this));
//                            I.push_back(new Intersection(t, new Point(0,1,1), P_intersection0, this));
//                        }
//                    }

//                }

//        }


//        EFloat a = dx * dx + dy * dy;
//        EFloat b = 2 * (dx * ox + dy * oy);
//        EFloat c = ox * ox + oy * oy - EFloat(radius) * EFloat(radius);

//        p = new Primitive("", 4, 0.0f,(this->base*2),(this->base*2),this->height,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
//        p->Translate(0,0,this->height/2);

//        listBBox = p->Ray_intersept(PoL, DL);
//        if(listBBox.size()>0){


//            p1.z = this->height;
//            v.z = -this->height;
//            //p2 - p1 = p2 - 0 = p2;  -> p2 = v;

//            v.operator /=(v.length());
//            // = v (0,0,1). Já é assim por definição..

//            p1Po.x = PoL.x - p1.x; // "-0"
//            p1Po.y = PoL.y - p1.y; // "-0"
//            p1Po.z = PoL.z - p1.z; // "-0"

//            dD.x = DL.x;
//            dD.y = DL.y;
//            dD.z = DL.z;

//            aux.x=v.x, aux.y=v.y; aux.z=v.z;
//            aux.operator *=(dot(DL, v));
//            dD.operator -=(aux);

//            //        dD.operator -=((Point(v.x, v.y, v.z).operator *=(dot(DL, v))));

//            aux2.x=v.x, aux2.y=v.y; aux2.z=v.z;
//            aux2.operator *=(dot(p1Po, v));

//            dPo.x = p1Po.x;
//            dPo.y = p1Po.y;
//            dPo.z = p1Po.z; //Tirei pois: p1Po = 0,0,0;

//            dPo.operator -=(aux2);

//            a = dot(dD, dD);
//            b = dot(dD,dPo);
//            c = dot(dPo, dPo) - this->base*this->base;
//            d = b*b - a*c;

//            if(d>=0){
//            //            Primitive *p = new Primitive("", 0, this->height, 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
//            //            p->Translate(0,0,this->height/2);
//            //            std::vector<Intersection*> listCube = p->Ray_intersept(PoL, DL);
//            //            if(listCube.size()>0){
//                t0 = ((-b - sqrt(d))/(2*a));
//                t1 = ((-b + sqrt(d))/(2*a));
////                PoL.ImpPoint();
//                Point *P_intersection0 = new Point(DL.x, DL.y, DL.z);
//                P_intersection0->operator *=(t0);
////                P_intersection0->operator +(PoL);

//                Point *Pint1 = new Point(DL.x, DL.y, DL.z);
//                Pint1->operator *=(t1);
////                Pint1->operator +=(PoL);

////                float l0 = dot(*P_intersection0, v);
////                float l1 = dot(*Pint1, v);

////                Point aux0(v.x, v.y, v.z);
////                aux0.operator *=(l0);

////                Point aux1(v.x, v.y, v.z);
////                aux1.operator *=(l1);

////                P_intersection0->operator -=(aux0);
////                Pint1->operator -=(aux1);



//                I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
//                I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));

//             }

//        }








        break;



    case 4:
        //Box;

        Pmin.x = -this->sizeX/2;
        Pmin.y = -this->sizeY/2;
        Pmin.z = -this->sizeZ/2;

        Pmax.x = this->sizeX/2;
        Pmax.y = this->sizeY/2;
        Pmax.z = this->sizeZ/2;


        Tmin.x = (Pmin.x-PoL.x)/DL.x;
        Tmin.y = (Pmin.y-PoL.y)/DL.y,
        Tmin.z = (Pmin.z-PoL.z)/DL.z;

        Tmax.x = (Pmax.x-PoL.x)/DL.x;
        Tmax.y = (Pmax.y-PoL.y)/DL.y,
        Tmax.z = (Pmax.z-PoL.z)/DL.z;

        sc = min(&Tmin, &Tmax);
        sf = max(&Tmin, &Tmax);

        t0   = max(max(sc.x,sc.y),sc.z);
        t1   = min(min(sf.x,sf.y),sf.z);

        if(!(t0 > t1 || t1 < 0.0)){

            Point *P_intersection0 = new Point(DL.x, DL.y, DL.z);
            P_intersection0->operator *=(t0);
            P_intersection0->operator +(PoL);

            Point *Pint1 = new Point(DL.x, DL.y, DL.z);
            Pint1->operator *=(t1);

            Pint1->operator +(PoL);

            I.push_back(new Intersection(t0, new Point(0,1,1), P_intersection0, this));
            I.push_back(new Intersection(t1, new Point(0,1,1), Pint1, this));
        }


        break;
    default:
        break;
    }

    return I;
}



//bool Primitive::Ray_intersept2(Point Po, Point D, int &tmin0, int &tmin1, int &tmax0, int &tmax1){

//    bool result = false;

//    float a=0, b=0, c=0, d=0;

//    switch (this->type) {
//    case 0:
//        //Cube;
//        tmin0=-1;
//        tmax0=-1;
//        tmin1=-1;
//        tmax1=-1;
//        break;
//    case 1:
//        a = dot(D, D);
//        b = 2*dot(Po,D);
//        c = dot(Po,Po) - (this->radius*this->radius);
//        d = b*b-4*a*c;
//        if(d >= 0){
//            tmin0= (-b - sqrt(d))/(2*a);
//            tmax0= (-b + sqrt(d))/(2*a);
//            result = true;
//        }
//        break;
//    case 2:
//        //Cone;
//        tmin0=-1;
//        tmax0=-1;
//        tmin1=-1;
//        tmax1=-1;
//        break;
//    case 3:
//        //Cylinder;
//        tmin0=-1;
//        tmax0=-1;
//        tmin1=-1;
//        tmax1=-1;
//        break;
//    case 4:
//        //Box;
//        tmin0=-1;
//        tmax0=-1;
//        tmin1=-1;
//        tmax1=-1;
//        break;
//    default:
//        break;
//    }

//    return result;
//}
