#ifndef ADDSPHERE_H
#define ADDSPHERE_H

#include <QDialog>
#include "scene.h"
namespace Ui {
class AddSphere;
}

class AddSphere : public QDialog
{
    Q_OBJECT

public:
    explicit AddSphere(QWidget *parent = 0);
    ~AddSphere();
    float radius=1;
    int slices = 10, stacks=10;
    float r=0.5, g=0.5, b=0.5;
    Scene *scene_ref;
    void setScene(Scene *S);

private slots:
    void on_pushButton_clicked();

    void on_radius_valueChanged(double arg1);
    void on_R_valueChanged(double arg1);
    void on_G_valueChanged(double arg1);
    void on_B_valueChanged(double arg1);

    void on_stacks_valueChanged(double arg1);

    void on_slices_valueChanged(double arg1);

private:
    Ui::AddSphere *ui;
};

#endif // ADDSPHERE_H
