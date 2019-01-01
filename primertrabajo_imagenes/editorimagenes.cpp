#include "editorimagenes.h"
#include "ui_editorimagenes.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;

String name;

EditorImagenes::EditorImagenes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorImagenes)
{
    ui->setupUi(this);
}

EditorImagenes::~EditorImagenes()
{
    delete ui;
}

void EditorImagenes::on_select_image_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    name = filename.toStdString();

    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    //QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    cvtColor(inputImage, inputImage, CV_BGR2RGB);
    //QImage image((uchar*)inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);
    QImage image((uchar*)inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);
    image = image.scaledToWidth(ui->input_image->width(), Qt::SmoothTransformation);
    ui->input_image->setPixmap(QPixmap::fromImage(image));
    /*
    if(QString::compare(filename, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(filename);

        if(valid)
        {
            image = image.scaledToWidth(ui->input_image->width(), Qt::SmoothTransformation);
            ui->input_image->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //Error handling
        }
    }*/
}


/**@autor  : Diego Javier
 * Tema4: DifuminadoAleatorio
**/
void EditorImagenes::on_btn_difuminado_aleatorio_clicked()
{
    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    Mat result = _difuminadoAleatorio(inputImage,40);

    QImage image((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_RGB888);
    image = image.scaledToWidth(ui->output_image->width(), Qt::SmoothTransformation);
    ui->output_image->setPixmap(QPixmap::fromImage(image));

}

/**@autor  : Diego Javier
 * Tema4: Transformacion Bilineal
**/
void EditorImagenes::on_btn_transformacion_bilinela_clicked()
{
    Point point1;
    point1.x = 50;
    point1.y = 0;
    Point point2;
    point2.x = 400;
    point2.y = 40;
    Point point3;
    point3.x = 200;
    point3.y = 400;
    Point point4;
    point4.x = 20;
    point4.y = 190;

    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    point2.x = inputImage.rows*3/4;
    point3.x = inputImage.cols/3;
    point3.y = inputImage.cols*2/3;
    point4.y = inputImage.cols/3;

    Mat result = _transformacionBilineal(inputImage, point1,point2, point3, point4);

    QImage image((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_Grayscale8);
    image = image.scaledToWidth(ui->output_image->width(), Qt::SmoothTransformation);
    ui->output_image->setPixmap(QPixmap::fromImage(image));
}

/**@autor  : Diego Javier
 * Tema3: Sobel para deteccion de bordes
**/
void EditorImagenes::on_btn_sobel_clicked()
{
    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    Mat result = _sobel(inputImage);
    //Mat result = inputImage.clone();

    QImage image((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_Grayscale8);
    image = image.scaledToWidth(ui->output_image->width(), Qt::SmoothTransformation);
    ui->output_image->setPixmap(QPixmap::fromImage(image));
}

void EditorImagenes::on_btn_filtro_mediana_clicked()
{
    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    Mat result = _medianBlur(inputImage, 20);

    QImage image((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_RGB888);
    image = image.scaledToWidth(ui->output_image->width(), Qt::SmoothTransformation);
    ui->output_image->setPixmap(QPixmap::fromImage(image));

}

void EditorImagenes::on_btn_ecualizacion_histograma_clicked()
{
    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    Mat result = _ecualizacionHistograma_gray(inputImage);

    QImage image((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_Grayscale8);
    image = image.scaledToWidth(ui->output_image->width(), Qt::SmoothTransformation);
    ui->output_image->setPixmap(QPixmap::fromImage(image));

}

void EditorImagenes::on_btn_fft_clicked()
{
    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    Mat result = opencv_fft(inputImage);

    QImage image((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_Grayscale8);
    image = image.scaledToWidth(ui->output_image->width(), Qt::SmoothTransformation);
    ui->output_image->setPixmap(QPixmap::fromImage(image));
}

void EditorImagenes::on_btn_rgbHSI_clicked()
{
    Mat inputImage = imread(name, CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    Mat result = _rgbtoHSI(inputImage);

    QImage image((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_RGB888);
    image = image.scaledToWidth(ui->output_image->width(), Qt::SmoothTransformation);
    ui->output_image->setPixmap(QPixmap::fromImage(image));
}
