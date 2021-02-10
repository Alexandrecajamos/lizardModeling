#ifndef OCTREENODE_H
#define OCTREENODE_H
#include "cube.h"
#include "face.h"

class OctreeNode
{
public:
    OctreeNode();
    OctreeNode(QString name, int level, int type, Cube *cube);
    QString name;
    Cube* cube;
    int level, type;
    bool leaf = false;
    //Type:0=Out; Type:1=On; Type:2=In;



    std::vector<OctreeNode*> children;
    void PrintNode();


    std::vector<Face*> interceptedFaces;

    float getVolume();

};

#endif // OCTREENODE_H
