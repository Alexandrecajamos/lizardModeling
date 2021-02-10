#include "octrees.h"
#include "ui_octrees.h"

Octrees::Octrees(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Octrees)
{
    ui->setupUi(this);
}

Octrees::~Octrees()
{
    delete ui;
}

void Octrees::on_maxlvl_valueChanged(double arg1)
{
    this->MaxLvl=arg1;
}


void Octrees::setScene(Scene *S){
    this->scene_ref=S;
}

void Octrees::on_generateButton_clicked()
{
    Primitive *P = this->scene_ref->getPrimitive(this->ui->id_input->text());
    if(P){
        Octree *octree = new Octree(this->ui->octree_name->text(),P, this->MaxLvl);
        octree->setMatrx(P->toWordMatrix);
        this->scene_ref->addOctree(octree);

        this->close();

    }else{

        Mesh *M = this->scene_ref->getMesh(this->ui->id_input->text());
        if(M){
            Octree *octree = new Octree(this->ui->octree_name->text(), M, this->MaxLvl);
            octree->setMatrx(M->toWordMatrix);
            this->scene_ref->addOctree(octree);

            this->close();
        }else{
            this->ui->error->setText(QString("Obj not found.\nPlease, try again."));
        }

    }
}
