#include "addcone.h"
#include "ui_addcone.h"

AddCone::AddCone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCone)
{
    ui->setupUi(this);
}

AddCone::~AddCone()
{
    delete ui;
}


void AddCone::setScene(Scene *S){
    this->scene_ref=S;
}
void AddCone::on_addCone_clicked()
{
    this->scene_ref->addPrimitive(this->ui->id_input->text(),2,0,0,0,0,0, this->base, this->height, this->slices, this->stacks, this->r, this->g, this->b);
    this->close();
}



void AddCone::on_base_valueChanged(double arg1)
{
    this->base=arg1;
}
void AddCone::on_height_valueChanged(double arg1)
{
    this->height=arg1;
}
void AddCone::on_stacks_valueChanged(double arg1)
{
    this->stacks = arg1;
}

void AddCone::on_slices_valueChanged(double arg1)
{
    this->slices=arg1;
}


void AddCone::on_R_valueChanged(double arg1)
{
    this->r=arg1;
}

void AddCone::on_G_valueChanged(double arg1)
{
    this->g=arg1;
}

void AddCone::on_B_valueChanged(double arg1)
{
    this->b=arg1;
}
