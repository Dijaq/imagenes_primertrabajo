#include "proyecto.hpp"

using namespace cv;
using namespace std;

/*proyecto::proyecto()
{

}*/

int thread_count = 4;
Mat img, templ;
int match_method = 5;
int max_Trackbar = 5;

Mat opencv_fft(Mat src)
{
    Mat src_gray;
    cvtColor(src, src_gray, CV_BGR2GRAY);
    Mat padded;
    int m = getOptimalDFTSize(src_gray.rows);
    int n = getOptimalDFTSize(src_gray.cols);
    copyMakeBorder(src_gray, padded, 0, m-src_gray.rows, 0, n-src_gray.cols, BORDER_CONSTANT, Scalar::all(0));

    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexSrc;
    merge(planes, 2, complexSrc);
    dft(complexSrc, complexSrc);

    split(complexSrc, planes);
    magnitude(planes[0], planes[1], planes[0]);
    Mat magSrc = planes[0];

    magSrc += Scalar::all(1);
    log(magSrc, magSrc);

    magSrc = magSrc(Rect(0, 0, magSrc.cols & -2, magSrc.rows & -2));

    int cx = magSrc.rows/2;
    int cy = magSrc.cols/2;

    Mat q0(magSrc, Rect(0, 0, cx, cy));
    Mat q1(magSrc, Rect(cx, 0, cx, cy));
    Mat q2(magSrc, Rect(0, cy, cx, cy));
    Mat q3(magSrc, Rect(cx, cy, cx, cy));

    Mat tmp;
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(magSrc, magSrc, 0, 1, CV_MINMAX);

    return magSrc;
}


Mat opencv_histogram(Mat src)
{
    vector<Mat> bgr_planes;
    split(src, bgr_planes);

    int histSize = 256;

    float range[] = {0, 256};
    const float* histRange = {range};

    bool uniform = true;
    bool accumulate = false;

    Mat b_hist, g_hist, r_hist;

    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w/histSize);

    cout << "B_histograma: "<< b_hist << endl;

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

