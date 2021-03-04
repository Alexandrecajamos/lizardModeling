#include "cube.h"

Cube::Cube(){
    this->name="name";
    this->center = new Point(0, 0, 0);
    this->size=1;

    float d = size/2;

    Point *p0 = new Point(-d,-d,d);
    //v0: -x, -x, x
    Point *p1 = new Point(d,-d,d);
    //v1: x, -x, x
    Point *p2 = new Point(-d,d,d);
    //v2: -x, x, x
    Point *p3 = new Point(d,d,d);
    //v3: x, x, x
    Point *p4 = new Point(-d,-d,-d);
    //v4: -x, -x, -x
    Point *p5 = new Point(d,-d,-d);
    //v5: x, -x, -x
    Point *p6 = new Point(-d,d,-d);
    //v6: -x, x, -x
    Point *p7 = new Point(d,d,-d);
    //v7: x, x, -x

    this->vertices.push_back(p0);
    this->vertices.push_back(p1);
    this->vertices.push_back(p2);
    this->vertices.push_back(p3);
    this->vertices.push_back(p4);
    this->vertices.push_back(p5);
    this->vertices.push_back(p6);
    this->vertices.push_back(p7);


    Edge *e0 = new Edge(p0,p1);
    Edge *e1 = new Edge(p1,p3);
    Edge *e2 = new Edge(p3,p2);
    Edge *e3 = new Edge(p2,p0);
    Edge *e4 = new Edge(p1,p5);
    Edge *e5 = new Edge(p5,p7);
    Edge *e6 = new Edge(p7,p3);
    Edge *e7 = new Edge(p7,p6);
    Edge *e8 = new Edge(p6,p2);
    Edge *e9 = new Edge(p5,p4);
    Edge *e10 = new Edge(p4,p6);
    Edge *e11 = new Edge(p4,p0);

    this->edges.push_back(e0);
    this->edges.push_back(e1);
    this->edges.push_back(e2);
    this->edges.push_back(e3);
    this->edges.push_back(e4);
    this->edges.push_back(e5);
    this->edges.push_back(e6);
    this->edges.push_back(e7);
    this->edges.push_back(e8);
    this->edges.push_back(e9);
    this->edges.push_back(e10);
    this->edges.push_back(e11);

}

Cube::Cube(QString name, float cX, float cY, float cZ, float size){

    this->name=name;
    this->center = new Point(0, 0, 0);
    this->size=size;

    float d = size/2;

    Point *p0 = new Point(-d,-d,d);
    //v0: -x, -x, x
    Point *p1 = new Point(d,-d,d);
    //v1: x, -x, x
    Point *p2 = new Point(-d,d,d);
    //v2: -x, x, x
    Point *p3 = new Point(d,d,d);
    //v3: x, x, x
    Point *p4 = new Point(-d,-d,-d);
    //v4: -x, -x, -x
    Point *p5 = new Point(d,-d,-d);
    //v5: x, -x, -x
    Point *p6 = new Point(-d,d,-d);
    //v6: -x, x, -x
    Point *p7 = new Point(d,d,-d);
    //v7: x, x, -x

    this->vertices.push_back(p0);
    this->vertices.push_back(p1);
    this->vertices.push_back(p2);
    this->vertices.push_back(p3);
    this->vertices.push_back(p4);
    this->vertices.push_back(p5);
    this->vertices.push_back(p6);
    this->vertices.push_back(p7);


    float M[4][4] = {{1,0,0,cX},
                     {0,1,0,cY},
                     {0,0,1,cZ},
                     {0,0,0,1}};
    this->Transform(M);



    Edge *e0 = new Edge(p0,p1);
    Edge *e1 = new Edge(p1,p3);
    Edge *e2 = new Edge(p3,p2);
    Edge *e3 = new Edge(p2,p0);
    Edge *e4 = new Edge(p1,p5);
    Edge *e5 = new Edge(p5,p7);
    Edge *e6 = new Edge(p7,p3);
    Edge *e7 = new Edge(p7,p6);
    Edge *e8 = new Edge(p6,p2);
    Edge *e9 = new Edge(p5,p4);
    Edge *e10 = new Edge(p4,p6);
    Edge *e11 = new Edge(p4,p0);

    this->edges.push_back(e0);
    this->edges.push_back(e1);
    this->edges.push_back(e2);
    this->edges.push_back(e3);
    this->edges.push_back(e4);
    this->edges.push_back(e5);
    this->edges.push_back(e6);
    this->edges.push_back(e7);
    this->edges.push_back(e8);
    this->edges.push_back(e9);
    this->edges.push_back(e10);
    this->edges.push_back(e11);
}


