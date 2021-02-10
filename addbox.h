#ifndef ADDBOX_H
#define ADDBOX_H

#include <QDialog>

#include "scene.h"
namespace Ui {
class AddBox;
}

class AddBox : public QDialog
{
    Q_OBJECT

public:
    explicit AddBox(QWidget *parent = 0);
    ~AddBox();
    float cX=0, cY=0, cZ=0, sizeX=1, sizeY=1, sizeZ=1;
    float r=0.5, g=0.5, b=0.5;
    Scene *scene_ref;
    void setScene(Scene *S);


private slots:


    void on_sizeX_valueChanged(double arg1);
    void on_sizeY_valueChanged(double arg1);
    void on_sizeZ_valueChanged(double arg1);
    void on_addBox_clicked();
    void on_R_valueChanged(double arg1);
    void on_G_valueChanged(double arg1);
    void on_B_valueChanged(double arg1);
private:
    Ui::AddBox *ui;
};

#endif // ADDBOX_H
