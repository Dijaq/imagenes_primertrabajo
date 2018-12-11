#include <iostream>
#include <fstream>
#include <string>
#include "proyecto.hpp"

using namespace std;

/**Tema2**/
void combinacionImagenes()
{
    Mat result = _combinacionImagenes();
    imwrite("static/imagen.jpg", result);
}

/**Tema2**/
void ecualizacion(char *nameImage)
{
    Mat src = imread("static/"+(string)nameImage);
    Mat result = _ecualizacionHistograma_gray(src);
    //imshow("Ecualizacion", result);
    imwrite("static/imagen.jpg", result);
}

/**Tema3**/

void sobel(char *nameImage)
{
    Mat src = imread("static/"+(string)nameImage);
    Mat result = _sobel(src);
    //imshow("Ecualizacion", result);
    imwrite("static/imagen.jpg", result);
}

/**Tema3**/
void medianBlur(char *nameImage)
{
    Mat src = imread("static/"+(string)nameImage);
    Mat result = _medianBlur(src, 5);
    //imshow("Ecualizacion", result);
    imwrite("static/imagen.jpg", result);
}

/**Tema4**/
void difuminadoAleatorio(char *nameImage)
{
    Mat src = imread("static/"+(string)nameImage);
    Mat result = _difuminadoAleatorio(src, 50);
    //imshow("Ecualizacion", result);
    imwrite("static/imagen.jpg", result);
}

/**Tema4**/
void transformacionBilineal(char *nameImage){
    Mat src = imread("static/"+(string)nameImage);
    Point point1;
    point1.x = 50;
    point1.y = 0;
    Point point2;
    point2.x = 500;
    point2.y = 50;
    Point point3;
    point3.x = 200;
    point3.y = 480;
    Point point4;
    point4.x = 20;
    point4.y = 190;
    
    Mat result = _transformacionBilineal(src, point1,point2, point3, point4);
    imwrite("static/imagen.jpg", result);
}

/**Tema5**/
void fft(char *nameImage)
{
    Mat src = imread("static/"+(string)nameImage);
    Mat result = opencv_fft(src);
    //imshow("Ecualizacion", result);
    imwrite("static/imagen.jpg", result);
}

extern "C"
{
    extern void cffi_combinacionImagenes()
    {
        return combinacionImagenes();
    }

    extern void cffi_ecualizacion(char * nameImage)
    {
        return ecualizacion(nameImage);
    }

    extern void cffi_sobel(char * nameImage)
    {
        return sobel(nameImage);
    }

    extern void cffi_medianblur(char * nameImage)
    {
        return medianBlur(nameImage);
    }

    extern void cffi_difuminadoAleatorio(char * nameImage)
    {
        return difuminadoAleatorio(nameImage);
    }

    extern void cffi_transformacionBilineal(char * nameImage)
    {
        return transformacionBilineal(nameImage);
    }

    extern void cffi_fft(char * nameImage)
    {
        return fft(nameImage);
    }

}