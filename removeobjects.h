#ifndef REMOVEOBJECTS_H
#define REMOVEOBJECTS_H

#include <QDialog>
#include "scene.h"

namespace Ui {
class removeObjects;
}

class removeObjects : public QDialog
{
    Q_OBJECT

public:
    explicit removeObjects(QWidget *parent = 0);
    ~removeObjects();

    Scene *scene_ref;
    void setScene(Scene *S);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::removeObjects *ui;
};

#endif // REMOVEOBJECTS_H
