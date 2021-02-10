#ifndef TRANSFORMOBJ_H
#define TRANSFORMOBJ_H

#include <QDialog>
#include "scene.h"
namespace Ui {
class TransformObj;
}

class TransformObj : public QDialog
{
    Q_OBJECT

public:
    explicit TransformObj(QWidget *parent = 0);
    ~TransformObj();

    Scene *scene_ref;
    void setScene(Scene *S);
    float tX=0, tY=0, tZ=0, eX=1, eY=1, eZ=1, rAng=0;
    int rEixo=0;

private slots:
    void on_pushButton_4_clicked();
    void on_translate_clicked();
    void on_scale_clicked();
    void on_rotate_clicked();
    void on_clean_clicked();

    void on_tX_valueChanged(double arg1);
    void on_tY_valueChanged(double arg1);
    void on_tZ_valueChanged(double arg1);

    void on_eX_valueChanged(double arg1);
    void on_eY_valueChanged(double arg1);
    void on_eZ_valueChanged(double arg1);

    void on_ang_valueChanged(double arg1);
    void on_eixo_valueChanged(double arg1);



private:
    Ui::TransformObj *ui;
};

#endif // TRANSFORMOBJ_H
