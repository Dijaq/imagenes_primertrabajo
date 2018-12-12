#include "general.h"
#include "ui_general.h"

General::General(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::General)
{
    ui->setupUi(this);
}

General::~General()
{
    delete ui;
}

void General::on_btn_procesamiento_imagenes_clicked()
{
    EditorImagenes *w = new EditorImagenes;
    w->show();
}

void General::on_pushButton_2_clicked()
{
    editorvideo *v = new editorvideo;
    v->show();
}
