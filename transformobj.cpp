#include "transformobj.h"
#include "ui_transformobj.h"

TransformObj::TransformObj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransformObj)
{
    ui->setupUi(this);
}

TransformObj::~TransformObj()
{
    delete ui;
}
void TransformObj::on_pushButton_4_clicked()
{
    this->close();
}
void TransformObj::setScene(Scene *S){
    this->scene_ref=S;
}
void TransformObj::on_translate_clicked(){
    this->ui->result_label->setText(QString(""));
    QString ok = "Operação realizada com sucesso!",
            error = "Objeto não encontrado;\nTente outro id.";

    QString id_input = this->ui->id_input->text();

    if(this->scene_ref->TranslateObj(id_input, this->tX, this->tY, this->tZ))
        this->ui->result_label->setText(ok);
    else
        this->ui->result_label->setText(error);

}

void TransformObj::on_scale_clicked()
{
    this->ui->result_label->setText(QString(""));
    QString ok = "Operação realizada com sucesso!",
            error = "Objeto não encontrado;\nTente outro id.";

    QString id_input = this->ui->id_input->text();

    if(this->scene_ref->ScaleObj(id_input, this->eX, this->eY, this->eZ))
        this->ui->result_label->setText(ok);
    else
        this->ui->result_label->setText(error);


}
void TransformObj::on_rotate_clicked()
{
    this->ui->result_label->setText(QString(""));
    QString ok = "Operação realizada com sucesso!",
            error = "Objeto não encontrado;\nTente outro id.";

    QString id_input = this->ui->id_input->text();
    if(this->scene_ref->RotateObj(id_input, this->rAng, this->rEixo))
        this->ui->result_label->setText(ok);
    else
       this->ui->result_label->setText(error);

}
void TransformObj::on_clean_clicked()
{
    this->ui->result_label->setText(QString(""));
    QString ok = "Operação realizada com sucesso!",
            error = "Objeto não encontrado;\nTente outro id.";

    QString id_input = this->ui->id_input->text();

    if(this->scene_ref->CleanObj(id_input))
        this->ui->result_label->setText(ok);
    else
        this->ui->result_label->setText(error);
}


void TransformObj::on_tX_valueChanged(double arg1)
{
    this->tX =arg1;
}
void TransformObj::on_tY_valueChanged(double arg1)
{
    this->tY =arg1;
}
void TransformObj::on_tZ_valueChanged(double arg1)
{
    this->tZ =arg1;
}
void TransformObj::on_eX_valueChanged(double arg1)
{
    this->eX =arg1;
}
void TransformObj::on_eY_valueChanged(double arg1)
{
    this->eY =arg1;
}
void TransformObj::on_eZ_valueChanged(double arg1)
{
    this->eZ =arg1;
}
void TransformObj::on_ang_valueChanged(double arg1)
{
    this->rAng = arg1;
}
void TransformObj::on_eixo_valueChanged(double arg1)
{
    this->rEixo = arg1;
}

