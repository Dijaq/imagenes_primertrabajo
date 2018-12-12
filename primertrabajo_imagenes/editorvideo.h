#ifndef EDITORVIDEO_H
#define EDITORVIDEO_H

#include <QDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

namespace Ui {
class editorvideo;
}

class editorvideo : public QDialog
{
    Q_OBJECT

public:
    explicit editorvideo(QWidget *parent = 0);
    ~editorvideo();
    void MatchingMethodVideo(Mat, Mat, int);

private slots:
    void on_btn_template_matching_clicked();

private:
    Ui::editorvideo *ui;
};

#endif // EDITORVIDEO_H
