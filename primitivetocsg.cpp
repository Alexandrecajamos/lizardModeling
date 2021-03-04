#include "primitivetocsg.h"
#include "ui_primitivetocsg.h"

PrimitiveToCSG::PrimitiveToCSG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrimitiveToCSG)
{
    ui->setupUi(this);
}

PrimitiveToCSG::~PrimitiveToCSG()
{
    delete ui;
}

void PrimitiveToCSG::setScene(Scene *S){
    this->scene_ref=S;
}

void PrimitiveToCSG::on_pushButton_clicked()
{
    if(this->scene_ref->primitiveToCSG(this->ui->id_input_csg->text(), this->ui->id_input_p->text(),this->ui->comboBox->currentIndex())){
        this->close();
    }else
        this->ui->error->setText(QString("Error!"));
}
