#ifndef SCENE_H
#define SCENE_H
#include <QString>
#include "sphere.h"
#include<vector>
#include "colorrgb.h"
#include "primitive.h"
#include "cube.h"
#include "octree.h"
#include "mesh.h"
#include "csgnode.h"

#include <sstream>
#include "QTextBrowser"
#include <fstream>

#include "observer.h"
#include "light.h"
#include "spotlight.h"

using namespace std;


class Scene
{
public:
    Scene();
    Scene(QString Name);
    QString Name;

    std::vector<Primitive*> primitives;
    std::vector<Octree*> octrees;
    std::vector<Mesh*> meshes;

    std::vector<CSGnode*> csg_trees;

    std::vector<Light*> lights;
    std::vector<SpotLight*> spotLights;


    Observer *observer = new Observer();
    void setObserver(float Ex,float Ey,float Ez,float Lox,float Loy,float Loz,float Avx,float Avy,float Avz);

    bool rendPrimitives = true, rendOctrees = true, rendMeshes = true, wireFrame = false;


//    void addPrimitive(QString name, float size, float R, float G, float B);
//    void addPrimitive(QString name, float radius, float slices, float stacks, float R, float G, float B);
//    void addPrimitive(QString name, float base, float height, float slices, float stacks, float R, float G, float B);
//    void addPrimitive(QString name, float sizeX, float sizeY, float sizeZ, float R, float G, float B,  int add);

    void addPrimitive(QString name, int type, float size,float sizeX,float sizeY,float sizeZ, float radius, float base, float height, float slices, float stacks, float R, float G, float B);

    bool removePrimitive(QString name);

    bool TranslateObj(QString name, float fX, float fY, float fZ);
    bool ScaleObj(QString name, float fX, float fY, float fZ);
    bool RotateObj(QString name, int axis, float angle);
    bool CleanObj(QString name);


    void addOctree(Octree *o);
    bool removeOctree(QString name);
    Octree* getOctree(QString name);

    void addMesh(Mesh *M);

    bool removeMesh(QString name);
    Mesh* getMesh(QString name);



    void addMeshes(string filepath);

    Primitive* getPrimitive(QString name);



    string SceneInformations();


    ColorRGB Ray_Pix_Ilm(Point Po, Point D);

    float Ray_intersept_primitive(Point Po, Point D, int &iPrimitive);

    ColorRGB* Bg = new ColorRGB(0.250980, 0.87843137, 0.815686275);
    ColorRGB* Amb = new ColorRGB(0.1,0.1,0.1);



    CSGnode* getCSG(QString name);
    bool removeCSG(QString name);

    bool createCSG(QString name, QString A, QString B, int Opr);
    bool primitiveToCSG(QString CSG, QString P, int Opr);



    bool createCSG(QString name, QString s);
    CSGnode* build_csg(string s);

    std::vector<Intersection*> Edge_intersept_CSG(QString name, float p0x,float p0y,float p0z,float p1x,float p1y,float p1z, bool infinity);



//    std::vector<Cube*> cubes;
//    std::vector<Sphere*> spheres;

//    void addCube(QString name, float cX, float cY, float cZ, float size);
//    void addCube(QString name, float cX, float cY, float cZ, float size, float r, float g, float b);
//    bool removeCube(QString id);
//    bool TranslateCube(QString id, float fX, float fY, float fZ);
//    bool ScaleCube(QString id, float fX, float fY, float fZ);
//    bool RotateCube(QString id, float Ang, int eixo);
//    bool CleanCube(QString id);

//    void addSphere(QString name, float cX, float cY, float cZ, float radius, int slices, int stacks, float r, float g, float b);
//    bool removeSphere(QString id);

};

#endif // SCENE_H
