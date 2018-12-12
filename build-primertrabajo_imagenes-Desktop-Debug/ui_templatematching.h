/********************************************************************************
** Form generated from reading UI file 'templatematching.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEMATCHING_H
#define UI_TEMPLATEMATCHING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TemplateMatching
{
public:
    QPushButton *btn_select_template;
    QPushButton *btn_select_video;
    QLabel *label;
    QLabel *template_2;
    QLabel *video;

    void setupUi(QDialog *TemplateMatching)
    {
        if (TemplateMatching->objectName().isEmpty())
            TemplateMatching->setObjectName(QStringLiteral("TemplateMatching"));
        TemplateMatching->resize(790, 491);
        btn_select_template = new QPushButton(TemplateMatching);
        btn_select_template->setObjectName(QStringLiteral("btn_select_template"));
        btn_select_template->setGeometry(QRect(110, 70, 131, 41));
        btn_select_video = new QPushButton(TemplateMatching);
        btn_select_video->setObjectName(QStringLiteral("btn_select_video"));
        btn_select_video->setGeometry(QRect(480, 70, 121, 41));
        label = new QLabel(TemplateMatching);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 30, 131, 21));
        template_2 = new QLabel(TemplateMatching);
        template_2->setObjectName(QStringLiteral("template_2"));
        template_2->setGeometry(QRect(110, 180, 121, 121));
        video = new QLabel(TemplateMatching);
        video->setObjectName(QStringLiteral("video"));
        video->setGeometry(QRect(350, 130, 401, 291));

        retranslateUi(TemplateMatching);

        QMetaObject::connectSlotsByName(TemplateMatching);
    } // setupUi

    void retranslateUi(QDialog *TemplateMatching)
    {
        TemplateMatching->setWindowTitle(QApplication::translate("TemplateMatching", "Dialog", 0));
        btn_select_template->setText(QApplication::translate("TemplateMatching", "Seleccione Template", 0));
        btn_select_video->setText(QApplication::translate("TemplateMatching", "Seleccion Video", 0));
        label->setText(QApplication::translate("TemplateMatching", "Template Matching", 0));
        template_2->setText(QApplication::translate("TemplateMatching", "TextLabel", 0));
        video->setText(QApplication::translate("TemplateMatching", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TemplateMatching: public Ui_TemplateMatching {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEMATCHING_H