#pragma omp parallel for num_threads(thread_count)
    for(int i=1; i<histSize; i++)
    {
        line(histImage, Point(bin_w*(i-1), hist_h-cvRound(b_hist.at<float>(i-1))),
            Point(bin_w*(i), hist_h-cvRound(b_hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
        line(histImage, Point(bin_w*(i-1), hist_h-cvRound(g_hist.at<float>(i-1))),
            Point(bin_w*(i), hist_h-cvRound(b_hist.at<float>(i))),
            Scalar(0, 255, 0), 2, 8, 0);
        line(histImage, Point(bin_w*(i-1), hist_h-cvRound(r_hist.at<float>(i-1))),
            Point(bin_w*(i), hist_h-cvRound(b_hist.at<float>(i))),
            Scalar(0, 0, 255), 2, 8, 0);
    }

    return histImage;

}


Mat opencv_ecualizacion(Mat src)
{
    Mat src_gray, dst;
    cvtColor(src, src_gray, CV_BGR2GRAY);
    equalizeHist(src_gray, dst);

    return dst;
}


Mat opencv_histogram_gray(Mat src, bool is_gray)
{
    Mat src_gray;
    if(is_gray)
    {
        src_gray = src.clone();
    }
    else
    {
        cvtColor(src, src_gray, CV_BGR2GRAY);
    }

    int histSize = 256;

    float range[] = {0, 256};
    const float* histRange = {range};

    bool uniform = true;
    bool accumulate = false;

    Mat i_hist;

    calcHist(&src_gray, 1, 0, Mat(), i_hist, 1, &histSize, &histRange, uniform, accumulate);

    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w/histSize);

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    normalize(i_hist, i_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());


    for(int i=1; i<histSize; i++)
    {
        line(histImage, Point(bin_w*(i-1), hist_h-cvRound(i_hist.at<float>(i-1))),
            Point(bin_w*(i), hist_h-cvRound(i_hist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
    }

    return histImage;

}


Mat opencv_medianblur(Mat src, int size)
{
    Mat dst;

    medianBlur(src, dst, size);

    return dst;
}


Mat opencv_sobel(Mat src)
{
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    string window_name = "Sobel Demo";
    Mat src_gray, grad;
    Mat dst = src.clone();

    blur(src, dst, Size(3,3));
    cvtColor(dst, src_gray, CV_BGR2GRAY);

    //namedWindow(window_name, CV_WINDOW_AUTOSIZE);

    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);
    Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(grad_y, abs_grad_y);

    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

    return grad;
}


/**
Author: Diego Javier
Tema 2
Implementación del filtro de _medianBlur para el suavizado de la imagen
**/

Mat _ecualizacionHistograma(Mat src)
{
    vector<Mat> bgr_planes;
    split(src, bgr_planes);

    int histSize = 256;

    float range[] = {0, 256};
    const float* histRange = {range};

    bool uniform = true;
    bool accumulate = false;

    Mat b_hist, g_hist, r_hist;

    calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w/histSize);

    return _ecualizacion(src, r_hist, g_hist, b_hist);

}


Mat _ecualizacion(Mat src, Mat r_hist, Mat g_hist, Mat b_hist)
{
    int f_r[256];
    int f_g[256];
    int f_b[256];

    f_r[0] = 0;
    f_g[0] = 0;
    f_b[0] = 0;

    int acumulado_r = r_hist.at<int>(0,0);
    int acumulado_g = g_hist.at<int>(0,0);
    int acumulado_b = b_hist.at<int>(0,0);

#pragma omp parallel for num_threads(thread_count)
    for(int i=1; i<255; i++)
    {
        f_r[i] = acumulado_r*255/(src.rows*src.cols);
        acumulado_r = acumulado_r + r_hist.at<int>(i,0);
        f_g[i] = acumulado_g*255/(src.rows*src.cols);
        acumulado_g = acumulado_g + g_hist.at<int>(i,0);
        f_b[i] = acumulado_b*255/(src.rows*src.cols);
        acumulado_b = acumulado_b + b_hist.at<int>(i,0);
    }

    f_r[255] = 255;
    f_g[255] = 255;
    f_b[255] = 255;

    string window_name = "Filtro sobel implementacion propia";

    Mat result = src.clone();

#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<src.rows; i++)
    {
        for(int j=0; j<src.cols; j++)
        {
            src.at<Vec3b>(i, j)[0] = f_r[(int)((Scalar)src.at<Vec3b>(i, j)[0]).val[0]];
            src.at<Vec3b>(i, j)[1] = f_g[(int)((Scalar)src.at<Vec3b>(i, j)[1]).val[0]];
            src.at<Vec3b>(i, j)[2] = f_b[(int)((Scalar)src.at<Vec3b>(i, j)[2]).val[0]];
        }
    }

    return src;

}


Mat _ecualizacionHistograma_gray(Mat src)
{
    Mat src_gray;
    cvtColor(src, src_gray, CV_BGR2GRAY);

    int histSize = 256;

    float range[] = {0, 256};
    const float* histRange = {range};

    bool uniform = true;
    bool accumulate = false;

    int * hist_gray = _calcularHistograma(src_gray);


    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w/histSize);


    return _ecualizacion_gray(src_gray, hist_gray);

}


Mat _ecualizacion_gray(Mat src, int *hist_gray)
{
    int f_g[256];
    f_g[0] = 0;

    int acumulado_g = hist_gray[0];

//#pragma omp parallel for num_threads(thread_count)
    for(int i=1; i<255; i++)
    {
        f_g[i] = acumulado_g*255/(src.rows*src.cols);
        acumulado_g = acumulado_g + hist_gray[i];
    }

    f_g[255] = 255;

    string window_name = "Filtro sobel implementacion propia";

    Mat result = src.clone();

//#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<src.rows; i++)
    {
        for(int j=0; j<src.cols; j++)
        {
            src.at<uchar>(i, j) = f_g[(int)((Scalar)src.at<uchar>(i, j)).val[0]];
        }
    }

    return src;

}


int * _calcularHistograma(Mat src)
{
    int *histo = new int[256];

//#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<256; i++)
    {
        histo[i] = 0;
    }

//#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<src.rows; i++)
    {
        for(int j=0; j<src.cols; j++)
        {
            histo[(int)((Scalar)src.at<uchar>(i,j)).val[0]] +=1;
            if(i <3 && j<1)
            {
                cout << ((Scalar)src.at<uchar>(i,j)).val[0] << endl;
            }
        }
    }

    return histo;
}


/**
Author: Diego Javier
Tema 2
Implementación de la combinacion de imagenes
**/
Mat _combinacionImagenes()
{
    Mat img1 = imread("tigre2.jpg");
    Mat img2 = imread("lava.jpg");

    cout << ((Scalar)img1.at<Vec3b>(3,3)[0]).val[0] << endl;

    img1 = _medianBlur(img1, 3);

#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<img2.rows; i++)
    {
        for(int j=0; j<img2.cols; j++)
        {
            if((((Scalar)img1.at<Vec3b>(i,j)[0]).val[0] != 0) && (((Scalar)img1.at<Vec3b>(i,j)[1]).val[0] != 0) &&(((Scalar)img1.at<Vec3b>(i,j)[2]).val[0] != 0))
            {
                img2.at<Vec3b>(i,j) = img1.at<Vec3b>(i,j);

            }
        }
    }

    return img2;
}


Mat _setFondoBlanco(Mat src)
{

#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<src.rows; i++)
    {
        for(int j=0; j<src.cols; j++)
        {
            if((((Scalar)src.at<Vec3b>(i,j)[0]).val[0] != 1) && (((Scalar)src.at<Vec3b>(i,j)[1]).val[0] != 254) &&(((Scalar)src.at<Vec3b>(i,j)[2]).val[0] != 49))
            {
                ((Scalar)src.at<Vec3b>(i,j)[0]).val[0] = 255;
                ((Scalar)src.at<Vec3b>(i,j)[1]).val[0] = 255;
                ((Scalar)src.at<Vec3b>(i,j)[2]).val[0] = 255;
            }
        }
    }

    return src;
}


/**
Author: Diego Javier
Tema 3
Implementación del filtro de _medianBlur para el suavizado de la imagen
**/

Mat _medianBlur(Mat src, int size)
{
    string window_name = "Filtro sobel implementacion propia";
    Mat dst = src.clone();

    Mat kernel = Mat::ones(size, size, CV_8UC1);
    Mat result = src.clone();

    int mid_size = size/2;

#pragma omp parallel for num_threads(thread_count)
    for(int i=mid_size; i<src.rows-mid_size; i++)
    {
        for(int j=mid_size; j<src.cols-mid_size; j++)
        {
            int sumaR = 0;
            int sumaG = 0;
            int sumaB = 0;

            for(int x=0; x<size; x++)
            {
                for(int y=0; y<size; y++)
                {
                    sumaR += ((Scalar)src.at<Vec3b>(i-mid_size+x,j-mid_size+y)[0]).val[0]*1;
                    sumaG += ((Scalar)src.at<Vec3b>(i-mid_size+x,j-mid_size+y)[1]).val[0]*1;
                    sumaB += ((Scalar)src.at<Vec3b>(i-mid_size+x,j-mid_size+y)[2]).val[0]*1;

                }
            }

            result.at<Vec3b>(i,j)[0] = sumaR/(size*size);
            result.at<Vec3b>(i,j)[1] = sumaG/(size*size);
            result.at<Vec3b>(i,j)[2] = sumaB/(size*size);


            if(i == 2 && j==2)
            {
                cout << ((Scalar)result.at<Vec3b>(i,j)[0]).val[0]<<endl;
                cout << ((Scalar)result.at<Vec3b>(i,j)[1]).val[0] <<endl;
                cout << ((Scalar)result.at<Vec3b>(i,j)[2]).val[0] <<endl;
            }
        }
    }

    return result;
}

/**
Author: Diego Javier
Tema 3
Implementación del filtro de _medianBlur para detección de bordes
**/
Mat _sobel(Mat src)
{
    string window_name = "Filtro sobel implementacion propia";
    Mat src_gray_x, grad;
    Mat dst = src.clone();
    Mat G_x = (Mat_<double>(3,3)<<-1, 0, 1, -2, 0, 2, -1, 0, 1);
    Mat G_y = (Mat_<double>(3,3)<<-1, -2, -1, 0, 0, 0, 1, 2, 1);

    dst = _medianBlur(src, 5);
    cvtColor(dst, src_gray_x, CV_BGR2GRAY);

    Mat result = Mat::zeros(src.rows, src.cols, CV_8UC1);
    Mat grad_x = Mat::zeros(src.rows, src.cols, CV_8UC1);
    Mat grad_y = Mat::zeros(src.rows, src.cols, CV_8UC1);

    Mat src_gray_y = src_gray_x.clone();
    for(int i=1; i<src.rows-1; i++)
    {
        for(int j=1; j<src.cols-1; j++)
        {
            if(i == 1 && j==1)
            {
                cout << ((Scalar)src_gray_x.at<uchar>(i-1,j-1)).val[0] << endl;

            }


            grad_x.at<uchar>(i,j) += abs((src_gray_x.at<uchar>(i-1,j-1)*G_x.at<double>(0,0)+
                src_gray_x.at<uchar>(i-1,j)*G_x.at<double>(0,1)+
                src_gray_x.at<uchar>(i-1,j+1)*G_x.at<double>(0,2)+
                src_gray_x.at<uchar>(i,j-1)*G_x.at<double>(1,0)+
                src_gray_x.at<uchar>(i,j)*G_x.at<double>(1,1)+
                src_gray_x.at<uchar>(i,j+1)*G_x.at<double>(1,2)+
                src_gray_x.at<uchar>(i+1,j-1)*G_x.at<double>(2,0)+
                src_gray_x.at<uchar>(i+1,j)*G_x.at<double>(2,1)+
                src_gray_x.at<uchar>(i+1,j+1)*G_x.at<double>(2,2)));
            if(i == 1 && j==1)
            {
                cout << "*-->"<< ((Scalar)grad_x.at<uchar>(i,j)).val[0] << endl;

            }
        }
    }

#pragma omp parallel for num_threads(thread_count)
    for(int i=1; i<src.rows-1; i++)
    {
        for(int j=1; j<src.cols-1; j++)
        {
            grad_y.at<uchar>(i,j) += abs((src_gray_y.at<uchar>(i-1,j-1)*G_y.at<double>(0,0)+
                src_gray_y.at<uchar>(i-1,j)*G_y.at<double>(0,1)+
                src_gray_y.at<uchar>(i-1,j+1)*G_y.at<double>(0,2)+
                src_gray_y.at<uchar>(i,j-1)*G_y.at<double>(1,0)+
                src_gray_y.at<uchar>(i,j)*G_y.at<double>(1,1)+
                src_gray_y.at<uchar>(i,j+1)*G_y.at<double>(1,2)+
                src_gray_y.at<uchar>(i+1,j-1)*G_y.at<double>(2,0)+
                src_gray_y.at<uchar>(i+1,j)*G_y.at<double>(2,1)+
                src_gray_y.at<uchar>(i+1,j+1)*G_y.at<double>(2,2)));
        }
    }

#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<src.rows; i++)
    {
        for(int j=0; j<src.cols; j++)
        {
            result.at<uchar>(i,j) += sqrt(pow(grad_x.at<uchar>(i,j),2)+pow(grad_y.at<uchar>(i,j),2));
        }
    }


    return result;
}

/**
Author: Diego Javier
Tema 4
Implementación del difuminado Aleatorio
**/

Mat _difuminadoAleatorio(Mat src, int a)
{
    srand(time(NULL));

    Mat result = src.clone();
#pragma omp parallel for num_threads(thread_count)
    for(int i=0; i<src.rows; i++)
    {
        for(int j=0; j<src.cols; j++)
        {
            int fx = i+rand()%(2*a+1)-a;
            int fy = j+rand()%(2*a+1)-a;

            if((fx >=0 && fx < src.rows) && (fy >=0 && fy < src.cols))
            {
                Vec3b pixelActual = result.at<Vec3b>(i,j);
                result.at<Vec3b>(i,j) = result.at<Vec3b>(fx,fy);
                result.at<Vec3b>(fx,fy) = result.at<Vec3b>(fx,fy);
            }
        }
    }

    return result;
}


Mat _transformacionBilineal(Mat src, Point xo1,Point xo2, Point xo3, Point xo4)
{
    int src_x = src.rows;
    int src_y = src.cols;

    Point xi1, xi2, xi3, xi4;
    xi1.x = 0; xi1.y = 0;
    xi2.x = src_x-1; xi2.y = 0;
    xi3.x = src_x-1; xi3.y = src_y-1;
    xi4.x = 0; xi4.y = src_y-1;

    double cx[4][5] = {{xi1.x, xi1.y,  xi1.x*xi1.y, 1, xo1.x}, {xi2.x, xi2.y, xi2.x*xi2.y, 1, xo2.x}, {xi3.x, xi3.y, xi3.x*xi3.y, 1, xo3.x}, {xi4.x, xi4.y, xi4.x*xi4.y, 1, xo4.x}};
    double cy[4][5] = {{xi1.x, xi1.y,  xi1.x*xi1.y, 1, xo1.y}, {xi2.x, xi2.y, xi2.x*xi2.y, 1, xo2.y}, {xi3.x, xi3.y, xi3.x*xi3.y, 1, xo3.y}, {xi4.x, xi4.y, xi4.x*xi4.y, 1, xo4.y}};

    for(int i=0; i<4; i++)
    {
        if(cx[i][i] == 0)
        {
            for(int k=i+1; k<4; k++)
            {
                if(cx[k][i] != 0)
                {
                    for(int p=0; p<5; p++)
                    {
                        double temp = cx[i][p];
                        cx[i][p] = cx[k][p];
                        cx[k][p] = temp;
                    }
                    break;
                }
            }
        }
        for(int n=i+1; n<4; n++)
        {
            double _temp = cx[n][i];
            for(int m=0; m<5; m++)
            {
                cx[n][m] = cx[n][m] - cx[i][m]*_temp/cx[i][i];
            }
        }

        for(int n=i-1; n>=0; n--)
        {
            double _temp = cx[n][i];
            for(int m=0; m<5; m++)
            {
                cx[n][m] = cx[n][m] - cx[i][m]*_temp/cx[i][i];
            }
        }
    }

    for(int i=0; i<4; i++)
    {
        cx[i][4] = cx[i][4]/cx[i][i];
        cx[i][i] = cx[i][i]/cx[i][i];
    }

    for(int i=0; i<4; i++)
    {
        if(cy[i][i] == 0)
        {
            for(int k=i+1; k<4; k++)
            {
                if(cy[k][i] != 0)
                {
                    for(int p=0; p<5; p++)
                    {
                        double temp = cy[i][p];
                        cy[i][p] = cy[k][p];
                        cy[k][p] = temp;
                    }
                    break;
                }
            }
        }

        for(int n=i+1; n<4; n++)
        {
            double _temp = cy[n][i];
            for(int m=0; m<5; m++)
            {
                cy[n][m] = cy[n][m] - cy[i][m]*_temp/cy[i][i];
            }
        }

        for(int n=i-1; n>=0; n--)
        {
            double _temp = cy[n][i];
            for(int m=0; m<5; m++)
            {
                cy[n][m] = cy[n][m] - cy[i][m]*_temp/cy[i][i];
            }
        }
    }

    for(int i=0; i<4; i++)
    {
        cy[i][4] = cy[i][4]/cy[i][i];
        cy[i][i] = cy[i][i]/cy[i][i];
    }

    for(int i=0; i<4; i++)
    {
        cout << cx[i][4] << endl;
    }

    for(int i=0; i<4; i++)
    {
        cout << cy[i][4] << endl;
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout << cy[i][j] << " ";
        }
        cout << endl;
    }

    Mat src_gray;
    cvtColor(src, src_gray, CV_BGR2GRAY);
    Mat src_result = src_gray.clone();

    for(int i=0; i<src_gray.rows; i++)
    {
        for(int j=0; j<src_gray.cols; j++)
        {
            src_result.at<uchar>(i,j) = 255;
        }

    }

    for(int i=0; i<src_gray.rows; i++)
    {
        for(int j=0; j<src_gray.cols; j++)
        {
            int x = i*cx[0][4]+j*cx[1][4]+i*j*cx[2][4]+cx[3][4];
            int y = i*cy[0][4]+j*cy[1][4]+i*j*cy[2][4]+cy[3][4];

            src_result.at<uchar>(x,y) = src_gray.at<uchar>(i,j);
        }
    }

    return src_result;

}

