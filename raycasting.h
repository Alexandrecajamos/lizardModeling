#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <QDialog>

#include <QMainWindow>

#include "QImage"
#include "camera.h"
#include "scene.h"
#include "colorrgb.h"

namespace Ui {
class RayCasting;
}

class RayCasting : public QDialog
{
    Q_OBJECT

public:
    explicit RayCasting(QWidget *parent = 0);
    ~RayCasting();

    int sizeX = 250;
    int sizeY = 250;
    float W = 0.5;
    float H = 0.5;
    float d = 1;

    Scene *scene_ref;
    void setScene(Scene *S);

private slots:
    void on_pushButton_clicked();

    void on_w_valueChanged(double arg1);

    void on_h_valueChanged(double arg1);

    void on_d_valueChanged(double arg1);

    void on_sizeX_valueChanged(double arg1);

    void on_sizeY_valueChanged(double arg1);


    void on_bgG_sliderMoved(int action);
    void on_bgB_sliderMoved(int action);

    void on_iaR_sliderMoved(int action);
    void on_iaG_sliderMoved(int action);
    void on_iaB_sliderMoved(int action);

    void on_bgR_sliderMoved(int position);

private:
    Ui::RayCasting *ui;
};

#endif // RAYCASTING_H
