#ifndef CSGOPTIONS_H
#define CSGOPTIONS_H

#include <QDialog>
#include "scene.h"


namespace Ui {
class CSGOptions;
}

class CSGOptions : public QDialog
{
    Q_OBJECT

public:
    explicit CSGOptions(QWidget *parent = 0);
    ~CSGOptions();
    Scene *scene_ref;
    void setScene(Scene *S);

private slots:
    void on_pushButton_clicked();

private:
    Ui::CSGOptions *ui;
};

#endif // CSGOPTIONS_H
