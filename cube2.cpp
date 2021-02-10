//#include "cube2.h"

//Cube::Cube()
//{

//}

//Cube::Cube(QString name, float cX, float cY, float cZ, float size){
//    this->name=name;
//    this->center = new Point(cX, cY, cZ);
//    this->size=size;
//}

//Cube::Cube(QString name, Point *P, float size){
//    this->name=name;
//    this->center=P;
//    this->size=size;
//}

//Cube::Cube(QString name, float cX, float cY, float cZ, float size, float r, float g, float b){
//    this->name=name;
//    this->center = new Point(cX, cY, cZ);
//    this->size=size;
//    this->color->setValues(r,g,b);
//}

//void Cube::getMatrix(float *temp_vector){
//    int c=0;
//    for(int i=0;i<4;i++)
//        for(int j=0;j<4;j++){
//            temp_vector[c]=this->toWordMatrix[j][i];
//            c++;
//        }
//}

//void Cube::translate(float fX, float fY, float fZ){
//    this->center->translate(fX,fY,fZ);
//    float translateMatrix[4][4] = { {1.0f, 0.0f, 0.0f, fX},
//                                    {0.0f, 1.0f, 0.0f, fY},
//                                    {0.0f, 0.0f, 1.0f, fZ},
//                                    {0.0f, 0.0f, 0.0f, 1.0f }};

//    float tempMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
//                               {0.0f, 1.0f, 0.0f, 0.0f},
//                               {0.0f, 0.0f, 1.0f, 0.0f},
//                               {0.0f, 0.0f, 0.0f, 1.0f }};

//    for(int i=0;i<4;i++)
//        for(int j=0; j<4; j++)
//            tempMatrix[i][j] = this->toWordMatrix[i][j];
//    multiplyMatrix(tempMatrix, translateMatrix,this->toWordMatrix);

//}
//void Cube::scale(float fX, float fY, float fZ){

//    float scaleMatrix[4][4] = { {fX, 0.0f, 0.0f, 0.0f},
//                                {0.0f, fY, 0.0f, 0.0f},
//                                {0.0f, 0.0f, fZ, 0.0f},
//                                {0.0f, 0.0f, 0.0f, 1.0f}};

//    float tempMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
//                               {0.0f, 1.0f, 0.0f, 0.0f},
//                               {0.0f, 0.0f, 1.0f, 0.0f},
//                               {0.0f, 0.0f, 0.0f, 1.0f }};

//    for(int i=0;i<4;i++)
//        for(int j=0; j<4; j++)
//            tempMatrix[i][j] = this->toWordMatrix[i][j];

//    multiplyMatrix(tempMatrix, scaleMatrix,this->toWordMatrix);
//}

//void Cube::rotate(float Ang, int eixo){
////    float tX = this->center->x, tY = this->center->y, tZ = this->center->z;

////    this->translate(-tX, -tY, -tZ);
//    float rotateMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
//                                {0.0f, 1.0f, 0.0f, 0.0f},
//                                {0.0f, 0.0f, 1.0f, 0.0f},
//                                {0.0f, 0.0f, 0.0f, 1.0f}};

//    getRotation(Ang, eixo, rotateMatrix);

//    float tempMatrix[4][4] = { {1.0f, 0.0f, 0.0f, 0.0f},
//                               {0.0f, 1.0f, 0.0f, 0.0f},
//                               {0.0f, 0.0f, 1.0f, 0.0f},
//                               {0.0f, 0.0f, 0.0f, 1.0f }};
//    for(int i=0;i<4;i++)
//        for(int j=0; j<4; j++)
//            tempMatrix[i][j] = this->toWordMatrix[i][j];

//    multiplyMatrix(tempMatrix, rotateMatrix,this->toWordMatrix);

////    this->translate(tX, tY, tZ);
//}

//void Cube::setMatrix(float M[4][4]){
//    for(int i=0;i<4;i++)
//        for(int j=0;j<4;j++)
//            this->toWordMatrix[i][j] = M[i][j];
//}
