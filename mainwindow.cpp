#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Eye_x_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Eye_X(double)));
    connect(ui->Eye_y_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Eye_Y(double)));
    connect(ui->Eye_z_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Eye_Z(double)));

    connect(ui->La_x_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Lo_X(double)));
    connect(ui->La_y_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Lo_Y(double)));
    connect(ui->La_z_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Lo_Z(double)));

    connect(ui->Av_x_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Av_X(double)));
    connect(ui->Av_y_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Av_Y(double)));
    connect(ui->Av_z_2,SIGNAL(valueChanged(double)), ui->GLwidget, SLOT(Av_Z(double)));
}

MainWindow::~MainWindow()
{
    delete ui;


}
void MainWindow::on_action_generateOctree_triggered(){
    octree = new Octrees(this);
    octree->setScene(ui->GLwidget->scene);
    octree->show();
}
void MainWindow::on_action_addCone_triggered(){
    addCone = new AddCone(this);
    addCone->setScene(ui->GLwidget->scene);
    addCone->show();
}
void MainWindow::on_action_addCube_triggered()
{
    addCube = new AddCube(this);
    addCube->setScene(ui->GLwidget->scene);
    addCube->show();

}
void MainWindow::on_action_addSphere_triggered()
{
    addSphere = new AddSphere(this);
    addSphere->setScene(ui->GLwidget->scene);
    addSphere->show();

}
void MainWindow::on_action_addBox_triggered()
{
    addBox = new AddBox(this);
    addBox->setScene(ui->GLwidget->scene);
    addBox->show();

}
void MainWindow::on_action_addCylinder_triggered(){
    AddCylinder = new addCylinder(this);
    AddCylinder->setScene(ui->GLwidget->scene);
    AddCylinder->show();
}

void MainWindow::on_action_removeObj_triggered(){
    removeObj = new removeObjects(this);
    removeObj->setScene(ui->GLwidget->scene);
    removeObj->show();
}

void MainWindow::on_action_transformObj_triggered(){
    transformObj = new TransformObj(this);
    transformObj->setScene(ui->GLwidget->scene);
    transformObj->show();
}

void MainWindow::on_action_OctreeViewOptions_triggered(){
    octreeViewOptions = new OctreeViewOptions(this);
    octreeViewOptions->setScene(ui->GLwidget->scene);
    octreeViewOptions->show();
}
void MainWindow::on_action_importMesh_triggered(){
    addMesh = new AddMesh(this);
    addMesh->setScene(ui->GLwidget->scene);
    addMesh->show();
}

void MainWindow::on_pushButtonSceneOptions_clicked()
{
    sceneOptions = new SceneOptions(this);
    sceneOptions->setScene(ui->GLwidget->scene);
    sceneOptions->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    rayCasting = new RayCasting(this);
    rayCasting->setScene(ui->GLwidget->scene);
    rayCasting->show();
}
