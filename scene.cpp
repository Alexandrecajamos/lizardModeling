#include "scene.h"

Scene::Scene()
{
    this->Name = "Nome Padrão";
}
Scene::Scene(QString Name)
{
    this->Name = Name;

    Light *L = new Light(ColorRGB(0.8,0.8,0.8), new Point(50, 50, 50));
    this->lights.push_back(L);


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
    if(!find){
        std::vector<CSGnode*>::iterator i = this->csg_trees.begin();
        while(!find && i!= this->csg_trees.end()){
            CSGnode *m = (*i);
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

    if(!find){
        std::vector<CSGnode*>::iterator i = this->csg_trees.begin();
        while(!find && i!= this->csg_trees.end()){
            CSGnode *m = (*i);
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
            p->Rotate(axis, angle);
            find=true;
        }
        i++;
    }
    if(!find){
        std::vector<Octree*>::iterator i = this->octrees.begin();
        while(!find && i!= this->octrees.end()){
            Octree *p = (*i);
            if(name == p->name){
                p->Rotate(axis, angle);
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
                m->Rotate(axis, angle);
                find=true;
            }
            i++;
        }
    }

    if(!find){
        std::vector<CSGnode*>::iterator i = this->csg_trees.begin();
        while(!find && i!= this->csg_trees.end()){
            CSGnode *m = (*i);
            if(name == m->name){
                m->Rotate(axis, angle);
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
            p->setWlMatrix(M);
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

    if(!find){
        std::vector<CSGnode*>::iterator i = this->csg_trees.begin();
        while(!find && i!= this->csg_trees.end()){
            CSGnode *p = (*i);
            if(name == p->name){
                float M[4][4] ={{1.0f, 0.0f, 0.0f, 0.0f},
                                {0.0f, 1.0f, 0.0f, 0.0f},
                                {0.0f, 0.0f, 1.0f, 0.0f},
                                {0.0f, 0.0f, 0.0f, 1.0f}};
                for(int i=0; i<4;i++)
                    for(int j=0; j<4;j++){
                        p->toWordMatrix[i][j] = M[i][j];
                        p->Wl[i][j] = M[i][j];
                    }
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

    float cam_Word[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    this->observer->Cam_Word(cam_Word);

    float vPo[4] = {Po.x, Po.y, Po.z, 1};
    float vD[4] = {D.x, D.y, D.z, 0};

    Point PoL = Mxv(cam_Word, vPo);
    Point DL = Mxv(cam_Word, vD);


    ColorRGB Ray_Pix(this->Bg->R,this->Bg->G,this->Bg->B);


//     int iPrimitive = -1;
//    float t = Ray_intersept_primitive(Po, D, iPrimitive);


//    if(t != -1 && t>0)
//    {

//        Primitive *primitive = this->primitives.at(iPrimitive);
//        Material *material = primitive->material;

//        Point Pint(D.x, D.y, D.z);
//        Pint.operator *=(t);
//        Point nPrimitive(Po.x, Po.y, Po.z);
//        nPrimitive.operator +=(Pint);
//        nPrimitive.normalize();

//        ColorRGB A(material->A.R*this->Amb->R,material->A.G*this->Amb->G,material->A.B*this->Amb->B);

//        float Dr=0, Dg=0, Db=0, Er=0, Eg=0, Eb=0;

//        for(std::vector<Light*>::iterator i = this->lights.begin(); i != this->lights.end(); i++){

//            Light* light = (*i);
//            Point light_pos(light->Pos->x, light->Pos->y, light->Pos->z);

////            light_pos.transform(WordCam);

//            light_pos.operator -=(Pint);
////            light_pos.normalize();

//            float xDif = dot(nPrimitive, light_pos);

//            Point v(Po.x, Po.y, Po.z);
//            v.operator -=(Pint);
//            v.normalize();
//            Point r(nPrimitive.x, nPrimitive.y, nPrimitive.z);
//            r.operator *=(2*xDif);
//            r.operator -=(light_pos);
//            r.normalize();

//            float xEsp = dot(v, r);
//            xEsp = pow(xEsp, material->m);

//            if(xDif > 0){
//                Dr += light->fontColor.R*xDif;
//                Dg += light->fontColor.G*xDif;
//                Db += light->fontColor.B*xDif;
//            }
//            if(xEsp > 0){
//                Er += light->fontColor.R*xEsp;
//                Eg += light->fontColor.G*xEsp;
//                Eb += light->fontColor.B*xEsp;
//            }
////            std::cout <<"\nTeste: " << Dr << ", " << Dg << ", " << Db << ";";
////            std::cout <<"\nTeste2: " << Er << ", " << Eg << ", " << Eb << ";";
//        }

//        ColorRGB Dif(material->D.R*Dr,material->D.G*Dg,material->D.B*Db);
//        ColorRGB E(material->E.R*Er,material->E.G*Eg,material->E.B*Eb);

//        Ray_Pix.R = A.R + Dif.R + E.R;
//        Ray_Pix.G = A.G + Dif.G + E.G;
//        Ray_Pix.B = A.B + Dif.B + E.B;

//        Ray_Pix.normalize();

//    }


    if(this->csg_trees.size()>0){

        int iCSG = this->csg_trees.size()-1;

        std::vector<Intersection*> list = this->csg_trees.at(iCSG)->Ray_intersept(PoL, DL);

        if(list.size()>0){

//            Ray_Pix.R=list.at(0)->p->color->R;; Ray_Pix.G=list.at(0)->p->color->G; Ray_Pix.B=list.at(0)->p->color->B;


            Primitive *primitive = list.front()->p;
            Material *material = primitive->material;


//            Ray_Pix.R=1; Ray_Pix.G=1; Ray_Pix.B =1;


//            Point Pint(DL.x, DL.y, DL.z);
//            Pint.operator *=(list.front()->t);

            Point Pint(list.at(0)->Pintersection->x,list.at(0)->Pintersection->y,list.at(0)->Pintersection->z);


            Point nPrimitive(PoL.x, PoL.y, PoL.z);
            nPrimitive.operator +=(Pint);
            nPrimitive.normalize();

            Point *normal = list.front()->normal = new Point(nPrimitive.x, nPrimitive.y, nPrimitive.z);
//            normal->ImpPoint();

            ColorRGB A(material->A.R*this->Amb->R,material->A.G*this->Amb->G,material->A.B*this->Amb->B);

            float Dr=0, Dg=0, Db=0, Er=0, Eg=0, Eb=0;

            for(std::vector<Light*>::iterator i = this->lights.begin(); i != this->lights.end(); i++){

                Light* light = (*i);
                Point light_pos(light->Pos->x, light->Pos->y, light->Pos->z);

                //light_pos.transform(WordCam);

                light_pos.operator -=(Pint);
                light_pos.normalize();

                float xDif = dot(*normal, light_pos);

                Point v(PoL.x, PoL.y, PoL.z);
                v.operator -=(Pint);
                v.normalize();
                Point r(normal->x, normal->y, normal->z);
                r.operator *=(2*xDif);
                r.operator -=(light_pos);
                r.normalize();

                float xEsp = dot(v, r);
                xEsp = pow(xEsp, material->m);

                if(xDif > 0){
                    Dr += light->fontColor.R*xDif;
                    Dg += light->fontColor.G*xDif;
                    Db += light->fontColor.B*xDif;
                }
                if(xEsp > 0){
                    Er += light->fontColor.R*xEsp;
                    Eg += light->fontColor.G*xEsp;
                    Eb += light->fontColor.B*xEsp;
                }
//                std::cout <<"\nTeste: " << Dr << ", " << Dg << ", " << Db << ";";
//                std::cout <<"\nTeste2: " << Er << ", " << Eg << ", " << Eb << ";";
           }

            ColorRGB Dif(material->D.R*Dr,material->D.G*Dg,material->D.B*Db);
            ColorRGB E(material->E.R*Er,material->E.G*Eg,material->E.B*Eb);

            Ray_Pix.R = A.R + Dif.R + E.R;
            Ray_Pix.G = A.G + Dif.G + E.G;
            Ray_Pix.B = A.B + Dif.B + E.B;

            Ray_Pix.normalize();

        }


    }

    return Ray_Pix;


}
void Scene::setObserver(float Ex, float Ey, float Ez, float Lox, float Loy, float Loz, float Avx, float Avy, float Avz){
    Point Eye(Ex, Ey, Ez);
    Point La(Lox,Loy, Loz);
    Point Av(Avx, Avy, Avz);
    free(this->observer);
    this->observer = new Observer(Eye, La, Av);
}

float Scene::Ray_intersept_primitive(Point Po, Point D, int &iPrimitive){
    float Tint=99999;
    int cont=0;

    float vPo[4] = {Po.x, Po.y, Po.z, 1};
    float vD[4] = {D.x, D.y, D.z, 0};
    float Vl[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

    this->observer->Cam_Word(Vl);


    Point PoL = Mxv(Vl, vPo);
    Point DL = Mxv(Vl, vD);

    for(std::vector<Primitive*>::iterator i = this->primitives.begin(); i!= this->primitives.end();i++){
//        float t0 = -1, t1=-1;

//        float M[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
//        multiplyMatrix((*i)->Wl, Vl, M);

//        Point PoL = Mxv(M, vPo);
//        Point DL = Mxv(M, vD);

        std::vector<Intersection*> list = (*i)->Ray_intersept(PoL, DL);
        if(list.size()>0){
            iPrimitive = cont;
            Tint = list.at(0)->t;
//            std::cout << "\nTint: " << Tint;
//            D.ImpPoint();
        }

        cont++;
    }
    if(Tint != 99999)
        return Tint;
    return -1;

}



std::vector<Intersection*> Scene::Edge_intersept_CSG(QString name, float p0x,float p0y,float p0z,float p1x,float p1y,float p1z, bool infinity){


    Point O(p0x, p0y, p0z);
    Point D(p1x, p1y, p1z);D.operator -=(O);
    float tamD = D.length();
    D.normalize();


    std::vector<Intersection*> R;

    CSGnode *csg = this->getCSG(name);

    if(csg == NULL)
        return R;

    R = csg->Ray_intersept(O,D);

    if(infinity)
        return R;


    std::vector<Intersection*> nR;

    for(std::vector<Intersection*>::iterator i = R.begin(); i!= R.end(); i++){
        if((*i)->t >= 0 && (*i)->t<tamD)
            nR.push_back((*i));
    }
    return nR;

}





CSGnode* Scene::getCSG(QString name){
    bool find = false;
    std::vector<CSGnode*>::iterator i = this->csg_trees.begin();
    while(!find && i!= this->csg_trees.end()){
        CSGnode *csg = (*i);
        if(name == csg->name){
            return csg;
        }
        i++;
    }
    return NULL;
}
bool Scene::removeCSG(QString name){
    bool find = false;
    std::vector<CSGnode*>::iterator i = this->csg_trees.begin();
    while(!find && i!= this->csg_trees.end()){
        CSGnode *csg = (*i);
        if(name == csg->name){
            this->csg_trees.erase(i);
            return true;
        }
        i++;
    }
    return false;
}

bool Scene::createCSG(QString name, QString A, QString B, int Opr){

    Primitive *pA = this->getPrimitive(A);
    Primitive *pB = this->getPrimitive(B);

    CSGnode *L, *R;


    if(pA == NULL){
        L = this->getCSG(A);
        if(L == NULL)
            return false;
//        else
//            this->removeCSG(A);
    }
    else
        L = new CSGnode(pA);


    if(pB == NULL){
        R = this->getCSG(B);
        if(R == NULL)
            return false;
//        else
//            this->removeCSG(B);
    }
    else
        R = new CSGnode(pB);


    CSGnode *csg = new CSGnode(name, L,R, Opr);

    this->csg_trees.push_back(csg);
    return true;

}
bool Scene::createCSG(QString name, QString s){

    CSGnode *csg = this->build_csg(s.toStdString());
    if(csg != NULL){
        csg->name = name;
        this->csg_trees.push_back(csg);
        return true;
    }
    return false;
}


bool Scene::primitiveToCSG(QString CSG, QString P, int Opr){

    Primitive *p = this->getPrimitive(P);
    CSGnode *L = this->getCSG(CSG);

    if(p == NULL || L == NULL)
        return false;

    this->removeCSG(CSG);

    CSGnode *R = new CSGnode(p);

    L->name = CSG+ "- L";
    R->name = CSG+ "- R";

    std::cout << "\n" + L->name.toStdString();
    std::cout << "\n" + R->name.toStdString();

    CSGnode *newRoot = new CSGnode(CSG, L, R, Opr);
    this->csg_trees.push_back(newRoot);


//    this->csg_trees.erase(*L);
    return true;

}

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
            NOctrees = this->octrees.size(),
            NCSG = this->csg_trees.size();

    informations += "\n\n"+to_string(NPrimitives)+" Primitives; \n" + to_string(NMeshes)+" Meshes; \n" + to_string(NOctrees) + " Octrees;\n"+ to_string(NCSG) + " CSG Trees;\n";
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


    if(NCSG>0){
        informations+="\n\n";
        for(vector<CSGnode*>::iterator i = this->csg_trees.begin(); i!= this->csg_trees.end();i++){
            CSGnode *csg = (*i);
            informations+="\nCSG Name: " + csg->name.toStdString();
            informations+= " = " + csg->getEquation().toStdString() +";\n";
        }
    }
    return informations;
}

CSGnode* Scene::build_csg(string s){
    CSGnode *csg;
    float lS = s.length();

    if(lS==1){
        csg = new CSGnode(this->primitives.at(int(s[0]-'0')));
    }else{

        int Op;

        switch (s[0]) {
        case 'U':
            Op=0;
            break;
        case 'I':
            Op=1;
            break;
        case 'D':
            Op=2;
            break;
        default:
            Op=0;
            break;
        }

        int Lmin=2, Lmax=-1, Dmin=-1,Dmax=(lS-2);

        if(s[3] == ','){
            Lmax = 2; Dmin=4;
        }else{
            int i = 4, a = 1, f = 0;
            while(a>f){
                if(s[i] == '(')
                    a++;
                if(s[i] == ')')
                    f++;
                i++;
            }
            Lmax = i-1; Dmin = i+2;
        }


        string sL = s.substr(Lmin,(Lmax-Lmin)+1);
        string sD = s.substr(Dmin,(Dmax-Dmin)+1);

//        std::cout << "\nS: " << s;
//        std::cout << "\nTeste L: " << sL;
//        std::cout << "\nTeste D: " << sD;

        CSGnode *L = this->build_csg(sL);
        CSGnode *D = this->build_csg(sD);

        csg = new CSGnode(QString::fromStdString(s), L, D, Op);


    }
    return csg;

}
