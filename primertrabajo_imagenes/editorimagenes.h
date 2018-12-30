#ifndef EDITORIMAGENES_H
#define EDITORIMAGENES_H

#include <QMainWindow>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "proyecto.hpp"

namespace Ui {
class EditorImagenes;
}

class EditorImagenes : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditorImagenes(QWidget *parent = 0);
    ~EditorImagenes();

private slots:
    void on_select_image_clicked();

    void on_btn_difuminado_aleatorio_clicked();

    void on_btn_transformacion_bilinela_clicked();

    void on_btn_sobel_clicked();

    void on_btn_filtro_mediana_clicked();

    void on_btn_ecualizacion_histograma_clicked();

    void on_btn_fft_clicked();

    void on_btn_rgbHSI_clicked();

private:
    Ui::EditorImagenes *ui;
};

#endif // EDITORIMAGENES_H
