#include "glwidget.h"
#include "cube.h"
#include "face.h"
#include "edge.h"


GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{

    connect( &timer, SIGNAL(timeout()), this, SLOT(updateGL()) );
    timer.start(16);
}

void GLWidget::initializeGL()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
//    this->scene->addPrimitive(QString("Cubo"), 2, 1,1,1);

//    vector<Mesh*> Objs = this->ReadMeshes(this->Lizard_path);

//    for(vector<Mesh*>::iterator i = Objs.begin(); i!=Objs.end(); i++)
//        this->scene->addMesh(*i);


}
void GLWidget::paintGL()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);


//    Point *p0 = new Point(1,1,6);
//    float b = 2, h = 5, sl = 10, st=10;
//    Primitive *Cone = new Primitive(QString("Name0"),b,h,sl,st);
//    std::cout << "\n" << Cone->type;

//    std::cout << "\nTeste: " << Cone->PointInCone(p0);
//    Point *p1 = new Point(5,0,0);
//    Point *p2 = new Point(0,0,0);

//    Face *f = new Face(p0,p1,p2);
//    paintFace(f);

//    Point *p = new Point(2,0,2);
//    Point *px = new Point(2,-2,2);
//    px->normalize();

//    Point *o = new Point(2,1,2);
//    o->operator -=(*px);

//    std::cout << "\n Teste: " << f->PointIntersept(p);


//    std::cout << "\n Teste2: " << f->Ray_intersept(*o, *px);


//    //    Point *o = new Point(f->N.x, f->N.y, f->N.z);

//    Cube *c = new Cube(QString("Cubo"), 0,0,0,1);

//    std::cout << "\n Teste: " << f->CubeIntersept(c);



//    Point *p =
//    f->Inter()


//    Cube *c = this->scene->meshes.at(0)->getCube();
//    glBegin(GL_POLYGON);

//        glColor3f(1,1,1);

//        //F0: 0, 1, 2, 3
//        glVertex3f(c->vertices[0]->x,c->vertices[0]->y,c->vertices[0]->z);
//        glVertex3f(c->vertices[1]->x,c->vertices[1]->y,c->vertices[1]->z);
//        glVertex3f(c->vertices[2]->x,c->vertices[2]->y,c->vertices[2]->z);
//        glVertex3f(c->vertices[3]->x,c->vertices[3]->y,c->vertices[3]->z);
//        //F1: 1, 5, 7, 3
//        glVertex3f(c->vertices[1]->x,c->vertices[1]->y,c->vertices[1]->z);
//        glVertex3f(c->vertices[5]->x,c->vertices[5]->y,c->vertices[5]->z);
//        glVertex3f(c->vertices[7]->x,c->vertices[7]->y,c->vertices[7]->z);
//        glVertex3f(c->vertices[3]->x,c->vertices[3]->y,c->vertices[3]->z);
//        //F2: 5, 4, 6, 7
//        glVertex3f(c->vertices[5]->x,c->vertices[5]->y,c->vertices[5]->z);
//        glVertex3f(c->vertices[4]->x,c->vertices[4]->y,c->vertices[4]->z);
//        glVertex3f(c->vertices[6]->x,c->vertices[6]->y,c->vertices[6]->z);
//        glVertex3f(c->vertices[7]->x,c->vertices[7]->y,c->vertices[7]->z);
//        //F3: 4, 0, 2, 6
//        glVertex3f(c->vertices[4]->x,c->vertices[4]->y,c->vertices[4]->z);
//        glVertex3f(c->vertices[0]->x,c->vertices[0]->y,c->vertices[0]->z);
//        glVertex3f(c->vertices[2]->x,c->vertices[2]->y,c->vertices[2]->z);
//        glVertex3f(c->vertices[6]->x,c->vertices[6]->y,c->vertices[6]->z);
//        //F4: 2, 3, 7, 6
//        glVertex3f(c->vertices[2]->x,c->vertices[2]->y,c->vertices[2]->z);
//        glVertex3f(c->vertices[3]->x,c->vertices[3]->y,c->vertices[3]->z);
//        glVertex3f(c->vertices[7]->x,c->vertices[7]->y,c->vertices[7]->z);
//        glVertex3f(c->vertices[6]->x,c->vertices[6]->y,c->vertices[6]->z);
////        F5: 1, 0, 4, 5
//        glVertex3f(c->vertices[1]->x,c->vertices[1]->y,c->vertices[1]->z);
//        glVertex3f(c->vertices[0]->x,c->vertices[0]->y,c->vertices[0]->z);
//        glVertex3f(c->vertices[4]->x,c->vertices[4]->y,c->vertices[4]->z);
//        glVertex3f(c->vertices[5]->x,c->vertices[5]->y,c->vertices[5]->z);



