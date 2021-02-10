#include "scene.h"

Scene::Scene()
{
    this->Name = "Nome Padrão";
}
Scene::Scene(QString Name)
{
    this->Name = Name;
}
void Scene::addOctree(Octree *o){
    this->octrees.push_back(o);
}

void Scene::addPrimitive(QString name, int type, float size,float sizeX,float sizeY,float sizeZ, float radius, float base, float height, float slices, float stacks, float R, float G, float B){

    Primitive *P = new Primitive(name, type, size, sizeX, sizeY, sizeZ, radius, base, height, slices, stacks,R,G,B);

    this->primitives.push_back(P);

}

void Scene::addMeshes(string filepath){

    ifstream readFile(filepath);
    string identifier, x, y, z, name, line;

    int sub_conj = this->meshes.size()-1;

    while(getline(readFile, line)){
        stringstream iss(line);
        getline(iss, identifier, ' ');

        if(identifier == "o"){
            getline(iss, name, ' ');
            Mesh* M = new Mesh(QString::fromStdString(name));
            this->meshes.push_back(M);
            sub_conj++;
        }

        if(identifier == "v"){

            getline(iss, x, ' ');
            getline(iss, y, ' ');
            getline(iss, z, ' ');

            this->meshes.at(sub_conj)->addPoint(QString::fromStdString(x).toFloat(), QString::fromStdString(y).toFloat(), QString::fromStdString(z).toFloat());

        }
        if(identifier == "f"){
            getline(iss, x, ' ');
            getline(iss, y, ' ');
            getline(iss, z, ' ');
            this->meshes.at(sub_conj)->addFace(stof(x)-1,stof(z)-1,stof(y)-1);

        }
    }
    for(std::vector<Mesh*>::iterator i = this->meshes.begin(); i != this->meshes.end(); i++)
        (*i)->attBBox();

}

bool Scene::removeMesh(QString name){
    bool find = false;
    std::vector<Mesh*>::iterator i = this->meshes.begin();
    while(!find && i!= this->meshes.end()){

        Mesh *p = (*i);
        if(name == p->name){
            this->meshes.erase(i);
            delete p;
            find=true;
        }
        i++;
    }
    return find;
}
//void Scene::addPrimitive(QString name, float size, float R, float G, float B){
//    if(size>0){
//        Primitive *P = new Primitive(name, size);
//        P->color->R=R;
//        P->color->G=G;
//        P->color->B=B;
//        this->primitives.push_back(P);
//    }
//}
//void Scene::addPrimitive(QString name, float radius, float slices, float stacks, float R, float G, float B){
//    if(radius>0){
//        Primitive *P = new Primitive(name, radius, slices, stacks);
//        P->color->R=R;
//        P->color->G=G;
//        P->color->B=B;
//        this->primitives.push_back(P);
//    }
//}
//void Scene::addPrimitive(QString name, float base, float height, float slices, float stacks, float R, float G, float B){
//    if(base>0 && height>0){
//        Primitive *P = new Primitive(name, base, height, slices, stacks);
//        P->color->R=R;
//        P->color->G=G;
//        P->color->B=B;
//        this->primitives.push_back(P);
//    }
//}
//void Scene::addPrimitive(QString name, float sizeX, float sizeY, float sizeZ, float R, float G, float B,  int add){
//    if(sizeX>0 && sizeY>0 && sizeZ>0){
//        Primitive *P = new Primitive(name, sizeX, sizeY, sizeZ, add);
//        P->color->R=R;
//        P->color->G=G;
//        P->color->B=B;
//        this->primitives.push_back(P);
//    }
//}

bool Scene::removePrimitive(QString name){
    bool find = false;
    std::vector<Primitive*>::iterator i = this->primitives.begin();
    while(!find && i!= this->primitives.end()){

        Primitive *p = (*i);
        if(name == p->name){
            this->primitives.erase(i);
            delete p;
            find=true;
        }
        i++;
    }
    return find;
}

