#include "addbox.h"
#include "ui_addbox.h"

AddBox::AddBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBox)
{
    ui->setupUi(this);
}

AddBox::~AddBox()
{
    delete ui;
}

void AddBox::on_sizeX_valueChanged(double arg1)
{
    this->sizeX=arg1;
}
void AddBox::on_sizeY_valueChanged(double arg1)
{
    this->sizeY=arg1;
}
void AddBox::on_sizeZ_valueChanged(double arg1)
{
    this->sizeZ=arg1;
}

void AddBox::on_addBox_clicked()
{
    this->scene_ref->addPrimitive( this->ui->id_input->text(),4,0.0, this->sizeX, this->sizeY, this->sizeZ,0,0,0,0,0, this->r, this->g, this->b);
    this->close();
}

void AddBox::setScene(Scene *S){
    this->scene_ref=S;
}

void AddBox::on_R_valueChanged(double arg1)
{
    this->r=arg1;
}

void AddBox::on_G_valueChanged(double arg1)
{
    this->g=arg1;
}

void AddBox::on_B_valueChanged(double arg1)
{
    this->b=arg1;
}
