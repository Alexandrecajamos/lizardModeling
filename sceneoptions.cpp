#include "sceneoptions.h"
#include "ui_sceneoptions.h"

SceneOptions::SceneOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SceneOptions)
{
    ui->setupUi(this);
}

SceneOptions::~SceneOptions()
{
    delete ui;
}

void SceneOptions::setScene(Scene *S){
    this->scene_ref=S;
    this->ui->primitives->setChecked(S->rendPrimitives);
    this->ui->meshes->setChecked(S->rendMeshes);
    this->ui->octrees->setChecked(S->rendOctrees);
    this->ui->wireframe->setChecked(S->wireFrame);

}
void SceneOptions::on_primitives_clicked(bool checked)
{
    this->scene_ref->rendPrimitives=checked;
}

void SceneOptions::on_meshes_clicked(bool checked)
{
    this->scene_ref->rendMeshes=checked;
}

void SceneOptions::on_octrees_clicked(bool checked)
{
    this->scene_ref->rendOctrees=checked;
}

void SceneOptions::on_wireframe_clicked(bool checked)
{
    this->scene_ref->wireFrame = checked;
}

void SceneOptions::on_informations_clicked()
{
    QString QS = QString::fromStdString(this->scene_ref->SceneInformations());

    this->ui->Inf->setText(QS);


}


void SceneOptions::on_informations_2_clicked()
{

    if(this->scene_ref->rendOctrees)
        this->scene_ref->octrees.clear();
    if(this->scene_ref->rendPrimitives)
        this->scene_ref->primitives.clear();
    if(this->scene_ref->rendMeshes)
        this->scene_ref->meshes.clear();

    this->scene_ref->csg_trees.clear();

}
