#ifndef ADDCUBE_H
#define ADDCUBE_H

#include <QDialog>
#include "scene.h"

namespace Ui {
class AddCube;
}

class AddCube : public QDialog
{
    Q_OBJECT

public:
    explicit AddCube(QWidget *parent = 0);
    ~AddCube();
    float cX=0, cY=0, cZ=0, size=1;
    float r=0.5, g=0.5, b=0.5;
    Scene *scene_ref;
    void setScene(Scene *S);


private slots:


    void on_size_valueChanged(double arg1);

    void on_addCube_clicked();

    void on_R_valueChanged(double arg1);

    void on_G_valueChanged(double arg1);

    void on_B_valueChanged(double arg1);

private:
    Ui::AddCube *ui;
};

#endif // ADDCUBE_H
