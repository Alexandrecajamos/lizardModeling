#ifndef OCTREES_H
#define OCTREES_H

#include <QDialog>
#include "scene.h"
#include "octree.h"

namespace Ui {
class Octrees;
}

class Octrees : public QDialog
{
    Q_OBJECT

public:
    explicit Octrees(QWidget *parent = 0);
    ~Octrees();

    Scene *scene_ref;
    void setScene(Scene *S);

    int MaxLvl = 1;

private slots:
    void on_maxlvl_valueChanged(double arg1);

    void on_generateButton_clicked();

private:
    Ui::Octrees *ui;
};

#endif // OCTREES_H
