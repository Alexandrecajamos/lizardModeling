#include "octree.h"

Octree::Octree()
{

}

Octree::Octree(QString name, Primitive *primitive, int LevelMax){
    this->name = name;
    this->primitive=primitive;
    this->LevelMax=LevelMax;
    this->rendLvlMax=LevelMax;

    Cube *c = this->primitive->getWrap();
//    c->Transform(this->primitive->toWordMatrix);
//    c->setToWordMatrix(this->primitive->toWordMatrix);

    this->root = new OctreeNode(name+"_root", 0, 1,c);
    SubDivide(this->root);
}

Octree::Octree(QString name, Mesh *mesh, int LevelMax){
    this->name=name;
    this->mesh=mesh;
    this->LevelMax=LevelMax;
    this->rendLvlMax=LevelMax;

    Cube *c = this->mesh->getCube();

    this->root = new OctreeNode(name+"_root",0,1,c);
    this->root->interceptedFaces = mesh->faces;

    SubDividev2(this->root);
}


Octree::Octree(QString name, CSGnode *csg, int LevelMax){
    this->name=name;
    this->csg=csg;
    this->LevelMax=LevelMax;
    this->rendLvlMax=LevelMax;

    Cube *c = this->csg->getWrap();
//    c->Transform(this->primitive->toWordMatrix);
//    c->setToWordMatrix(this->primitive->toWordMatrix);
    this->root = new OctreeNode(name+"_root", 0, 1,c);
    SubDivide(this->root);

}


void Octree::SubDivide(OctreeNode *node){
    if(node->level>=this->LevelMax || node->type==2)
        return;

    std::vector<Cube*> newCubes = node->cube->Divide8();
//    for(std::vector<Cube*>::iterator i = newCubes.begin(); i != newCubes.end(); i++){
//        if(this->primitive != NULL)
//            (*i)->Transform(this->primitive->toWordMatrix);
//        else
//            (*i)->Transform(this->csg->toWordMatrix);
//    }

    for(int i=0; i<8; i++){

//        if(this->primitive != NULL){
//        newCubes[i]->setToWordMatrix(this->primitive->toWordMatrix);
//        }
//        if(this->csg != NULL){
//            newCubes[i]->setToWordMatrix(this->csg->toWordMatrix);
//        }

        int lvl = node->level+1, type = this->Classify2(newCubes[i]);
        QString node_name  =  node->name +"_" + QString::number(i);

        node->children[i] = new OctreeNode(node_name, lvl, type, newCubes[i]);

        if(node->children[i]->level == this->LevelMax)
            node->children[i]->leaf = true;

        this->SubDivide(node->children[i]);

    }


}
int Octree::Classify(Cube *c){

    //Type:0=Out; Type:1=On; Type:2=In;

    if(this->primitive != NULL){

        bool controlIn = false, controlOut = false;
        for(std::vector<Point*>::iterator i = c->vertices.begin(); i!=c->vertices.end();i++){
            Point *P = (*i);
            bool control = this->primitive->PointIntersect(P);
            if(control)
                controlIn=true;
            else
                controlOut=true;
        }

        if(controlIn && controlOut)
            return 1;
        if(controlIn)
            return 2;        
        return 0;
    }

    return 3;
}
int Octree::Classify2(Cube *c){


    //Type:0=Out; Type:1=On; Type:2=In;

    if(this->primitive != NULL || this->csg != NULL){
        int cont = 0;
        for(std::vector<Point*>::iterator i = c->vertices.begin(); i!=c->vertices.end();i++){
            Point *P = (*i);
            if(this->primitive != NULL)
                c->Classified_points[cont] = this->primitive->PointClassify(P);
            else{
//                float Wl[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

                c->Classified_points[cont] = this->csg->PointClassify(P);
//                if(c->Classified_points[cont] == 0){
//                    c->Classified_points[cont] = this->VerifyByEdge(c);
//                }

            }cont++;



        }

        int in =0, on=0, out=0;

        for(int i=0;i<8;i++){
            switch (c->Classified_points[i]) {
            case 0:
                out++;
                break;
            case 1:
                on++;
                break;
            case 2:
                in++;
                break;
            default:
                break;
            }
        }

        if(out == 8)
//            return VerifyByEdge(c);
            return 0;
        else if(in == 8)
            return 2;
        else
            return 1;


    }
    return 0;

}


int Octree::VerifyByEdge(Cube *c){
    std::vector<Edge*>::iterator i = c->edges.begin();
    int control = 0;
    while(i != c->edges.end() && control == 0){
        Edge *e = (*i);
        Point p = e->getVector();
        p.operator *=(0.5);

        Point teste(e->P0->x, e->P0->y, e->P0->z);
        teste.operator +=(p);
        if(this->primitive != NULL)
            control = this->primitive->PointClassify(&p);
        else
            control = this->csg->PointClassify(&p);

    }
    return control;

}

void Octree::SubDividev2(OctreeNode *node){

    if(node->level>=this->LevelMax || node->type==0 || node->type==2)
        return;

    std::vector<Cube*> newCubes = node->cube->Divide8();

    for(int i=0; i<8; i++){
        int lvl = node->level+1;
        QString node_name  =  node->name +"_" + QString::number(i);

        node->children[i] = new OctreeNode(node_name, lvl, 1, newCubes[i]);

        for(std::vector<Face*>::iterator f = this->mesh->faces.begin(); f != this->mesh->faces.end(); f++){
            if((*f)->CubeIntersept(newCubes[i]))
                node->children[i]->interceptedFaces.push_back(*f);

        }

        if(node->children[i]->interceptedFaces.empty()){
            node->children[i]->type=0;
            node->children[i]->leaf = true;
        }


        if(node->children[i]->level == this->LevelMax)
            node->children[i]->leaf = true;


        this->SubDividev2(node->children[i]);

    }

}
void Octree::getToWordMatrix(float *temp_vector){
    int c=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            temp_vector[c]=this->transformMatrix[j][i];
            c++;
        }
}
void Octree::setMatrx(float matrix[4][4]){
    for(int i=0;i<4;i++)
        for(int j=0; j<4; j++)
            this->transformMatrix[i][j]=matrix[i][j];
}

