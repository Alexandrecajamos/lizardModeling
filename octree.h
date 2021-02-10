#ifndef OCTREE_H
#define OCTREE_H
#include "primitive.h"
#include "octreenode.h"
#include "colorrgb.h"
#include "mesh.h"

class Octree
{
public:
    Octree();

    Octree(QString name, Primitive *primitive, int LevelMax);
    Octree(QString name, Mesh *mesh, int LevelMax);

    void SubDivide(OctreeNode* node);
    void SubDividev2(OctreeNode* node); // With mesh;


    int Classify(Cube *c);
    int Classify2(Cube *c);

    int VerifyByEdge(Cube *c);
//    int ClassifyV2(Cube *c, std::vector<Face*> intercepted_by_father);


    QString name = "";
    Primitive *primitive;
    Mesh *mesh;
    OctreeNode *root = NULL;
    int LevelMax = 0;

    bool rendIn = true, rendOn = true, rendOut = true, WFIn = true, WFOn = true, WFOut = true, RenderNonLeafNodes = false, OnlyLeafatLevel = false;
    int rendLvlMax = 0, NonRenderRegion = -1;
    ColorRGB *In_Color = new ColorRGB(0,0,1), *On_Color = new ColorRGB(0,1,0), *Out_Color = new ColorRGB(1,0,0);

    float transformMatrix[4][4] = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };

    void setRendIn(bool rendIn);
    void setRendOn(bool rendOn);
    void setRendOut(bool rendOut);
    void setWFIn(bool rendIn);
    void setWFOn(bool rendOn);
    void setWFOut(bool rendOut);
    void setRenderNonLeafNodes(bool RenderNonLeafNodes);
    void setOnlyleafatLevel(bool OnlyLeafatLevel);

    void setLevelMax(int LevelMax);
    void setNonRenderRegion(int Region);

    void setIn_Color(float R, float G, float B);
    void setOn_Color(float R, float G, float B);
    void setOut_Color(float R, float G, float B);


    void setIn_Color_R(float R);
    void setOn_Color_R(float R);
    void setOut_Color_R(float R);
    void setIn_Color_G(float G);
    void setOn_Color_G(float G);
    void setOut_Color_G(float G);
    void setIn_Color_B(float B);
    void setOn_Color_B(float B);
    void setOut_Color_B(float B);

    void getToWordMatrix(float *temp_vector);
    void setMatrx(float matrix[4][4]);

    void Scale(float fX, float fY, float fZ);
    void Translate(float fX, float fY, float fZ);
    void Rotate(int axis, float angle);



    float getVolume();
    float getVolume(OctreeNode *node);

    void NumberOfNodes(OctreeNode *node, int &In, int &On, int &Out, int &Leaf);


};

#endif // OCTREE_H
