#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <thread>

#include <QtWidgets>
#include <opencv2/opencv.hpp>

#include "videocaptureThread.h"

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    RenderArea(QWidget *parent=nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPoint center;
    int radius;
    cv::VideoCapture video;
    QPixmap pixmap;
    QImage *qimg = nullptr;
    VideoCaptureThread *mThread;

public:
    void cursorDefalut();
    void videoCapture();

public slots:
    void moveCursor(QPoint p,  int r);
    void videoUpdate(QImage *img);
};

#endif // RENDERAREA_H
