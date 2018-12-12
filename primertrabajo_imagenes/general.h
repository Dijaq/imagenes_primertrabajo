#ifndef GENERAL_H
#define GENERAL_H

#include <QDialog>
#include "editorimagenes.h"
#include "editorvideo.h"

namespace Ui {
class General;
}

class General : public QDialog
{
    Q_OBJECT

public:
    explicit General(QWidget *parent = 0);
    ~General();

private slots:
    void on_btn_procesamiento_imagenes_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::General *ui;
};

#endif // GENERAL_H
