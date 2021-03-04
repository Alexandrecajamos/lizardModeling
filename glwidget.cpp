#include "glwidget.h"
#include "cube.h"
#include "face.h"
#include "edge.h"
#include "transformations.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{

    connect( &timer, SIGNAL(timeout()), this, SLOT(updateGL()) );
    timer.start(16);


    // Lizard:





//    this->scene->addPrimitive("b",2,0,0,0,0,0,1,3,10,10,0,1,0); // Rabo;
//    this->scene->RotateObj("b",0,180);






//    this->scene->addPrimitive("a",1,0,0,0,0,2,0,0,40,40,0.8,1,0.5);
//    this->scene->TranslateObj("a", 0,0,2);

//    this->scene->addPrimitive("b",1,0,0,0,0,3,0,0,40,40,0.8,0.5,0.5);


//    this->scene->createCSG("csg","a","b",2);





//    Point p(0,0,0);

//        std:: cout << "\nTeste: "<< this->scene->primitives.at(0)->PointClassify(&p) << ", " << this->scene->primitives.at(1)->PointClassify(&p);
//        this->scene->addPrimitive("b",2,0,0,0,0,0,2,3,10,10,0,1,0);

//        this->csg = new CSGnode(this->scene->primitives.at(0));
//        CSGnode *c1 = new CSGnode(this->scene->primitives.at(0));
//        CSGnode *c2 = new CSGnode(this->scene->primitives.at(1));

//        this->csg = new CSGnode(c1,c2,3);

//    for(int i=-5; i<6; i++)
//        this->points.push_back(Point(i,1,0));

}

void GLWidget::initializeGL()
{
    glClearColor(0.2, 0.2, 0.2, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

//    Point *n1 = new Point(0,1,1);

//    Intersection *i0 = new Intersection(1.0f, n1, 0);
//    Intersection *i1 = new Intersection(4.0f, n1, 0);
//    Intersection *i2 = new Intersection(7.0f, n1, 0);
//    Intersection *i3 = new Intersection(9.0f, n1, 0);

//    Intersection *i4 = new Intersection(3.0f, n1, 0);
//    Intersection *i5 = new Intersection(5.0f, n1, 0);
//    Intersection *i6 = new Intersection(7.0f, n1, 0);
//    Intersection *i7 = new Intersection(9.0f, n1, 0);

//    std::vector<Intersection*> LA;
//    std::vector<Intersection*> LB;

//    LA.push_back(i0);
//    LA.push_back(i1);
//    LA.push_back(i2);
//    LA.push_back(i3);




//    LB.push_back(i4);
//    LB.push_back(i5);

//    LB.push_back(i6);
//    LB.push_back(i7);

// std::vector<Intersection*> list = Merge(LA, LB, 1);

//    string s = "I(1,U(0,1))";

//    string s = "I(U(0,D(2,3)), D(4,U(3,0)))";


//    CSGnode *csg = this->scene->build_csg(s);

//    this->scene->csg_trees.push_back(csg);

//    std::cout << "\nTeste:" << csg->name.toStdString() << csg->getEquation().toStdString();




//    Point D(-0.505671, -0.560192, -0.656111);
//    Point Po(10,10,10);



//    Point D(0, 0, -1);

//    Point Po(0,0,10);

//    std::vector<Intersection*> list = this->scene->primitives.at(0)->Ray_intersept(Po, D);

//     std::vector<Intersection*> list = this->scene->csg_trees.at(0)->Ray_intersept(Po, D);

//     std::cout << "\nTeste Resultado:";

//       for(std::vector<Intersection*>::iterator i = list.begin(); i != list.end(); i++){
//           std::cout << "\nTeste result: " << (*i)->t;
//       }

//    float t0 = -1, t1=-1;
//    this->scene->primitives.at(0)->Ray_intersept(Po, D, t0, t1);



//    std::cout << "\nTeste1: " << t0 << ", " << t1;

//    std::cout << "\nTeste: " << T0->t;

//   std::vector<Intersection*> list = Merge(LA, LB, 1);

//   for(std::vector<Intersection*>::iterator i = list.begin(); i != list.end(); i++){
//       std::cout << "\nTeste result: " << (*i)->t;
//   }

//    GLfloat luzAmbiente[4]={0.1,0.1,0.1,1.0};
//    GLfloat luzDifusa[4]={1,1,1,1};
//    GLfloat luzEspecular[4]={0, 0, 0, 0.0};
//    GLfloat posicaoLuz[4]={-10.0, 50.0, -10.0, 0};
//    GLfloat especularidade[4]={0,0,0,1.0};
//    GLint especMaterial = 100;

//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//    // Habilita o modelo de colorização de Gouraud
//    glShadeModel(GL_SMOOTH);
//    // Define a refletância do material
//    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
//    // Define a concentração do brilho
//    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
//    // Ativa o uso da luz ambiente
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

//    // Define os parâmetros da luz de número 0
//    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
//    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
//    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

//    // Habilita a definição da cor do material a partir da cor corrente
//    //glEnable(GL_COLOR_MATERIAL);
//    //Habilita o uso de iluminação
//     glEnable(GL_LIGHTING);

//     glEnable(GL_LIGHT0);

//    // Habilita o depth-buffering  Opacidade dos objetos
//     glEnable(GL_DEPTH_TEST);



//    this->scene->addPrimitive(QString("Shpe"), 2, 1,1,1);

//    vector<Mesh*> Objs = this->ReadMeshes(this->Lizard_path);

//    for(vector<Mesh*>::iterator i = Objs.begin(); i!=Objs.end(); i++)
//        this->scene->addMesh(*i);





//    std::cout<< "\nTeste: " << c1->PointIntersect(&points.at(0));

//    this->scene->addPrimitive("Cube", 1, 0,0,0,0,2,0,0,10,10,1,0,0);



}
void GLWidget::paintGL()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);


