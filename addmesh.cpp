#include "addmesh.h"
#include "ui_addmesh.h"

AddMesh::AddMesh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMesh)
{
    ui->setupUi(this);
}

AddMesh::~AddMesh()
{
    delete ui;
}

void AddMesh::setScene(Scene *S){
    this->scene_ref=S;
}

void AddMesh::on_R_valueChanged(double arg1)
{
    this->r=arg1;
}

void AddMesh::on_G_valueChanged(double arg1)
{
    this->g=arg1;
}

void AddMesh::on_B_valueChanged(double arg1)
{
    this->b=arg1;
}

void AddMesh::on_pasta_textChanged(const QString &arg1)
{
    this->path=arg1.toStdString();
}

void AddMesh::on_add_clicked()
{
    float size = scene_ref->meshes.size();

    this->scene_ref->addMeshes(this->path);

    if(size < scene_ref->meshes.size())
        this->close();
    else
         this->ui->error->setText(QString("File not found.\nPlease, try again."));
}
