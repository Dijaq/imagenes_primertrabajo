/********************************************************************************
** Form generated from reading UI file 'general.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERAL_H
#define UI_GENERAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_General
{
public:
    QPushButton *btn_procesamiento_imagenes;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *General)
    {
        if (General->objectName().isEmpty())
            General->setObjectName(QStringLiteral("General"));
        General->resize(665, 395);
        btn_procesamiento_imagenes = new QPushButton(General);
        btn_procesamiento_imagenes->setObjectName(QStringLiteral("btn_procesamiento_imagenes"));
        btn_procesamiento_imagenes->setGeometry(QRect(120, 120, 181, 61));
        pushButton_2 = new QPushButton(General);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 120, 181, 61));
        label = new QLabel(General);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 40, 121, 31));

        retranslateUi(General);

        QMetaObject::connectSlotsByName(General);
    } // setupUi

    void retranslateUi(QDialog *General)
    {
        General->setWindowTitle(QApplication::translate("General", "Dialog", 0));
        btn_procesamiento_imagenes->setText(QApplication::translate("General", "Procesamiento de Im\303\241genes", 0));
        pushButton_2->setText(QApplication::translate("General", "Procesamiento de Video", 0));
        label->setText(QApplication::translate("General", "Ventana General", 0));
    } // retranslateUi

};

namespace Ui {
    class General: public Ui_General {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERAL_H
