#include "removeobjects.h"
#include "ui_removeobjects.h"

removeObjects::removeObjects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeObjects)
{
    ui->setupUi(this);
}
removeObjects::~removeObjects()
{
    delete ui;
}
void removeObjects::on_pushButton_clicked()
{
    this->ui->result_label->setText(QString(""));
    QString find = "Objeto removido com sucesso!",
            no_find = "Objeto não encontrado;\nTente outro id.";

    QString id_input = this->ui->id_input->text();

    if(this->scene_ref->removePrimitive(id_input)||this->scene_ref->removeOctree(id_input)||this->scene_ref->removeMesh(id_input) || this->scene_ref->removeCSG(id_input)){
        this->ui->result_label->setText(find);
    }else{

        this->ui->result_label->setText(no_find);
    }
}

void removeObjects::setScene(Scene *S){
    this->scene_ref=S;
}
void removeObjects::on_pushButton_2_clicked()
{
    this->close();
}
