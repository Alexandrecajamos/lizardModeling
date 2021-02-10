#ifndef ADDMESH_H
#define ADDMESH_H

#include <QDialog>
#include "scene.h"

namespace Ui {
class AddMesh;
}

class AddMesh : public QDialog
{
    Q_OBJECT

public:
    explicit AddMesh(QWidget *parent = 0);
    ~AddMesh();
    float r=0.5, g=0.5, b=0.5;
    Scene *scene_ref;

    std::string path = "/home/alexandre/Desktop/lizard.obj";

    void setScene(Scene *S);



private slots:


    void on_R_valueChanged(double arg1);

    void on_G_valueChanged(double arg1);

    void on_B_valueChanged(double arg1);


    void on_pasta_textChanged(const QString &arg1);

    void on_add_clicked();

private:
    Ui::AddMesh *ui;
};

#endif // ADDMESH_H
