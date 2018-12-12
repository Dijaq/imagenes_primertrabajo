#include "editorimagenes.h"
#include "general.h"
#include "proyecto.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <omp.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //EditorImagenes w;
    General w;
    w.show();

    return a.exec();
}
