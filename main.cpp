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

}