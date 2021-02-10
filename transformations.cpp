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
        Point px(vPt[0],vPt[1],vPt[2]);
        return px;

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
