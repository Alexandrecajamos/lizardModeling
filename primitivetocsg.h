#ifndef PRIMITIVETOCSG_H
#define PRIMITIVETOCSG_H

#include <QDialog>
#include "scene.h"

namespace Ui {
class PrimitiveToCSG;
}

class PrimitiveToCSG : public QDialog
{
    Q_OBJECT

public:
    explicit PrimitiveToCSG(QWidget *parent = 0);
    ~PrimitiveToCSG();

    Scene *scene_ref;

    void setScene(Scene *S);

private slots:
    void on_pushButton_clicked();

private:
    Ui::PrimitiveToCSG *ui;
};

#endif // PRIMITIVETOCSG_H
