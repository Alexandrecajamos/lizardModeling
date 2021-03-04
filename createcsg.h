#ifndef CREATECSG_H
#define CREATECSG_H

#include <QDialog>
#include "scene.h"

namespace Ui {
class CreateCSG;
}

class CreateCSG : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCSG(QWidget *parent = 0);
    ~CreateCSG();

    Scene *scene_ref;

    void setScene(Scene *S);


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateCSG *ui;
};

#endif // CREATECSG_H
