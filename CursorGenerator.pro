QT = core gui widgets

CONFIG += c++11

INCLUDEPATH += /usr/local/include/opencv4
QMAKE_LFLAGS +=  -L/usr/local/lib
LIBS += -lopencv_calib3d -lopencv_core -lopencv_dnn -lopencv_features2d -lopencv_flann -lopencv_gapi \
        -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo \
        -lopencv_stitching -lopencv_video -lopencv_videoio

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    renderarea.cpp \
    videocaptureThread.cpp

HEADERS += \
    mainwindow.h \
    renderarea.h \
    videocaptureThread.h
