/********************************************************************************
** Form generated from reading UI file 'editorimagenes.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORIMAGENES_H
#define UI_EDITORIMAGENES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditorImagenes
{
public:
    QWidget *centralWidget;
    QLabel *input_image;
    QPushButton *select_image;
    QLabel *output_image;
    QPushButton *btn_ecualizacion_histograma;
    QPushButton *btn_sobel;
    QPushButton *btn_filtro_mediana;
    QPushButton *btn_transformacion_bilinela;
    QPushButton *btn_difuminado_aleatorio;
    QPushButton *btn_fft;
    QPushButton *btn_rgbHSI;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EditorImagenes)
    {
        if (EditorImagenes->objectName().isEmpty())
            EditorImagenes->setObjectName(QStringLiteral("EditorImagenes"));
        EditorImagenes->resize(1471, 543);
        centralWidget = new QWidget(EditorImagenes);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        input_image = new QLabel(centralWidget);
        input_image->setObjectName(QStringLiteral("input_image"));
        input_image->setGeometry(QRect(200, 20, 441, 451));
        select_image = new QPushButton(centralWidget);
        select_image->setObjectName(QStringLiteral("select_image"));
        select_image->setGeometry(QRect(30, 20, 131, 51));
        output_image = new QLabel(centralWidget);
        output_image->setObjectName(QStringLiteral("output_image"));
        output_image->setGeometry(QRect(720, 20, 441, 451));
        btn_ecualizacion_histograma = new QPushButton(centralWidget);
        btn_ecualizacion_histograma->setObjectName(QStringLiteral("btn_ecualizacion_histograma"));
        btn_ecualizacion_histograma->setGeometry(QRect(30, 110, 151, 41));
        btn_sobel = new QPushButton(centralWidget);
        btn_sobel->setObjectName(QStringLiteral("btn_sobel"));
        btn_sobel->setGeometry(QRect(30, 210, 151, 41));
        btn_filtro_mediana = new QPushButton(centralWidget);
        btn_filtro_mediana->setObjectName(QStringLiteral("btn_filtro_mediana"));
        btn_filtro_mediana->setGeometry(QRect(30, 260, 151, 41));
        btn_transformacion_bilinela = new QPushButton(centralWidget);
        btn_transformacion_bilinela->setObjectName(QStringLiteral("btn_transformacion_bilinela"));
        btn_transformacion_bilinela->setGeometry(QRect(30, 310, 151, 41));
        btn_difuminado_aleatorio = new QPushButton(centralWidget);
        btn_difuminado_aleatorio->setObjectName(QStringLiteral("btn_difuminado_aleatorio"));
        btn_difuminado_aleatorio->setGeometry(QRect(30, 360, 151, 41));
        btn_fft = new QPushButton(centralWidget);
        btn_fft->setObjectName(QStringLiteral("btn_fft"));
        btn_fft->setGeometry(QRect(30, 410, 151, 41));
        btn_rgbHSI = new QPushButton(centralWidget);
        btn_rgbHSI->setObjectName(QStringLiteral("btn_rgbHSI"));
        btn_rgbHSI->setGeometry(QRect(30, 160, 151, 41));
        EditorImagenes->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EditorImagenes);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1471, 27));
        EditorImagenes->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EditorImagenes);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EditorImagenes->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EditorImagenes);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EditorImagenes->setStatusBar(statusBar);

        retranslateUi(EditorImagenes);

        QMetaObject::connectSlotsByName(EditorImagenes);
    } // setupUi

    void retranslateUi(QMainWindow *EditorImagenes)
    {
        EditorImagenes->setWindowTitle(QApplication::translate("EditorImagenes", "EditorImagenes", 0));
        input_image->setText(QApplication::translate("EditorImagenes", "Imagen de Entrada", 0));
        select_image->setText(QApplication::translate("EditorImagenes", "Seleccionar Imagen", 0));
        output_image->setText(QApplication::translate("EditorImagenes", "Imagen de salida", 0));
        btn_ecualizacion_histograma->setText(QApplication::translate("EditorImagenes", "Ecualizaci\303\263n Histograma", 0));
        btn_sobel->setText(QApplication::translate("EditorImagenes", "Sobel", 0));
        btn_filtro_mediana->setText(QApplication::translate("EditorImagenes", "Filtro de la Mediana", 0));
        btn_transformacion_bilinela->setText(QApplication::translate("EditorImagenes", "Transformacion Bilineal", 0));
        btn_difuminado_aleatorio->setText(QApplication::translate("EditorImagenes", "Difuminado Aleatorio", 0));
        btn_fft->setText(QApplication::translate("EditorImagenes", "FFT", 0));
        btn_rgbHSI->setText(QApplication::translate("EditorImagenes", "RGB to HSI", 0));
    } // retranslateUi

};

namespace Ui {
    class EditorImagenes: public Ui_EditorImagenes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORIMAGENES_H