//    glEnd();


    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(1000,0,0);

        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,1000,0);

        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,1000);
    glEnd();


//    float M[4][4] = {{1,0,0,0.5},
//                     {0,1,0,0.5},
//                     {0,0,1,0.5},
//                     {0,0,0,1}};
//    QString name = "Nome";
//    Primitive *s1 = new Primitive(name, 1, 10,10);

//    Cube *c = new Cube(name, 0.0f, 0.0f, 0.0f, 3);
//    std::vector<Cube*> filhos = c->Divide8();

//    for(std::vector<Cube*>::iterator i = filhos.begin(); i!= filhos.end(); i++)
//    {
//         Cube *c = (*i);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);
//         glColor3f(1,1,1);
//         glTranslatef(c->center->x, c->center->y, c->center->z);
//         glutWireCube(c->size);
//    }

//    std::vector<Cube*> nFilhos = filhos[0]->Divide8();

//    nFilhos = nFilhos[5]->Divide8();
//    int cont = 0;
//    for(std::vector<Cube*>::iterator i = nFilhos.begin(); i!= nFilhos.end(); i++)
//    {
//         Cube *c = (*i);
//         bool teste =  s1->CubeIntersect(c);


//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);
//         glColor3f(1,1,1);
//         glTranslatef(c->center->x, c->center->y, c->center->z);

//         if(teste){
//             glutSolidCube(c->size);
//         }else{
//             glColor3f(1,0,0);
//             glutWireCube(c->size);
//         }



//         std::cout << "\nTeste C"<<cont<<": " << teste;
//         cont++;
//    }



//    glColor3f(1,1,1);
//    glTranslatef(c->center->x, c->center->y, c->center->z);
//    glutWireCube(c->size);

    if(this->scene->rendPrimitives)
        paintPrimitives();
    if(this->scene->rendMeshes)
        paintMeshes();
    if(this->scene->rendOctrees)
        paintOctrees();

}
void GLWidget::resizeGL(int w, int h)
{    
    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w/h, 1, 1000.0);
    updateGL();
}