//    glLoadIdentity();
//    gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);

//    if(this->scene->csg_trees.size()>0){
//            int bbox = 10;

//            glBegin(GL_LINE_STRIP);
//            for(int k=-bbox; k<=bbox; k++){
//                for(int j=-bbox; j<=bbox;j++){
//                    for(int i=-bbox; i<=bbox; i++){
//                        glLoadIdentity();
//                        gluLookAt(Ex,Ey,Ez,Lox,Loy,Loz,Avx,Avy,Avz);
//                        glColor3f(1.0f, 1.0f, 1.0f);
//                        p->x=i;
//                        p->y=j;
//                        p->z=k;
//                        if(this->scene->csg_trees.at(0)->PointIntersect(this->p)){
//                            glTranslated(i,j,k);
//                            glutSolidCube(1);
//                        }
//                    }

//                }
//            }

//            glEnd();
//    }


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

//        float M[4][4] = {{1,0,0,0},
//                         {0,1,0,0},
//                         {0,0,1,0},
//                         {0,0,0,1}};


        octree->getToWordMatrix(m);
        glMultMatrixf(m);

//        multiplyMatrix(octree->transformMatrix, node->cube->toWordMatrix, M);
//        float m[16] = {1,0,0,0,
//                       0,1,0,0,
//                       0,0,1,0,
//                       0,0,0,1};
//        for(int k=0; k<4;k++)
//            for(int l=0;l<4;l++){
//                m[k+l] = M[k][l];
//            }


