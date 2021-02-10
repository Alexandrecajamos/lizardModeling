#include "addcube.h"
#include "ui_addcube.h"

AddCube::AddCube(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCube)
{
    ui->setupUi(this);
}

AddCube::~AddCube()
{
    delete ui;
}




void AddCube::on_size_valueChanged(double arg1)
{
    this->size=arg1;
}

void AddCube::on_addCube_clicked()
{

    this->scene_ref->addPrimitive(this->ui->id_input->text(),0,  this->size,this->size,this->size,this->size, this->size, this->size, this->size, 0,0, this->r, this->g, this->b);
    this->close();
}

void AddCube::setScene(Scene *S){
    this->scene_ref=S;
}

void AddCube::on_R_valueChanged(double arg1)
{
    this->r=arg1;
}

void AddCube::on_G_valueChanged(double arg1)
{
    this->g=arg1;
}

void AddCube::on_B_valueChanged(double arg1)
{
    this->b=arg1;
}
