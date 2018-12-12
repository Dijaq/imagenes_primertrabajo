/********************************************************************************
** Form generated from reading UI file 'editorvideo.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITORVIDEO_H
#define UI_EDITORVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_editorvideo
{
public:
    QLabel *lbl_template;
    QLabel *lbl_video;
    QPushButton *btn_template_matching;

    void setupUi(QDialog *editorvideo)
    {
        if (editorvideo->objectName().isEmpty())
            editorvideo->setObjectName(QStringLiteral("editorvideo"));
        editorvideo->resize(683, 535);
        lbl_template = new QLabel(editorvideo);
        lbl_template->setObjectName(QStringLiteral("lbl_template"));
        lbl_template->setGeometry(QRect(80, 160, 151, 121));
        lbl_video = new QLabel(editorvideo);
        lbl_video->setObjectName(QStringLiteral("lbl_video"));
        lbl_video->setGeometry(QRect(350, 170, 311, 251));
        btn_template_matching = new QPushButton(editorvideo);
        btn_template_matching->setObjectName(QStringLiteral("btn_template_matching"));
        btn_template_matching->setGeometry(QRect(280, 60, 171, 71));

        retranslateUi(editorvideo);

        QMetaObject::connectSlotsByName(editorvideo);
    } // setupUi

    void retranslateUi(QDialog *editorvideo)
    {
        editorvideo->setWindowTitle(QApplication::translate("editorvideo", "Dialog", 0));
        lbl_template->setText(QApplication::translate("editorvideo", "Template", 0));
        lbl_video->setText(QApplication::translate("editorvideo", "Video", 0));
        btn_template_matching->setText(QApplication::translate("editorvideo", "Template Matching", 0));
    } // retranslateUi

};

namespace Ui {
    class editorvideo: public Ui_editorvideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITORVIDEO_H
