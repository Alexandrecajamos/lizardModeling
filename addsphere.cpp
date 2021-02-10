#include "addsphere.h"
#include "ui_addsphere.h"

AddSphere::AddSphere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSphere)
{
    ui->setupUi(this);
}

AddSphere::~AddSphere()
{
    delete ui;
}

void AddSphere::setScene(Scene *S){
    this->scene_ref=S;
}
void AddSphere::on_pushButton_clicked()
{
    float size = this->radius*2;
    this->scene_ref->addPrimitive(this->ui->id_input->text(),1,size,size,size,size, this->radius,this->radius,this->radius, this->slices, this->stacks, this->r, this->g, this->b);
    this->close();
}

void AddSphere::on_radius_valueChanged(double arg1)
{
    this->radius=arg1;
}
void AddSphere::on_R_valueChanged(double arg1)
{
    this->r=arg1;
}
void AddSphere::on_G_valueChanged(double arg1)
{
    this->g=arg1;
}
void AddSphere::on_B_valueChanged(double arg1)
{
    this->b=arg1;
}
void AddSphere::on_stacks_valueChanged(double arg1)
{
    this->stacks = arg1;
}

void AddSphere::on_slices_valueChanged(double arg1)
{
    this->slices=arg1;
}
