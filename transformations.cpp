#include "transformations.h"


void getIdentity(float M[TAM][TAM]){
    for(int i=0; i<TAM;i++)
        for(int j=0;j<TAM;j++)
            if(i==j)
                M[i][j]=1;
            else
                M[i][j]=0;
}

void getScale(float fX, float fY, float fZ,float M[TAM][TAM]){
//    getIdentity((M));
    M[0][0]=fX;
    M[1][1]=fY;
    M[2][2]=fZ;
}
void getTranslation(float fX, float fY, float fZ,float M[TAM][TAM]){
//    getIdentity((M));
    M[0][3]=fX;
    M[1][3]=fY;
    M[2][3]=fZ;
}


void getRotation(float ang, int eixo, float M[TAM][TAM]){
    float seno = sin(ang*PI/180), cosseno = cos(ang*PI/180);

//    std::cout << "\nAng: "<< ang << "; Seno: "<< seno <<"; Cosseno: "<< cosseno;


    switch (eixo) {
        case 0:
            M[1][1] = cosseno;
            M[2][2] = cosseno;
            M[1][2] = -seno;
            M[2][1] = seno;
            break;
        case 1:
            M[0][0] = cosseno;
            M[2][2] = cosseno;
            M[0][2] = seno;
            M[2][0] = -seno;
            break;
        case 2:
            M[0][0] = cosseno;
            M[1][1] = cosseno;
            M[0][1] = -seno;
            M[1][0] = seno;
        default:
            break;
        }
//    printMatrix(M);
}

