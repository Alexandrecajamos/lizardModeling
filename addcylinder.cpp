#include "addcylinder.h"
#include "ui_addcylinder.h"

addCylinder::addCylinder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCylinder)
{
    ui->setupUi(this);
}

addCylinder::~addCylinder()
{
    delete ui;
}
void addCylinder::setScene(Scene *S){
    this->scene_ref=S;
}
void addCylinder::on_addCylinder_2_clicked()
{
    this->scene_ref->addPrimitive(this->ui->id_input->text(),3,0,0,0,0,0, this->base, this->height, this->slices, this->stacks, this->r, this->g, this->b);
    this->close();

}
void addCylinder::on_base_valueChanged(double arg1)
{
    this->base=arg1;
}
void addCylinder::on_height_valueChanged(double arg1)
{
    this->height=arg1;
}
void addCylinder::on_stacks_valueChanged(double arg1)
{
    this->stacks = arg1;
}
void addCylinder::on_slices_valueChanged(double arg1)
{
    this->slices=arg1;
}
void addCylinder::on_R_valueChanged(double arg1)
{
    this->r=arg1;
}
void addCylinder::on_G_valueChanged(double arg1)
{
    this->g=arg1;
}
void addCylinder::on_B_valueChanged(double arg1)
{
    this->b=arg1;
}