/*
void TemplateMatching()
{

    img = imread("prueba.PNG");
    templ = imread("template.PNG");

    namedWindow(image_window, CV_WINDOW_AUTOSIZE);
    namedWindow(result_window, CV_WINDOW_AUTOSIZE);

    char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEDD \n 5: TM COEFF NORMED";

    MatchingMethod(0, 0);

    waitKey(0);
}

void MatchingMethod(int, void*)
{
    match_method = 5;
    Mat img_display, result;
    img.copyTo(img_display);

    int result_cols = img.cols - templ.cols+1;
    int result_rows = img.rows - templ.rows+1;

    result.create(result_rows, result_cols, CV_32FC1);

    matchTemplate(img, templ, result, match_method);
    normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());

    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    Point matchLoc;

    minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

    cout << "--" << match_method << endl;

    if(match_method == TM_SQDIFF || match_method == TM_SQDIFF_NORMED)
    {
        matchLoc = minLoc;
    }
    else
    {
        matchLoc = maxLoc;
    }

    rectangle(img_display, matchLoc, Point(matchLoc.x+templ.cols, matchLoc.y+templ.rows), Scalar::all(0), 2, 8, 0);
    rectangle(result, matchLoc, Point(matchLoc.x+templ.cols, matchLoc.y+templ.rows), Scalar::all(0), 2, 8, 0);

    imshow(image_window, img_display);
    imshow(result_window, result);

}*/


void TemplateMatchingVideo()
{
    templ = imread("template.PNG");

    //namedWindow(image_window, CV_WINDOW_AUTOSIZE);
    //namedWindow(result_window, CV_WINDOW_AUTOSIZE);

    //char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEDD \n 5: TM COEFF NORMED";

    VideoCapture cap("prueba.avi");
    if ( !cap.isOpened() )
    {
        cout << "Cannot open the video file. \n";
    }

    double fps = cap.get(CV_CAP_PROP_FPS);

    while(1)
    {
        if (!cap.read(img))
        {
            cout<<"\n Cannot read the video file. \n";
            break;
        }

        MatchingMethodVideo();

      //  if(waitKey(30) == 27)
      //  {
      //      break;
       // }
    }


    //    waitKey(0);
}

void MatchingMethodVideo()
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

