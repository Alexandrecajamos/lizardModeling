#include "octreenode.h"

OctreeNode::OctreeNode()
{

}

OctreeNode::OctreeNode(QString name, int level, int type, Cube *cube){
    this->name=name;
    this->level=level;
    this->type=type;
    this->cube=cube;

    if(type==0 || type==2)
        this->leaf=true;

    for(int i=0; i<8; i++)
        this->children.push_back(NULL);
}

void OctreeNode::PrintNode(){

    std::cout<<name.toStdString()<<" - Lvl:"<< this->level <<", Type: "<< this->type << ", IsLeaf: "<<this->leaf<<", Cube Size" << this->cube->size<< ";\n";

    for(int i=0;i<8;i++)
        if(this->children[i]!= NULL)
            this->children[i]->PrintNode();
}

float OctreeNode::getVolume(){
    float volume = 0;
    if(this->leaf)
        return this->cube->getVolume();
    else{
        for(std::vector<OctreeNode*>::iterator i = this->children.begin(); i!= this->children.end(); i++){
            OctreeNode *c = (*i);
            if(c != NULL)
                volume+= c->getVolume();
        }

    }
    return volume;
}