//        node->cube->getToWordMatrix(m);
//        glMultMatrixf(m);

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
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Eye_Y(double x){
    Ey=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Eye_Z(double x){
    Ez=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Lo_X(double x){
    Lox=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Lo_Y(double x){
    Loy=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Lo_Z(double x){
    Loz=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Av_X(double x){
    Avx=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Av_Y(double x){
    Avy=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}
void GLWidget::Av_Z(double x){
    Avz=(float)x;
    this->scene->setObserver(this->Ex, this->Ey, this->Ez, this->Lox, this->Loy, this->Loz, this->Avx, this->Avy, this->Avz);
}


void GLWidget::LoadExemploSlide(){

    this->scene->csg_trees.clear();
    this->scene->primitives.clear();


    this->scene->addPrimitive("bl1",4,0,10,1,10,0,0,0,0,0,0,1,0); // bl1;
    this->scene->addPrimitive("bl2",4,0,10,9,1,0,0,0,0,0,0,0,1); // Bl2;
    this->scene->TranslateObj("bl1", 5,0.5,5);
    this->scene->TranslateObj("bl2", 5,5.5,0.5);

    this->scene->createCSG("un", "bl1", "bl2", 0);


    this->scene->addPrimitive("C",3,0,0,0,0,0,1,1,10,10,1,0,0); // Corpo - Cilindro;
    this->scene->addPrimitive("c",4,0,2,2,2,0,0,0,0,0,1,0,0); // Corpo - Box;

    this->scene->createCSG("Cy", "c", "C", 1);

    this->scene->TranslateObj("Cy", 5,0,5);
    this->scene->RotateObj("Cy",0, -90);


    this->scene->createCSG("csg","un", "Cy", 2);

}

void GLWidget::LoadClassicCSG(){

    this->scene->csg_trees.clear();
    this->scene->primitives.clear();


    this->scene->addPrimitive("A",0,3,0,0,0,0,0,0,0,0,1,0,0);
    this->scene->addPrimitive("B",1,0,0,0,0,2,0,0,10,10,0,0,1);

    this->scene->createCSG("AB", "A", "B", 1);


    this->scene->addPrimitive("C",3,0,0,0,0,0,1,1,10,10,0,1,0);
    this->scene->addPrimitive("c",4,0,2,2,3,0,0,0,0,0,0,1,0);

    this->scene->createCSG("C0", "c", "C", 1);
    this->scene->createCSG("C1", "c", "C", 1);
    this->scene->createCSG("C2", "c", "C", 1);

    this->scene->RotateObj("C1",0, -90);
    this->scene->RotateObj("C2",1, 90);

    this->scene->createCSG("aux", "C0", "C1", 0);

    this->scene->createCSG("Cs", "aux", "C2", 0);
    this->scene->removeCSG("aux");

    this->scene->createCSG("csg","AB", "Cs", 2);

}



void GLWidget::LoadLizard(){

    this->scene->csg_trees.clear();
    this->scene->primitives.clear();

        this->scene->addPrimitive("a",3,0,0,0,0,0,1,1,10,10,0,1,0); // Corpo - Cilindro;
        this->scene->addPrimitive("b",4,0,2,1,5,0,0,0,0,0,0,1,0); // Corpo - Box;

        this->scene->createCSG("corpo","a","b",1);

        this->scene->addPrimitive("c",1,0,0,0,0,1.5,0,0,10,10,0.5,1,0.5);
        this->scene->TranslateObj("c", 0,0,2.5);
        this->scene->ScaleObj("c", 0.75,0.75,1);

        this->scene->createCSG("cabeça", "2");

        this->scene->addPrimitive("d",1,0,0,0,0,1.5,0,0,10,10,0.5,1,0.5);
        this->scene->TranslateObj("d", 0,0,-2.5);
        this->scene->ScaleObj("d", 0.6,0.5,2.5);

        this->scene->createCSG("rabo", "3");

        this->scene->addPrimitive("e",4,0,0.5,2,0.5,0,0,0,0,0,0,1,0.5);
        this->scene->TranslateObj("e", 0.5,-1,-1.75);

        this->scene->addPrimitive("f",4,0,0.5,2,0.5,0,0,0,0,0,0,1,0.5);
        this->scene->TranslateObj("f",-0.5,-1,-1.75);


        this->scene->addPrimitive("g",4,0,0.5,2,0.5,0,0,0,0,0,0,1,0.5);
        this->scene->TranslateObj("g", 0.5,-1,1.75);

        this->scene->addPrimitive("h",4,0,0.5,2,0.5,0,0,0,0,0,0,1,0.5);
        this->scene->TranslateObj("h",-0.5,-1,1.75);


        this->scene->createCSG("pernasTrazeiras","e","f",0);
        this->scene->createCSG("pernasDianteiras","g","h",0);
        this->scene->createCSG("pernas","pernasDianteiras","pernasTrazeiras",0);


        this->scene->addPrimitive("i",1,0,0,0,0,1.5,0,0,10,10,0,1,0);
        this->scene->TranslateObj("i", 0,0.7,0);
        this->scene->ScaleObj("i", 0.25,0.5,0.25);

        this->scene->addPrimitive("j",1,0,0,0,0,1.5,0,0,10,10,0,1,0);
        this->scene->TranslateObj("j", 0,0.7,1.25);
        this->scene->ScaleObj("j", 0.25,0.5,0.25);


        this->scene->addPrimitive("k",1,0,0,0,0,1.5,0,0,10,10,0,1,0);
        this->scene->TranslateObj("k", 0,0.7,-1.25);
        this->scene->ScaleObj("k", 0.25,0.5,0.25);


        this->scene->createCSG("costas", "i", "j",  0);
        this->scene->createCSG("costas", "costas", "k",  0);
        this->scene->removeCSG("costas");

        this->scene->createCSG("Lizard", "cabeça", "corpo",  0);
        this->scene->createCSG("Lizard","Lizard", "pernas",0);
        this->scene->removeCSG("Lizard");
        this->scene->createCSG("Lizard","Lizard", "costas",0);
        this->scene->removeCSG("Lizard");
        this->scene->createCSG("Lizard","Lizard", "rabo",0);
        this->scene->removeCSG("Lizard");



}
