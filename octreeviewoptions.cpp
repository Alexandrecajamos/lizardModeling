#include "octreeviewoptions.h"
#include "ui_octreeviewoptions.h"

OctreeViewOptions::OctreeViewOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OctreeViewOptions)
{
    ui->setupUi(this);
}

OctreeViewOptions::~OctreeViewOptions()
{
    delete ui;
}

void OctreeViewOptions::setScene(Scene *S){
    this->scene_ref=S;
}

void OctreeViewOptions::on_pushButton_clicked()
{
    this->ui->label->setText(QString(""));
    QString ok = "Octree Selected!",
            error = "Octree not found";

    this->octree = this->scene_ref->getOctree(this->ui->octree_name->text());
    if(this->octree != NULL){
        this->ui->label->setText(ok);
        this->ui->maxlvl->setValue(this->octree->rendLvlMax);

        this->ui->maxlvl->setMaximum(this->octree->LevelMax);
        this->ui->InNodes->setChecked(this->octree->rendIn);
        this->ui->InNodes_WF->setChecked(this->octree->WFIn);
        this->ui->OnNodes->setChecked(this->octree->rendOn);
        this->ui->OnNodes_WF->setChecked(this->octree->WFOn);
        this->ui->OutNodes->setChecked(this->octree->rendOut);
        this->ui->OutNodes_WF->setChecked(this->octree->WFOut);

        this->ui->InNodes_2->setChecked(this->octree->RenderNonLeafNodes);
        this->ui->InNodes_3->setChecked(this->octree->OnlyLeafatLevel);

        this->ui->maxlvl_2->setValue(this->octree->NonRenderRegion);


        this->ui->In_R->setValue(this->octree->In_Color->R);
        this->ui->In_G->setValue(this->octree->In_Color->G);
        this->ui->In_B->setValue(this->octree->In_Color->B);
        this->ui->On_R->setValue(this->octree->On_Color->R);
        this->ui->On_G->setValue(this->octree->On_Color->G);
        this->ui->On_B->setValue(this->octree->On_Color->B);
        this->ui->Out_R->setValue(this->octree->Out_Color->R);
        this->ui->Out_G->setValue(this->octree->Out_Color->G);
        this->ui->Out_B->setValue(this->octree->Out_Color->B);

    }else{
        this->ui->label->setText(error);
    }


}

void OctreeViewOptions::on_OutNodes_clicked(bool checked)
{
    if(this->octree != NULL)
        this->octree->setRendOut(checked);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_OnNodes_clicked(bool checked)
{
    if(this->octree != NULL)
        this->octree->setRendOn(checked);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_InNodes_clicked(bool checked)
{
    if(this->octree != NULL)
        this->octree->setRendIn(checked);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}

void OctreeViewOptions::on_OutNodes_WF_clicked(bool checked)
{
    if(this->octree != NULL)
        this->octree->setWFOut(checked);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_OnNodes_WF_clicked(bool checked)
{
    if(this->octree != NULL)
        this->octree->setWFOn(checked);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_InNodes_WF_clicked(bool checked)
{
    if(this->octree != NULL)
        this->octree->setWFIn(checked);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}

void OctreeViewOptions::on_maxlvl_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setLevelMax(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}

void OctreeViewOptions::on_InNodes_2_clicked(bool checked)
{
    if(this->octree != NULL)
        this->octree->setRenderNonLeafNodes(checked);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}

void OctreeViewOptions::on_maxlvl_2_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setNonRenderRegion(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_In_R_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setIn_Color_R(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_In_G_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setIn_Color_G(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}

void OctreeViewOptions::on_In_B_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setIn_Color_B(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_On_R_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setOn_Color_R(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_On_G_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setOn_Color_G(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}

void OctreeViewOptions::on_On_B_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setOn_Color_B(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}



void OctreeViewOptions::on_Out_R_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setOut_Color_R(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}
void OctreeViewOptions::on_Out_G_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setOut_Color_G(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}

void OctreeViewOptions::on_Out_B_valueChanged(double arg1)
{
    if(this->octree != NULL)
        this->octree->setOut_Color_B(arg1);
    else{
        this->ui->label->setText(QString("First, select the octree."));
    }
}


void OctreeViewOptions::on_InNodes_3_clicked(bool checked)
{
    if(this->octree !=NULL)
        this->octree->setOnlyleafatLevel(checked);
    else
        this->ui->label->setText(QString("First, select the octree."));
}
