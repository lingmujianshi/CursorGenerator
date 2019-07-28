#ifndef VIDEOCAPTURE_H
#define VIDEOCAPTURE_H

#include <QtWidgets>
#include <opencv2/opencv.hpp>

class VideoCaptureThread : public QThread
{
    Q_OBJECT
public:
    VideoCaptureThread(QObject *parent = nullptr);
    cv::VideoCapture video;
    bool stop = true;

private:
    void run() override;

signals:
    void vidoeCaptured(QImage *img);
};

#endif // VIDEOCAPTURE_H