void GLWidget::paintLocalAxis(float X, float Y, float Z){

    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(X,0,0);

        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,Y,0);

        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,Z);
    glEnd();
}
void GLWidget::paintPrimitives(){

    float m[16] = {1,0,0,0,
                   0,1,0,0,
                   0,0,1,0,
                   0,0,0,1};

    if(this->scene->wireFrame){
        for(std::vector<Primitive*>::iterator i = this->scene->primitives.begin(); i!= this->scene->primitives.end(); i++)
        {
            Primitive *p = (*i);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);
            glColor3f(p->color->R,p->color->G,p->color->B);
            p->getToWordMatrix(m);
            glMultMatrixf(m);
            GLUquadricObj *obj;

            switch (p->type) {
            case 0:
                glutWireCube(p->size);
                paintLocalAxis(p->size+1,p->size+1,p->size+1);
                break;
            case 1:
                glutWireSphere(p->radius, p->slices, p->stacks);
                paintLocalAxis(p->radius+1,p->radius+1,p->radius+1);
                break;
            case 2:
                glutWireCone(p->base, p->height, p->slices, p->stacks);
                paintLocalAxis(p->base+1,p->base+1,p->height+1);
                break;
            case 3:
//                glutWireCylinder(1,1,10,10);
                obj = gluNewQuadric();
                gluCylinder(obj, p->base, p->base, p->height, p->slices, p->stacks);
                break;
            case 4:                
                glScalef(p->sizeX, p->sizeY, p->sizeZ);
                glutWireCube(1);
                paintLocalAxis(p->sizeX+1,p->sizeY+1,p->sizeZ+1);
                break;

            default:
                break;
            }
        }


    }else{
        for(std::vector<Primitive*>::iterator i = this->scene->primitives.begin(); i!= this->scene->primitives.end(); i++)
        {
            Primitive *p = (*i);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);
            glColor3f(p->color->R,p->color->G,p->color->B);
            p->getToWordMatrix(m);
            glMultMatrixf(m);
            GLUquadricObj *obj;

            switch (p->type) {
            case 0:
                glutSolidCube(p->size);
                paintLocalAxis(p->size+1,p->size+1,p->size+1);
                break;
            case 1:
                glutSolidSphere(p->radius, p->slices, p->stacks);
                paintLocalAxis(p->radius+1,p->radius+1,p->radius+1);
                break;
            case 2:
                glutSolidCone(p->base, p->height, p->slices, p->stacks);
                paintLocalAxis(p->base+1,p->base+1,p->height+1);
                break;
            case 3:
                obj = gluNewQuadric();
                gluCylinder(obj, p->base, p->base, p->height, p->slices, p->stacks);
                break;
            case 4:
                glScalef(p->sizeX, p->sizeY, p->sizeZ);
                glutSolidCube(1);
                paintLocalAxis(p->sizeX+1,p->sizeY+1,p->sizeZ+1);
                break;
            default:
                break;
            }
        }

    }

}
void GLWidget::paintOctrees(){

    for(std::vector<Octree*>::iterator i = this->scene->octrees.begin(); i!= this->scene->octrees.end(); i++){
        Octree *o = (*i);
        paintOctreeNode(o, o->root);
    }
}
void GLWidget::paintOctreeNode(Octree *octree, OctreeNode *node){


    if(node==NULL)
        return;

    // Se só quiser as folhas do nível exato:

    if(octree->OnlyLeafatLevel && node->level!=octree->rendLvlMax){
        for(int i=0;i<8;i++){
            if(i!=octree->NonRenderRegion)
                paintOctreeNode(octree, node->children[i]);
        }
        return;
    }

    if((node->leaf && node->level <= octree->rendLvlMax) || (octree->RenderNonLeafNodes && node->level == octree->rendLvlMax)){

        if((node->type==0 && !octree->rendOut) || (node->type==1 && !octree->rendOn) || (node->type==2 && !octree->rendIn))
            return;

        Cube *c = node->cube;

        glLoadIdentity();
        gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);

        float m[16] = {1,0,0,0,
                       0,1,0,0,
                       0,0,1,0,
                       0,0,0,1};

        octree->getToWordMatrix(m);
        glMultMatrixf(m);
        glTranslatef(c->center->x, c->center->y, c->center->z);

        ColorRGB *color;

        switch (node->type) {
        case 0:
            color=octree->Out_Color;
            break;
        case 1:
            color=octree->On_Color;
            break;
        case 2:
            color=octree->In_Color;
        default:
            break;
        }
        glColor3f(color->R, color->G, color->B);

        if((node->type==0 && octree->WFOut) || (node->type==1 && octree->WFOn) || (node->type==2 && octree->WFIn))
            glutWireCube(c->size);
        else
            glutSolidCube(c->size);


        if(octree->RenderNonLeafNodes)
            for(int i=0;i<8;i++)
                paintOctreeNode(octree, node->children[i]);

    }else{

        for(int i=0;i<8;i++){
            if(i!=octree->NonRenderRegion)
                paintOctreeNode(octree, node->children[i]);
        }
    }


}