void Octree::Translate(float fX, float fY, float fZ){
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
            tempMatrix[i][j] = this->transformMatrix[i][j];

    multiplyMatrix(tempMatrix, translateMatrix,this->transformMatrix);
}
void Octree::Scale(float fX, float fY, float fZ){
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
            tempMatrix[i][j] = this->transformMatrix[i][j];

    multiplyMatrix(tempMatrix, scaleMatrix,this->transformMatrix);
}
void Octree::Rotate(int axis, float angle){
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
            tempMatrix[i][j] = this->transformMatrix[i][j];

    multiplyMatrix(tempMatrix, rotateMatrix,this->transformMatrix);
}

float Octree::getVolume(){

//    return this->root->getVolume();

    return this->getVolume(this->root);
}
float Octree::getVolume(OctreeNode *node){

    float volume = 0;

    if(node==NULL)
        return volume;


    if(this->OnlyLeafatLevel && node->level!=this->rendLvlMax){
        for(int i=0;i<8;i++){
            if(i!=this->NonRenderRegion)
                volume+=this->getVolume(node->children[i]);
        }
        return volume;
    }

    if((node->leaf && node->level <= this->rendLvlMax) || (this->RenderNonLeafNodes && node->level == this->rendLvlMax)){

        if((node->type==0 && !this->rendOut) || (node->type==1 && !this->rendOn) || (node->type==2 && !this->rendIn))
            return volume;

        volume = node->cube->getVolume();

        if(this->RenderNonLeafNodes)
            for(int i=0;i<8;i++)
                volume+=this->getVolume(node->children[i]);

    }else{

        for(int i=0;i<8;i++){
            if(i!=this->NonRenderRegion)
                volume+=this->getVolume(node->children[i]);
        }
    }

    return volume;
}
void Octree::NumberOfNodes(OctreeNode *node, int &In, int &On, int &Out, int &Leaf){

    if(node==NULL)
        return;


    if(this->OnlyLeafatLevel && node->level!=this->rendLvlMax){
        for(int i=0;i<8;i++){
            if(i!=this->NonRenderRegion)
                this->NumberOfNodes(node->children[i], In, On, Out, Leaf);
        }
        return;
    }

    if((node->leaf && node->level <= this->rendLvlMax) || (this->RenderNonLeafNodes && node->level == this->rendLvlMax)){

        if((node->type==0 && !this->rendOut) || (node->type==1 && !this->rendOn) || (node->type==2 && !this->rendIn))
            return;

        switch (node->type) {
        case 0:
            Out++;
            break;
        case 1:
            On++;
            break;
        case 2:
            In++;
            break;
        default:
            break;
        }

        if(node->leaf)
            Leaf++;

        if(this->RenderNonLeafNodes)
            for(int i=0;i<8;i++)
                this->NumberOfNodes(node->children[i], In, On, Out, Leaf);

    }else{

        for(int i=0;i<8;i++){
            if(i!=this->NonRenderRegion)
                this->NumberOfNodes(node->children[i], In, On, Out, Leaf);
        }
    }

}


void Octree::setRendIn(bool rendIn){
    this->rendIn=rendIn;
}
void Octree::setRendOn(bool rendOn){
    this->rendOn=rendOn;
}
void Octree::setRendOut(bool rendOut){
    this->rendOut = rendOut;
}
void Octree::setRenderNonLeafNodes(bool RenderNonLeafNodes){
    this->RenderNonLeafNodes=RenderNonLeafNodes;
}

void Octree::setWFIn(bool WFIn){
    this->WFIn=WFIn;
}
void Octree::setWFOn(bool WFOn){
    this->WFOn=WFOn;
}
void Octree::setWFOut(bool WFOut){
    this->WFOut = WFOut;
}
void Octree::setLevelMax(int LevelMax){
    this->rendLvlMax=LevelMax;
}
void Octree::setNonRenderRegion(int Region){
    this->NonRenderRegion=Region;
}
void Octree::setOnlyleafatLevel(bool OnlyLeafatLevel){
    this->OnlyLeafatLevel=OnlyLeafatLevel;
}

void Octree::setIn_Color(float R, float G, float B){
    this->In_Color->R=R;
    this->In_Color->G=G;
    this->In_Color->B=B;
}
void Octree::setOn_Color(float R, float G, float B){
    this->On_Color->R=R;
    this->On_Color->G=G;
    this->On_Color->B=B;
}
void Octree::setOut_Color(float R, float G, float B){
    this->Out_Color->R=R;
    this->Out_Color->G=G;
    this->Out_Color->B=B;
}

void Octree::setIn_Color_R(float R){
    this->In_Color->R=R;
}
void Octree::setIn_Color_G(float G){
    this->In_Color->G=G;
}
void Octree::setIn_Color_B(float B){
    this->In_Color->B=B;
}

void Octree::setOn_Color_R(float R){
    this->On_Color->R=R;
}
void Octree::setOn_Color_G(float G){
    this->On_Color->G=G;
}
void Octree::setOn_Color_B(float B){
    this->On_Color->B=B;
}

void Octree::setOut_Color_R(float R){
    this->Out_Color->R=R;
}
void Octree::setOut_Color_G(float G){
    this->Out_Color->G=G;
}
void Octree::setOut_Color_B(float B){
    this->Out_Color->B=B;
}
