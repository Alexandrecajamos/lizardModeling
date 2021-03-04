#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "addcube.h"
#include "addsphere.h"
#include "addbox.h"
#include "addcone.h"
#include "addcylinder.h"
#include "removeobjects.h"
#include "transformobj.h"
#include "octrees.h"
#include "octreeviewoptions.h"
#include "addmesh.h"
#include "sceneoptions.h"
#include "raycasting.h"

#include "createcsg.h"
#include "primitivetocsg.h"

#include "csgoptions.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_action_addCube_triggered();
    void on_action_addSphere_triggered();
    void on_action_addCone_triggered();
    void on_action_addBox_triggered();
    void on_action_addCylinder_triggered();
    void on_action_removeObj_triggered();
    void on_action_transformObj_triggered();
    void on_action_generateOctree_triggered();
    void on_action_OctreeViewOptions_triggered();

    void on_action_importMesh_triggered();


    void on_pushButtonSceneOptions_clicked();

    void on_pushButton_2_clicked();


    void on_action_createCSG_triggered();
    void on_action_primitiveCSG_triggered();
    void on_action_viewCSG_triggered();

    void on_action_loadLizard_triggered();
    void on_action_loadExpB_triggered();
    void on_action_loadClassic_triggered();




private:
    Ui::MainWindow *ui;
    AddCube *addCube;
    AddSphere *addSphere;
    AddCone *addCone;
    AddBox *addBox;
    addCylinder *AddCylinder;
    removeObjects *removeObj;
    TransformObj *transformObj;
    Octrees *octree;
    OctreeViewOptions *octreeViewOptions;
    AddMesh *addMesh;

    SceneOptions *sceneOptions;

    RayCasting *rayCasting;
    CreateCSG *createCSG;
    PrimitiveToCSG *primitiveToCSG;

    CSGOptions *csgOptions;

};

#endif // MAINWINDOW_H