void GLWidget::paintFace(Face *f){

    if(this->scene->wireFrame){
        glBegin(GL_LINES);
            glVertex3f(f->P1->x,f->P1->y,f->P1->z);
            glVertex3f(f->P2->x,f->P2->y,f->P2->z);
            glVertex3f(f->P3->x,f->P3->y,f->P3->z);
        glEnd();

    }else{
        glBegin(GL_POLYGON);
            glVertex3f(f->P1->x,f->P1->y,f->P1->z);
            glVertex3f(f->P2->x,f->P2->y,f->P2->z);
            glVertex3f(f->P3->x,f->P3->y,f->P3->z);
        glEnd();

    }


}
void GLWidget::paintMesh(Mesh *M){

    float m[16] = {1,0,0,0,
                   0,1,0,0,
                   0,0,1,0,
                   0,0,0,1};

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);
    glColor3f(M->color->R,M->color->G,M->color->B);
    M->getToWordMatrix(m);
    glMultMatrixf(m);

    for(vector<Face*>::iterator i=M->faces.begin(); i!= M->faces.end();i++){
        paintFace(*i);
    }
}
void GLWidget::paintMeshes(){
    for(vector<Mesh*>::iterator i = this->scene->meshes.begin(); i!= this->scene->meshes.end();i++)
        paintMesh(*i);

}

vector<Mesh*> GLWidget::ReadMeshes (std::string filepath){


    ifstream readFile(filepath);
    string identifier, x, y, z, name, line;

    vector<Mesh*> meshes;

    int sub_conj = -1;

    while(getline(readFile, line)){
        stringstream iss(line);
        getline(iss, identifier, ' ');

        if(identifier == "o"){
            getline(iss, name, ' ');
            Mesh* M = new Mesh(QString::fromStdString(name));
            meshes.push_back(M);
            sub_conj++;
        }

        if(identifier == "v"){

            getline(iss, x, ' ');
            getline(iss, y, ' ');
            getline(iss, z, ' ');

            meshes.at(sub_conj)->addPoint(QString::fromStdString(x).toFloat(), QString::fromStdString(y).toFloat(), QString::fromStdString(z).toFloat());

        }
        if(identifier == "f"){
            getline(iss, x, ' ');
            getline(iss, y, ' ');
            getline(iss, z, ' ');
            meshes.at(sub_conj)->addFace(stof(x)-1,stof(z)-1,stof(y)-1);

        }
    }

    return meshes;
//    std::ifstream readFile();


//    std::string identifier, x, y, z,alfa, line;

//    std::vector<Mesh*> Objetos;

//       int sub_conj = -1;

//       while(std::getline(readFile, line)){
//           std::stringstream iss(line);
//           std::getline(iss, identifier, ' ');

//           if(identifier == "o"){
//               Mesh* O = new Mesh();
//               Objetos.push_back(O);
//               sub_conj++;
//           }

//           if(identifier == "v"){
//               std::getline(iss, x, ' ');
//               std::getline(iss, y, ' ');
//               std::getline(iss, z, ' ');
//               Objetos.at(sub_conj)->addPoint(stof(x),stof(y),stof(z));

//           }
////           if(identifier == "f"){
////               getline(iss, x, ' ');
////               getline(iss, y, ' ');
////               getline(iss, z, ' ');
////               Objetos.at(sub_conj)->addFace(stof(x),stof(y),stof(z));

////           }
//       }

//       return Objetos;
}

void GLWidget::Eye_X(double x){
    Ex=(float)x;
}
void GLWidget::Eye_Y(double x){
    Ey=(float)x;
}
void GLWidget::Eye_Z(double x){
    Ez=(float)x;
}
void GLWidget::Lo_X(double x){
    Lox=(float)x;
}
void GLWidget::Lo_Y(double x){
    Loy=(float)x;
}
void GLWidget::Lo_Z(double x){
    Loz=(float)x;
}
void GLWidget::Av_X(double x){
    Avx=(float)x;
}
void GLWidget::Av_Y(double x){
    Avy=(float)x;
}
void GLWidget::Av_Z(double x){
    Avz=(float)x;
}

