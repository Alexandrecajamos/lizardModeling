#ifndef OCTREEVIEWOPTIONS_H
#define OCTREEVIEWOPTIONS_H

#include <QDialog>
#include "scene.h"
#include "octree.h"
namespace Ui {
class OctreeViewOptions;
}

class OctreeViewOptions : public QDialog
{
    Q_OBJECT

public:
    explicit OctreeViewOptions(QWidget *parent = 0);
    ~OctreeViewOptions();
    Scene *scene_ref;
    Octree *octree = NULL;

    void setScene(Scene *S);

private slots:
    void on_pushButton_clicked();

    void on_OutNodes_clicked(bool checked);
    void on_OnNodes_clicked(bool checked);
    void on_InNodes_clicked(bool checked);

    void on_OutNodes_WF_clicked(bool checked);
    void on_OnNodes_WF_clicked(bool checked);
    void on_InNodes_WF_clicked(bool checked);

    void on_maxlvl_valueChanged(double arg1);

    void on_InNodes_2_clicked(bool checked);

    void on_maxlvl_2_valueChanged(double arg1);

    void on_In_R_valueChanged(double arg1);
    void on_In_G_valueChanged(double arg1);
    void on_In_B_valueChanged(double arg1);
    void on_On_R_valueChanged(double arg1);
    void on_On_G_valueChanged(double arg1);
    void on_On_B_valueChanged(double arg1);
    void on_Out_R_valueChanged(double arg1);
    void on_Out_G_valueChanged(double arg1);
    void on_Out_B_valueChanged(double arg1);

    void on_InNodes_3_clicked(bool checked);

private:
    Ui::OctreeViewOptions *ui;
};

#endif // OCTREEVIEWOPTIONS_H
