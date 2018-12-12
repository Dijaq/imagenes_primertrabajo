#-------------------------------------------------
#
# Project created by QtCreator 2018-12-11T18:51:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = primertrabajo_imagenes
TEMPLATE = app

INCLUDEPATH += /usr/local/include/
QMAKE_CXXFLAGS += -fopenmp
LIBS += -L/usr/local/lib -lopencv_dnn -lopencv_ml -lopencv_objdetect -lopencv_shape -lopencv_stitching -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_imgproc -lopencv_flann -lopencv_core -fopenmp

CONFIG += c++11

SOURCES += main.cpp\
        editorimagenes.cpp \
    proyecto.cpp \
    general.cpp \
    editorvideo.cpp

HEADERS  += editorimagenes.h \
    proyecto.hpp \
    general.h \
    editorvideo.h

FORMS    += editorimagenes.ui \
    general.ui \
    editorvideo.ui