bool Scene::TranslateObj(QString name, float fX, float fY, float fZ){
    bool find = false;
    std::vector<Primitive*>::iterator i = this->primitives.begin();
    while(!find && i!= this->primitives.end()){
        Primitive *p = (*i);
        if(name == p->name){
            p->Translate(fX, fY, fZ);
            find=true;
        }
        i++;
    }
    if(!find){
        std::vector<Octree*>::iterator i = this->octrees.begin();
        while(!find && i!= this->octrees.end()){
            Octree *p = (*i);
            if(name == p->name){
                p->Translate(fX, fY, fZ);
                find=true;
            }
            i++;
        }
    }

    if(!find){
        std::vector<Mesh*>::iterator i = this->meshes.begin();
        while(!find && i!= this->meshes.end()){
            Mesh *m = (*i);
            if(name == m->name){
                m->Translate(fX, fY, fZ);
                find=true;
            }
            i++;
        }
    }


    return find;
}
bool Scene::ScaleObj(QString name, float fX, float fY, float fZ){
    bool find = false;
    std::vector<Primitive*>::iterator i = this->primitives.begin();
    while(!find && i!= this->primitives.end()){
        Primitive *p = (*i);
        if(name == p->name){
            p->Scale(fX, fY, fZ);
            find=true;
        }
        i++;
    }
    if(!find){
        std::vector<Octree*>::iterator i = this->octrees.begin();
        while(!find && i!= this->octrees.end()){
            Octree *p = (*i);
            if(name == p->name){
                p->Scale(fX, fY, fZ);
                find=true;
            }
            i++;
        }
    }
    if(!find){
        std::vector<Mesh*>::iterator i = this->meshes.begin();
        while(!find && i!= this->meshes.end()){
            Mesh *m = (*i);
            if(name == m->name){
                m->Scale(fX, fY, fZ);
                find=true;
            }
            i++;
        }
    }

    return find;
}
bool Scene::RotateObj(QString name, int axis, float angle){
    bool find = false;
    std::vector<Primitive*>::iterator i = this->primitives.begin();
    while(!find && i!= this->primitives.end()){
        Primitive *p = (*i);
        if(name == p->name){
            p->Rotate(angle, axis);
            find=true;
        }
        i++;
    }
    if(!find){
        std::vector<Octree*>::iterator i = this->octrees.begin();
        while(!find && i!= this->octrees.end()){
            Octree *p = (*i);
            if(name == p->name){
                p->Rotate(angle, axis);
                find=true;
            }
            i++;
        }
    }
    if(!find){
        std::vector<Mesh*>::iterator i = this->meshes.begin();
        while(!find && i!= this->meshes.end()){
            Mesh *m = (*i);
            if(name == m->name){
                m->Rotate(angle, axis);
                find=true;
            }
            i++;
        }
    }
    return find;
}
bool Scene::CleanObj(QString name){
    bool find = false;
    std::vector<Primitive*>::iterator i = this->primitives.begin();
    while(!find && i!= this->primitives.end()){
        Primitive *p = (*i);
        if(name == p->name){
            float M[4][4] ={{1.0f, 0.0f, 0.0f, 0.0f},
                            {0.0f, 1.0f, 0.0f, 0.0f},
                            {0.0f, 0.0f, 1.0f, 0.0f},
                            {0.0f, 0.0f, 0.0f, 1.0f}};
            p->setToWordMatrix(M);
            find=true;
        }
        i++;
    }

    if(!find){
        std::vector<Octree*>::iterator i = this->octrees.begin();
        while(!find && i!= this->octrees.end()){
            Octree *p = (*i);
            if(name == p->name){
                float M[4][4] ={{1.0f, 0.0f, 0.0f, 0.0f},
                                {0.0f, 1.0f, 0.0f, 0.0f},
                                {0.0f, 0.0f, 1.0f, 0.0f},
                                {0.0f, 0.0f, 0.0f, 1.0f}};
                for(int i=0; i<4;i++)
                    for(int j=0; j<4;j++)
                        p->transformMatrix[i][j] = M[i][j];
                find=true;
            }
            i++;
        }
    }

    if(!find){
        std::vector<Mesh*>::iterator i = this->meshes.begin();
        while(!find && i!= this->meshes.end()){
            Mesh *p = (*i);
            if(name == p->name){
                float M[4][4] ={{1.0f, 0.0f, 0.0f, 0.0f},
                                {0.0f, 1.0f, 0.0f, 0.0f},
                                {0.0f, 0.0f, 1.0f, 0.0f},
                                {0.0f, 0.0f, 0.0f, 1.0f}};
                for(int i=0; i<4;i++)
                    for(int j=0; j<4;j++)
                        p->toWordMatrix[i][j] = M[i][j];
                find=true;
            }
            i++;
        }
    }
    return find;
}

