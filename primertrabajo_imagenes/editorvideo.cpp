#include "editorvideo.h"
#include "ui_editorvideo.h"

//int thread_count = 4;
//Mat img, templ;
//int match_method = 5;
//int max_Trackbar = 5;


editorvideo::editorvideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editorvideo)
{
    ui->setupUi(this);
}

editorvideo::~editorvideo()
{
    delete ui;
}

void editorvideo::on_btn_template_matching_clicked()
{
    Mat inputImage = imread("template.PNG", CV_LOAD_IMAGE_COLOR);
    cvtColor(inputImage, inputImage, CV_BGR2RGB);

    QImage image((uchar*)inputImage.data, inputImage.cols, inputImage.rows, inputImage.step, QImage::Format_RGB888);
    image = image.scaledToWidth(ui->lbl_template->width(), Qt::SmoothTransformation);
    ui->lbl_template->setPixmap(QPixmap::fromImage(image));

    //namedWindow(image_window, CV_WINDOW_AUTOSIZE);
    //namedWindow(result_window, CV_WINDOW_AUTOSIZE);

    //char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEDD \n 5: TM COEFF NORMED";

    VideoCapture cap("prueba.avi");
    if ( !cap.isOpened() )
    {
        cout << "Cannot open the video file. \n";
    }

    double fps = cap.get(CV_CAP_PROP_FPS);

    Mat img;
    int match_method = 5;

   /* while(1)
    {
        if (!cap.read(img))
        {
            cout<<"\n Cannot read the video file. \n";
            break;
        }

        //MatchingMethodVideo(inputImage, img, match_method);

      //  if(waitKey(30) == 27)
      //  {
      //      break;
       // }
    }*/

   // namedWindow("final");
    //imshow("final", inputImage);
}

void editorvideo:: MatchingMethodVideo(Mat templ, Mat img, int match_method)
{
    Mat img_display, result;
    img.copyTo(img_display);

    result.create(img.rows - templ.rows+1, img.cols - templ.cols+1, CV_32FC1);

    matchTemplate(img, templ, result, match_method);
    normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    Point matchLoc;

    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

    if(match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED)
    {
        matchLoc = minLoc;
    }
    else
    {
        matchLoc = maxLoc;
    }

    rectangle(img_display, matchLoc, Point(matchLoc.x+templ.cols, matchLoc.y+templ.rows), Scalar::all(0), 2, 8, 0);

    //imshow(image_window, img_display);

}
