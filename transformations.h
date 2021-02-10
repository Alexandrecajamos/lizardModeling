#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H
#define TAM 4
#define PI 3.14159265

#include <iostream>
#include <math.h>
#include "point.h"
#include "vec2.h"


void getIdentity(float M[TAM][TAM]);
void getScale(float fX, float fY, float fZ,float M[TAM][TAM]);
void getTranslation(float fX, float fY, float fZ,float M[TAM][TAM]);
void getRotation(float ang, int eixo, float M[TAM][TAM]);

void multiplyMatrix(float A[TAM][TAM], float B[TAM][TAM], float C[TAM][TAM]); // C=A*B;
void printMatrix(float M[TAM][TAM]);

float detMatrix3x3(float M[3][3]);
void InvMatrix3x3(float M[3][3], float det);

Point mxv(float M[3][3], Point *P);


Point vec(Point *P0, Point *P1);
float dot(Point A, Point B);
float dot2(Point A);
Point cross(Point A, Point B);


float dot(Vec2 A, Vec2 B);
float dot2(Vec2 A);
Vec2 cross(Vec2 A, Vec2 B);
Vec2 vec(Vec2 *A, Vec2 *B);

float min(float A, float B);
float max(float A, float B);
float clamp(float x, float upper, float lower);


#endif // TRANSFORMATIONS_H