Primitive* Scene::getPrimitive(QString name){
    bool find = false;
    std::vector<Primitive*>::iterator i = this->primitives.begin();
    while(!find && i!= this->primitives.end()){
        Primitive *p = (*i);
        if(name == p->name){
            return p;
        }
        i++;
    }
    return NULL;
}
Octree* Scene::getOctree(QString name){
    bool find = false;
    std::vector<Octree*>::iterator i = this->octrees.begin();
    while(!find && i!= this->octrees.end()){
        Octree *o = (*i);
        if(name == o->name){
            return o;
        }
        i++;
    }
    return NULL;
}
bool Scene::removeOctree(QString name){
    bool find = false;
    std::vector<Octree*>::iterator i = this->octrees.begin();
    while(!find && i!= this->octrees.end()){

        Octree *o = (*i);
        if(name == o->name){
            this->octrees.erase(i);
            delete o;
            find=true;
        }
        i++;
    }
    return find;
}



ColorRGB Scene::Ray_Pix_Ilm(Point Po, Point D){
    ColorRGB Ray_Pix(this->Bg->R,this->Bg->G,this->Bg->B);
    return Ray_Pix;
}


//void Scene::addCube(QString name, float cX, float cY, float cZ, float size){
//    if(size>0){
//        Cube *c = new Cube(name, cX, cY, cZ, size);
//        this->cubes.push_back(c);
//    }
//}
//void Scene::addCube(QString name, float cX, float cY, float cZ, float size, float r, float g, float b){
//    std::cout << "Teste1";
//    if(size>0){
//        Cube *c = new Cube(name, cX, cY, cZ, size, r, g, b);
//        this->cubes.push_back(c);
//    }
//}
//bool Scene::removeCube(QString id){
//    bool find = false;
//    std::vector<Cube*>::iterator i = this->cubes.begin();
//    while(!find && i!= this->cubes.end()){
//        Cube *c = (*i);
//        if(id == c->name){
//            this->cubes.erase(i);
//            find=true;
//        }
//        i++;
//    }
//    return find;
//}

//void Scene::addSphere(QString name, float cX, float cY, float cZ, float radius, int slices, int stacks, float r, float g, float b){

//    if(radius>0){
//        ColorRGB *c = new ColorRGB(r,g,b);
//        Sphere *s = new Sphere(name, cX, cY, cZ, radius, slices, stacks, c);
//        this->spheres.push_back(s);
//    }
//}
//bool Scene::removeSphere(QString id){
//    bool find = false;
//    std::vector<Sphere*>::iterator i = this->spheres.begin();
//    while(!find && i!= this->spheres.end()){
//        Sphere *s = (*i);
//        if(id == s->name){
//            this->spheres.erase(i);
//            find=true;
//        }
//        i++;
//    }
//    return find;
//}

//bool Scene::TranslateCube(QString id, float fX, float fY, float fZ){
//    bool find = false;
//    std::vector<Cube*>::iterator i = this->cubes.begin();
//    while(!find && i!= this->cubes.end()){
//        Cube *c = (*i);
//        if(id == c->name){
////            c->center->translate(fX, fY, fZ);
//            c->translate(fX,fY,fZ);
//            find=true;
//        }
//        i++;
//    }
//    return find;
//}

//bool Scene::ScaleCube(QString id, float fX, float fY, float fZ){
//    bool find = false;
//    std::vector<Cube*>::iterator i = this->cubes.begin();
//    while(!find && i!= this->cubes.end()){
//        Cube *c = (*i);
//        if(id == c->name){
//            c->scale(fX,fY,fZ);
//            find=true;
//        }
//        i++;
//    }
//    return find;
//}

//bool Scene::RotateCube(QString id, float Ang, int eixo){
//    bool find = false;
//    std::vector<Cube*>::iterator i = this->cubes.begin();
//    while(!find && i!= this->cubes.end()){
//        Cube *c = (*i);
//        if(id == c->name){
//            c->rotate(Ang, eixo);
//            find=true;
//        }
//        i++;
//    }
//    return find;
//}

//bool Scene::CleanCube(QString id){
//    bool find = false;
//    std::vector<Cube*>::iterator i = this->cubes.begin();
//    while(!find && i!= this->cubes.end()){
//        Cube *c = (*i);
//        if(id == c->name){
//            float M[4][4] ={{1.0f, 0.0f, 0.0f, 0.0f},
//                            {0.0f, 1.0f, 0.0f, 0.0f},
//                            {0.0f, 0.0f, 1.0f, 0.0f},
//                            {0.0f, 0.0f, 0.0f, 1.0f}};
//            c->setMatrix(M);
//            find=true;
//        }
//        i++;
//    }
//    return find;
//}


