#ifndef TEMPLATEMATCHING_H
#define TEMPLATEMATCHING_H

#include <QDialog>

namespace Ui {
class TemplateMatching;
}

class TemplateMatching : public QDialog
{
    Q_OBJECT

public:
    explicit TemplateMatching(QWidget *parent = 0);
    ~TemplateMatching();

private:
    Ui::TemplateMatching *ui;
};

#endif // TEMPLATEMATCHING_H