void multiplyMatrix(float A[TAM][TAM], float B[TAM][TAM], float C[TAM][TAM]){
//    printf("\n\n\nMultiply: "
//           "\nA:\n");
//    printMatrix(A);
//    printf("\nB:\n");
//    printMatrix(B);

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++) {
            C[i][j] = 0;
            for (int k = 0; k < TAM; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

//    printf("Result:\n");
//    printMatrix(C);
}

void printMatrix(float M[TAM][TAM]){
    std::cout << "\n Matrix M["<<TAM<<"]["<<TAM<<"]: ";
    for(int i=0; i<TAM;i++){
        std::cout << "\n";
        for(int j=0;j<TAM;j++)
            std::cout << M[i][j] << " | ";
    }
}

//void getScale(float E[TAM][TAM], float e[TAM]){
//    this->getIdentity(E);
//    for(int i=0;i<(TAM-1);i++)
//        E[i][i]=e[i];
//}

//void getTranslation(float T[TAM][TAM], float t[TAM]){
//    this->getIdentity(T);
//    for(int i=0;i<(TAM-1);i++)
//        T[i][TAM-1]=t[i];

//}

float detMatrix3x3(float m[3][3]){
    return m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
                 m[0][1] *(m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                 m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

void InvMatrix3x3(float Inv[TAM-1][TAM-1], float det){
    float m[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            m[i][j] = Inv[i][j];

    float iD = 1/det;
    Inv[0][0] = (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * iD;
    Inv[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * iD;
    Inv[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * iD;
    Inv[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * iD;
    Inv[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * iD;
    Inv[1][2] = (m[1][0] * m[0][2] - m[0][0] * m[1][2]) * iD;
    Inv[2][0] = (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * iD;
    Inv[2][1] = (m[2][0] * m[0][1] - m[0][0] * m[2][1]) * iD;
    Inv[2][2] = (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * iD;


}


Point mxv(float M[TAM-1][TAM-1], Point *P){

        float vP[TAM-1]={P->x, P->y, P->z};
        float vPt[TAM-1]={0,0,0};
        for(int i=0;i<TAM-1;i++){
            for(int j=0;j<TAM-1;j++)
            vPt[i]+=M[i][j]*vP[j];
        }
        return Point(vPt[0],vPt[1],vPt[2]);

}

Point Mxv(float M[TAM][TAM], float vP[TAM]){

    float vPt[TAM]={0,0,0,0};

    for(int i=0;i<TAM-1;i++){
        for(int j=0;j<TAM;j++)
            vPt[i]+=M[i][j]*vP[j];
    }
    return Point(vPt[0], vPt[1], vPt[2]);

}

Point vec(Point *P1, Point *P0){
    return Point(P1->x-P0->x, P1->y-P0->y, P1->z=P0->z);
}

float dot(Point A, Point B){
    return (A.x*B.x)+(A.y*B.y)+(A.z*B.z);
}
float dot2(Point A){
    return dot(A,A);
}

Point cross(Point A, Point B){
    return Point(A.x*B.x, A.y*B.y, A.z*B.z);
}

float min(float A, float B){
    if(A<B)
        return A;
    return B;
}
float max(float A, float B){
    if(A>B)
        return A;
    return B;
}
float clamp(float x, float upper, float lower){
    return min(upper, max(x, lower));
}

Vec2 vec(Vec2 *A, Vec2 *B){
    return Vec2(A->x-B->x, A->y-B->y);
}

float dot(Vec2 A, Vec2 B){
    return (A.x*B.x)+(A.y*B.y);
}
float dot2(Vec2 A){
    return dot(A,A);
}

Vec2 cross(Vec2 A, Vec2 B){
    return Vec2(A.x*B.x, A.y*B.y);
}


Point normal(Point a, Point b){
    Point p1;
    p1.x=(a.y*b.z)-(a.z*b.y);
    p1.y=(a.z*b.x)-(a.x*b.z);
    p1.z=(a.x*b.y)-(a.y*b.x);
    return p1;
}


Intersection* min(Intersection* A, Intersection* B){
    if(A->t < B->t)
        return A;
    return B;
}
Intersection* max(Intersection* A, Intersection* B){
    if(A->t > B->t)
        return A;
    return B;
}

Point min(Point *A, Point *B){
    float x, y,z;
    x = min(A->x, B->x);
    y = min(A->y, B->y);
    z = min(A->z, B->z);
    return Point(x,y,z);
}
Point max(Point *A, Point *B){
    float x, y,z;
    x = max(A->x, B->x);
    y = max(A->y, B->y);
    z = max(A->z, B->z);
    return Point(x,y,z);
}

float length(float a, float b){
    if(a>0 && b>0)
        return b-a;
    if(a<0 && b<0)
        return ((a*-1)-(b*-1));
    return ((a*-1)+b);

}


std::vector<Intersection*> Merge(std::vector<Intersection*> lA, std::vector<Intersection*> lB, int Op){

//    std::cout << "\nChegou aqui!";
    std::vector<Intersection*> res;

    switch (Op) {
    case 0:
        if(lA.size()==0)
            return lB;
        if(lB.size()==0)
            return lA;
        break;
    case 1:
        if(lA.size()==0 || lB.size()==0)
            return res;
        break;
    case 2:
        if(lA.size()==0)
            return res;
        if(lB.size()==0)
            return lA;
        break;
    default:
        return res;
        break;
    }


//    std::cout << "\nChegou aqui 2!";

//    if(lA.size() lB.size())
//        return res;
//            return (lA.size()>lB.size())?lA:lB;

//    //Se interseção e uma das listas for vazia, volta zero.
//    if(Op == 1 && (lA.size()==0 || lB.size()==0))
//        return res;

//    //Se diferença e A é vazio, retorna zero.
//    if(Op == 2 && lA.size()==0)
//        return res;



    Intersection* sentinel_temp = max(lA.back(), lB.back());

    Intersection* sentinel = new Intersection(sentinel_temp->t, sentinel_temp->normal, sentinel_temp->Pintersection, sentinel_temp->p);

    sentinel->t++;

    lA.push_back(sentinel);
    lB.push_back(sentinel);



//    for(std::vector<Intersection*>::iterator i = lA.begin(); i != lA.end(); i++){
//        std::cout << "\nTeste lA: " << (*i)->t;
//    }

//    for(std::vector<Intersection*>::iterator i = lB.begin(); i != lB.end(); i++){
//        std::cout << "\nTeste lB: " << (*i)->t;
//    }


    int a_index = 0, b_index=0;

    Intersection* scan = min(lA.front(), lB.front());

//    std::cout << "\nTeste Scan: " << scan->t;


    while(scan->operator <(sentinel)){

        bool in_a = !((scan->operator <(lA[a_index])) ^ (a_index % 2));
        bool in_b = !((scan->operator <(lB[b_index])) ^ (b_index % 2));

        bool in_res;

        switch (Op) {
        case 0:
            in_res = in_a || in_b;
            break;
        case 1:
            in_res = in_a && in_b;
            break;
        case 2:
            in_res = in_a && !in_b;
            break;
        default:
            in_res = 0;
            break;
        }

        if (in_res ^ (res.size() % 2))
            res.push_back(scan);

        if(scan->operator ==(lA[a_index]))
            a_index++;

        if(scan->operator ==(lB[b_index]))
            b_index++;

        scan = min(lA[a_index], lB[b_index]);
    }


    return res;
}



//def merge(a_tps, b_tps, op):
//  """Merge two lists of intervals according to the boolean function op"""
//  a_endpoints = flatten(a_tps)
//  b_endpoints = flatten(b_tps)

//  sentinel = max(a_endpoints[-1], b_endpoints[-1]) + 1
//  a_endpoints += [sentinel]
//  b_endpoints += [sentinel]

//  a_index = 0
//  b_index = 0

//  res = []

//  scan = min(a_endpoints[0], b_endpoints[0])
//  while scan < sentinel:
//    in_a = not ((scan < a_endpoints[a_index]) ^ (a_index % 2))
//    in_b = not ((scan < b_endpoints[b_index]) ^ (b_index % 2))
//    in_res = op(in_a, in_b)

//    if in_res ^ (len(res) % 2): res += [scan]
//    if scan == a_endpoints[a_index]: a_index += 1
//    if scan == b_endpoints[b_index]: b_index += 1
//    scan = min(a_endpoints[a_index], b_endpoints[b_index])

//  return unflatten(res)