void Scene::addMesh(Mesh *M){
    this->meshes.push_back(M);
}
Mesh* Scene::getMesh(QString name){
    bool find = false;
    std::vector<Mesh*>::iterator i = this->meshes.begin();
    while(!find && i!= this->meshes.end()){
        Mesh *m = (*i);
        if(name == m->name){
            return m;
        }
        i++;
    }
    return NULL;
}
string Scene::SceneInformations(){

    string informations = "\n Scene Informations: ";
    int NPrimitives = this->primitives.size(),
            NMeshes = this->meshes.size(),
            NOctrees = this->octrees.size();

    informations += "\n\n"+to_string(NPrimitives)+" Primitives; \n" + to_string(NMeshes)+" Meshes; \n" + to_string(NOctrees) + " Octrees;\n";
    if(this->rendPrimitives && NPrimitives>0)
    for(vector<Primitive*>::iterator i = this->primitives.begin(); i != this->primitives.end(); i++){
        Primitive *p = (*i);

        switch (p->type) {
        case 0:
            informations += "\nCube: "+p->name.toStdString()+"\nSize: "+to_string(p->size)+"; Vol: " + to_string(p->getVolume())+"; Area: " + to_string(p->getArea())+";";
            break;
        case 1:
            informations += "\nSphere: "+p->name.toStdString()+"\nRadius: "+to_string(p->radius)+"; Vol: " + to_string(p->getVolume())+"; Area: " + to_string(p->getArea())+";";
            break;
        case 2:
            informations += "\nCone: "+p->name.toStdString()+"\nBase: "+to_string(p->base)+"; Height: "+ to_string(p->height)+"; Vol: " + to_string(p->getVolume())+"; Area: " + to_string(p->getArea())+";";
            break;
        case 3:
            informations += "\nCylinder: "+p->name.toStdString()+"\nBase: "+to_string(p->base)+"; Height: " + to_string(p->height)+"; Vol: " + to_string(p->getVolume())+"; Area: " + to_string(p->getArea())+";";
            break;
        case 4:
            informations += "\nBox: "+p->name.toStdString()+"\nSizeX: "+to_string(p->sizeX)+"; sizeY: " + to_string(p->sizeY)+"; sizeZ: " + to_string(p->sizeZ)+"; Vol: " + to_string(p->getVolume())+"; Area: " + to_string(p->getArea())+";";
            break;
        default:
            break;
        }
    }


    if(this->rendMeshes && NMeshes>0){
        informations+="\n\n";
        for(vector<Mesh*>::iterator i = this->meshes.begin(); i!= this->meshes.end();i++){
            Mesh *M = (*i);
            informations+="\nMesh name: " +M->name.toStdString() +"; Vertices: "+to_string(M->points.size())+"; Faces: "+to_string(M->faces.size())+";";
            informations+="\nMin X: " + to_string(M->mX)+"; Min Y: " + to_string(M->mY)+"; Min Z: " + to_string(M->mZ);
            informations+="\nMax X: " + to_string(M->MX)+"; Max Y: " + to_string(M->MY)+"; Max Z: " + to_string(M->MZ);
            informations+="\n Surface Area: " + to_string(M->SurfaceArea());
            Cube *c = M->getCube();
            informations+="\nBBox Volume:" + to_string(c->getVolume()) + "; BBox Surface Area: " + to_string(c->getArea());
            // Número de Faces; Área de fronteira;

        }
    }

    if(this->rendOctrees && NOctrees>0){
        informations+="\n\n";
        for(vector<Octree*>::iterator i = this->octrees.begin(); i != this->octrees.end(); i++){
            Octree *o = (*i);
            informations+= "\nOctree Name: "+ o->name.toStdString();
            informations+= ", Volume: " + to_string(o->getVolume());

            int nIn =0, nOn=0, nOut=0, nLeaf=0;
            o->NumberOfNodes(o->root, nIn, nOn, nOut, nLeaf);
            int nTotal = nIn+nOn+nOut;
            informations+="\nNumber of Nodes("+to_string(nTotal)+"): In: " + to_string(nIn) + ", On: " + to_string(nOn) + ", Out: " + to_string(nOut) + ", Leaf: " + to_string(nLeaf);


        }
    }


    return informations;
}
