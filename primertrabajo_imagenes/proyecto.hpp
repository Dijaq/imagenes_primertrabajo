#ifndef PROYECTO_H
#define PROYECTO_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <time.h>
#include <math.h>

using namespace cv;

Mat opencv_fft(Mat);
Mat opencv_sobel(Mat);
Mat opencv_medianblur(Mat, int);
Mat opencv_histogram(Mat);
Mat opencv_histogram_gray(Mat, bool);
Mat opencv_ecualizacion(Mat);
Mat _ecualizacionHistograma(Mat);
Mat _ecualizacion(Mat, Mat, Mat, Mat);
Mat _ecualizacionHistograma_gray(Mat);
Mat _ecualizacion_gray(Mat, int *);
Mat _sobel(Mat);
Mat _medianBlur(Mat, int);
Mat _difuminadoAleatorio(Mat, int);
int * _calcularHistograma(Mat);
Mat _combinacionImagenes();
Mat _setFondoBlanco(Mat);
Mat _transformacionBilineal(Mat, Point, Point, Point, Point);
void TemplateMatching();
void MatchingMethod(int, void*);
void TemplateMatchingVideo();
void MatchingMethodVideo();

#endif // PROYECTO_H
