#ifndef ADDCONE_H
#define ADDCONE_H

#include <QDialog>
#include "scene.h"
namespace Ui {
class AddCone;
}

class AddCone : public QDialog
{
    Q_OBJECT

public:
    explicit AddCone(QWidget *parent = 0);
    ~AddCone();
    float base=1, height=1, slices=10, stacks=10;
    float r=0.5, g=0.5, b=0.5;
    Scene *scene_ref;
    void setScene(Scene *S);


private slots:
    void on_addCone_clicked();
    void on_base_valueChanged(double arg1);
    void on_height_valueChanged(double arg1);
    void on_slices_valueChanged(double arg1);
    void on_stacks_valueChanged(double arg1);

    void on_R_valueChanged(double arg1);
    void on_G_valueChanged(double arg1);
    void on_B_valueChanged(double arg1);

private:
    Ui::AddCone *ui;
};

#endif // ADDCONE_H
