#include "createcsg.h"
#include "ui_createcsg.h"

CreateCSG::CreateCSG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCSG)
{
    ui->setupUi(this);
}

CreateCSG::~CreateCSG()
{
    delete ui;
}

void CreateCSG::on_pushButton_clicked()
{
    QString error = "Error! Try again.";

    if(this->scene_ref->createCSG(this->ui->id_input_name->text(), this->ui->id_input_a->text(),this->ui->id_input_b->text(),  this->ui->comboBox->currentIndex())){
        this->close();
    }else{
        this->ui->error->setText(error);
    }
}

void CreateCSG::setScene(Scene *S){
    this->scene_ref=S;
    QString s = "0 .. N : Primitive id in scene. N=";
    s+=QString::number(S->primitives.size());
    this->ui->label_primitive->setText(s);
}

void CreateCSG::on_pushButton_2_clicked()
{

    QString error = "Error! Try again.";

    if(this->scene_ref->createCSG(this->ui->id_input_name->text(),this->ui->equation->text())){
        this->close();
    }else{
        this->ui->error->setText(error);
    }
}