Cube::Cube(QString name, Point *Pmin, Point *Pmax){
    this->name=name;

//    Point *V = new Point(Pmax->x,Pmax->y, Pmax->z);
//    V->operator -=(*Pmin);
//    V->operator *=(0.5);

//    this->center=V;

    float sizeX = length(Pmin->x, Pmax->x);
    float sizeY = length(Pmin->y, Pmax->y);
    float sizeZ = length(Pmin->z, Pmax->z);


    this->size = max(sizeX,max(sizeY,sizeZ));

    float d = this->size/2;

    Point *p0 = new Point(-d,-d,d);
    Point *p1 = new Point(d,-d,d);
    Point *p2 = new Point(-d,d,d);
    Point *p3 = new Point(d,d,d);
    Point *p4 = new Point(-d,-d,-d);
    Point *p5 = new Point(d,-d,-d);
    Point *p6 = new Point(-d,d,-d);
    Point *p7 = new Point(d,d,-d);

    this->vertices.push_back(p0);
    this->vertices.push_back(p1);
    this->vertices.push_back(p2);
    this->vertices.push_back(p3);
    this->vertices.push_back(p4);
    this->vertices.push_back(p5);
    this->vertices.push_back(p6);
    this->vertices.push_back(p7);

    float   cX = (Pmin->x+(sizeX/2)),
            cY = (Pmin->y+(sizeY/2)),
            cZ = (Pmin->z+(sizeZ/2));

    this->center = new Point(0,0,0);

    float M[4][4] = {{1,0,0,cX},
                     {0,1,0,cY},
                     {0,0,1,cZ},
                     {0,0,0,1}};

    this->Transform(M);



    Edge *e0 = new Edge(p0,p1);
    Edge *e1 = new Edge(p1,p3);
    Edge *e2 = new Edge(p3,p2);
    Edge *e3 = new Edge(p2,p0);
    Edge *e4 = new Edge(p1,p5);
    Edge *e5 = new Edge(p5,p7);
    Edge *e6 = new Edge(p7,p3);
    Edge *e7 = new Edge(p7,p6);
    Edge *e8 = new Edge(p6,p2);
    Edge *e9 = new Edge(p5,p4);
    Edge *e10 = new Edge(p4,p6);
    Edge *e11 = new Edge(p4,p0);

    this->edges.push_back(e0);
    this->edges.push_back(e1);
    this->edges.push_back(e2);
    this->edges.push_back(e3);
    this->edges.push_back(e4);
    this->edges.push_back(e5);
    this->edges.push_back(e6);
    this->edges.push_back(e7);
    this->edges.push_back(e8);
    this->edges.push_back(e9);
    this->edges.push_back(e10);
    this->edges.push_back(e11);


}

void Cube::Transform(float M[4][4]){

    for(std::vector<Point*>::iterator i = this->vertices.begin(); i!= this->vertices.end(); i++)
    {
        Point *p = (*i);
        p->transform(M);
    }
    this->center->transform(M);

    Point *P = new Point(this->vertices[1]->x,this->vertices[1]->y,this->vertices[1]->z);
    P->operator -=(*this->vertices[0]);
    this->size = P->length();

}

void Cube::printVertices(){
    std::cout << "\nCube: " << this->name.toStdString() << ";\nCenter (x,y,z): " << this->center->x <<", "<< this->center->y <<", "<< this->center->z;
    std::cout <<"\nSize:" << this->size;
    for(std::vector<Point*>::iterator i = this->vertices.begin(); i!= this->vertices.end(); i++)
    {
        Point *p = (*i);
        std::cout << "\nv " << p->x<<", "<<p->y<<", "<<p->z<<";";
    }

}


std::vector<Cube*> Cube::Divide8(){
    std::vector<Cube*> newCubes;

    for(std::vector<Point*>::iterator i = this->vertices.begin(); i!= this->vertices.end(); i++)
    {
        Point *p = (*i);
        Point *V = new Point(p->x,p->y, p->z);
        V->operator -=(*this->center);
        V->operator *=(0.5);
        Point *cx = new Point(this->center->x, this->center->y, this->center->z);
        cx->operator +=(*V);
        newCubes.push_back(new Cube("-", cx->x, cx->y, cx->z, (this->size/2)));

    }
    return newCubes;
}



int Cube::PointClassify(Point *P){


    Point *min = this->vertices.at(4);
    Point *max = this->vertices.at(3);

        if(P->x <= max->x && P->y <= max->y  && P->z <= max->z && P->x >= min->x && P->y >= min->x  && P->z >= min->z){
            if(P->x == max->x || P->y == max->y  || P->z == max->z || P->x == min->x || P->y == min->y  || P->z == min->z)
                return 1;
            else
                return 2;
        }
        else
            return 0;
}

float Cube::getVolume(){
    return (this->size*this->size*this->size);
}

float Cube::getArea(){
    return 6*(this->size*this->size);
}


Point* Cube::getPmin(){

    float mX, mY, mZ;

    mX = this->vertices.at(0)->x;
    mY = this->vertices.at(0)->y;
    mZ = this->vertices.at(0)->z;

    for(int i=1; i<this->vertices.size(); i++){
        float x = this->vertices.at(i)->x;
        float y = this->vertices.at(i)->y;
        float z = this->vertices.at(i)->z;

        if(x<mX)
            mX = x;
        if(y<mY)
            mY = y;
        if(z<mZ)
            mZ = z;

    }
    return new Point(mX,mY,mZ);
}


Point* Cube::getPmax(){

    float mX, mY, mZ;

    mX = this->vertices.at(0)->x;
    mY = this->vertices.at(0)->y;
    mZ = this->vertices.at(0)->z;

    for(int i=1; i<this->vertices.size(); i++){
        float x = this->vertices.at(i)->x;
        float y = this->vertices.at(i)->y;
        float z = this->vertices.at(i)->z;

        if(x>mX)
            mX = x;
        if(y>mY)
            mY = y;
        if(z>mZ)
            mZ = z;

    }
    return new Point(mX,mY,mZ);
}

void Cube::setToWordMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->toWordMatrix[i][j] = M[i][j];
}
void Cube::setWlMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->Wl[i][j] = M[i][j];
}
void Cube::getToWordMatrix(float *temp_vector){
    int c=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            temp_vector[c]=this->toWordMatrix[j][i];
            c++;
        }
}

