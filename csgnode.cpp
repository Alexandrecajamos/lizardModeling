#include "csgnode.h"

CSGnode::CSGnode()
{

}

CSGnode::CSGnode(Primitive *P){
    this->isLeaf = true;
    this->primitive = P;
    this->left = NULL;
    this->right = NULL;
    this->name = P->name;
}
CSGnode::CSGnode(QString name, CSGnode *L, CSGnode *R, int BoolOpr){
    this->name = name;
    this->left=L;
    this->right=R;
    this->boolOpr = BoolOpr;
    this->primitive = NULL;
    this->isLeaf=false;
}

void CSGnode::Translate(float fX, float fY, float fZ){
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
void CSGnode::Scale(float fX, float fY, float fZ){
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
void CSGnode::Rotate(int axis, float angle){
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

void CSGnode::setToWordMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->toWordMatrix[i][j] = M[i][j];
}
void CSGnode::setWlMatrix(float M[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            this->Wl[i][j] = M[i][j];
}
void CSGnode::getToWordMatrix(float *temp_vector){
    int c=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            temp_vector[c]=this->toWordMatrix[j][i];
            c++;
        }
}

bool CSGnode::PointIntersect(Point *P){
    if(this->isLeaf){
        return this->primitive->PointClassify(P);
    }else{

        bool result = false;

        switch (this->boolOpr) {
        case 0:
            result = this->left->PointIntersect(P) || this->right->PointIntersect(P); // União
            break;
        case 1:
            result = this->left->PointIntersect(P) && this->right->PointIntersect(P); // Interseção
            break;
        case 2:
            result = this->left->PointIntersect(P) && !this->right->PointIntersect(P); // A - B
            break;
        case 3:
            result = !this->left->PointIntersect(P) && this->right->PointIntersect(P); // B - A
            break;
        default:
            break;
        }
        return result;
    }

}

QString CSGnode::getEquation(){
    if(this->isLeaf){
        return this->primitive->name;
    }else{

        QString result = " (";

        switch (this->boolOpr) {
        case 0:
            result += this->left->getEquation();
            result += " OR ";
            result += this->right->getEquation();
            result += ") ";
            break;
        case 1:
            result += this->left->getEquation();
            result += " AND ";
            result += this->right->getEquation();
            result += ") ";
            break;
        case 2:
            result += this->left->getEquation();
            result += " - ";
            result += this->right->getEquation();
            result += ") ";
            break;
        default:
            break;
        }
        return result;
    }
}


int CSGnode::PointClassify(Point *P){

    Point *Pl = new Point(P->x, P->y, P->z);
    Pl->transform(this->Wl);



    if(this->isLeaf){

        Point *Pll = new Point(Pl->x, Pl->y, Pl->z);
        Pll->transform(this->primitive->Wl);
        return this->primitive->PointClassify(Pll);
    }else{

        int result = 0;

        int A = this->left->PointClassify(Pl),
            B = this->right->PointClassify(Pl);

        switch (this->boolOpr) {
        case 0:
            if(A == 2 || B == 2)
                result = 2;
            else if(A == 1 || B == 1)
                result = 1;
            else
                result = 0;
            break;
        case 1:
            if(A == 0 || B == 0)
                result = 0;
            else if(A == 1 || B == 1)
                result = 1;
            else
                result = 2;
            break;
        case 2:
            if(A == 0 || B == 2)
                result = 0;
            else if(B==0)
                result = A;
            else
                result =0;
//            else if(A == 1 || B == 1)
//                result = 1;
//            else
//                result = 2;
            break;
        default:
            break;
        }
        return result;
    }
}

Cube* CSGnode::getWrap(){
//    float cubeSize = 10;
//    float cX = 0, cY=0, cZ=0;
    Cube *c;

    if(this->isLeaf){

        c = this->primitive->getWrap();
        c->Transform(this->primitive->toWordMatrix);
        return c;

    }else{

        Cube *cL = this->left->getWrap();

        if(this->boolOpr == 2){
            cL->Transform(this->toWordMatrix);
            return cL;
        }
        Cube *cR = this->right->getWrap();

        Point *Lmin = cL->getPmin(), *Lmax = cL->getPmax();
        Point *Rmin = cR->getPmin(), *Rmax = cR->getPmax();

        //        Point Pmin = min(Lmin,Rmin);
        //        Point Pmax = max(Lmax,Rmax);
        Point Pmin, Pmax;

        if(this->boolOpr == 0){
            Pmin = min(Lmin,Rmin);
            Pmax = max(Lmax,Rmax);
        }else{
            Pmin = max(Lmin,Rmin);
            Pmax = min(Lmax,Rmax);
        }



//        return new Cube("",&Pmin, &Pmax);
        Cube *c = new Cube("",&Pmin, &Pmax);
        c->Transform(this->toWordMatrix);
//        c->printVertices();

        return c;
//        return new Cube("", cX, cY, cZ, cubeSize);
    }




}


bool CSGnode::Ray_intersept(Point Po, Point D, float &tmin0, float &tmin1, float &tmax0, float &tmax1){

    tmin0 = -1; tmin1=-1; tmax0=-1; tmax1=-1;

    if(this->isLeaf){
        float vPo[4] = {Po.x, Po.y, Po.z, 1};
        float vD[4] = {D.x, D.y, D.z, 0};
        Point PoL = Mxv(this->primitive->Wl, vPo);
        Point DL = Mxv(this->primitive->Wl, vD);
        tmin1=-1;
        tmax1=-1;
        return this->primitive->Ray_intersept(PoL, DL, tmin0, tmax0);
    }else{



        float tminA0 = -1, tmaxA0 = -1, tminB0 = -1, tmaxB0 = -1,
                tminA1 = -1, tmaxA1 = -1, tminB1 = -1, tmaxB1 = -1;

        bool iA = this->left->Ray_intersept(Po, D, tminA0, tminA1, tmaxA0, tmaxA1);
        bool iB = this->right->Ray_intersept(Po, D, tminB0, tminB1, tmaxB0, tmaxB1);

        if(!iA && !iB)
            return false;

        bool result = false;

        switch (this->boolOpr) {
        case 0:
            tmin0=min(tminA0, tminB0);
            tmax0=min(tmaxA0, tmaxB0);
            tmin1=max(tminA0, tminB0);
            tmax1=max(tmaxA0, tmaxB0);
            if(tmin0 < tmax1 && tmin1 < tmax0){
                tmin1=-1; tmax1=-1;
            }
            result =  true;
            break;
        case 1:
            tmin0 = max(tminA0, tminB0);
            tmax0 = min(tmaxA0, tmaxB0);
            tmin1=-1;
            tmax1=-1;
            if(tmin0 > tmax0){
                tmin0=-1;
                tmax0=-1;
            }

        default:
            break;
        }

        return result;

    }
}



std::vector<Intersection*> CSGnode::Ray_intersept(Point Po, Point D){

    float vPo[4] = {Po.x, Po.y, Po.z, 1};
    float vD[4] = {D.x, D.y, D.z, 0};

    Point PoL = Mxv(this->Wl, vPo);
    Point DL = Mxv(this->Wl, vD);


    std::vector<Intersection*> r;


    if(this->isLeaf){
         r = this->primitive->Ray_intersept(PoL, DL);


//         std::cout << "\n Primitiva: " << this->primitive->name.toStdString();
//         for(std::vector<Intersection*>::iterator i = r.begin(); i != r.end(); i++){
//             std::cout << "\nTeste result: " << (*i)->t;
//         }


    }else{

        std::vector<Intersection*> lA, lB;

        lA = this->left->Ray_intersept(PoL, DL);
        lB = this->right->Ray_intersept(PoL, DL);



        r = Merge(lA,lB, this->boolOpr);


//        std::cout << "\n Teste Size: " << lA.size() << " "<<this->boolOpr<< " " << lB.size() << ": " << r.size();


//        Po.ImpPoint();
//        D.ImpPoint();

    }

    for(int i=0;i<r.size();i++){
        r.at(i)->Pintersection->transform(this->toWordMatrix);
    }


    return r;
}
