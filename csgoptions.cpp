#include "csgoptions.h"
#include "ui_csgoptions.h"

CSGOptions::CSGOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSGOptions)
{
    ui->setupUi(this);
}

CSGOptions::~CSGOptions()
{
    delete ui;
}

void CSGOptions::setScene(Scene *S){
    this->scene_ref=S;
}

void CSGOptions::on_pushButton_clicked()
{
    //Aqui.

    this->ui->error->setText(QString(""));
    this->ui->Inf->setText("");

    if(this->scene_ref->getCSG(this->ui->id_input_name->text())){
        std::vector<Intersection*> I = this->scene_ref->Edge_intersept_CSG(this->ui->id_input_name->text(), this->ui->P0x->value(),this->ui->P0y->value(),this->ui->P0z->value(),this->ui->P1x->value(),this->ui->P1y->value(),this->ui->P1z->value(),this->ui->checkBox->isChecked());
        if(I.size()>0){
            string text = "";
            for(std::vector<Intersection*>::iterator i = I.begin(); i != I.end();i++){
    //            std::cout<<"\nTeste: " << (*i)->t;
                text += "\n(";
                text += to_string((*i)->t);
                text += ", ";
                text += (*i)->p->name.toStdString();
                text += ");";
            }
            QString QS = QString::fromStdString(text);

            this->ui->Inf->setText(QS);

        }else{
             this->ui->Inf->setText("No intersections.");
        }


    }else{
            this->ui->error->setText(QString("Error. Try Again."));

    }



}
