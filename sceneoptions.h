#ifndef SCENEOPTIONS_H
#define SCENEOPTIONS_H

#include <QDialog>
#include "scene.h"

namespace Ui {
class SceneOptions;
}

class SceneOptions : public QDialog
{
    Q_OBJECT

public:
    explicit SceneOptions(QWidget *parent = 0);
    ~SceneOptions();
    Scene *scene_ref;
    void setScene(Scene *S);

private slots:
    void on_primitives_clicked(bool checked);

    void on_meshes_clicked(bool checked);

    void on_octrees_clicked(bool checked);

    void on_wireframe_clicked(bool checked);

    void on_informations_clicked();

private:
    Ui::SceneOptions *ui;
};

#endif // SCENEOPTIONS_H
