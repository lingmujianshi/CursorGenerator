#include "videocaptureThread.h"

#include <QMessageBox>

VideoCaptureThread::VideoCaptureThread(QObject *parent)
    : QThread (parent)
{
    if(video.isOpened())
    {
        //ui->startBtn->setText("Start");
        video.release();
        return;
    }

    int cameraIndex = 1200;
    if(!video.open(cameraIndex))
    {
            //QMessageBox::critical(this,
            //                      "Camera Error",
            //                      "Make sure you enter a corrent camera index,"
            //                      "<br>or that the camera is not being accessed by another program!"
            //                      );
        qDebug() << "Camera Error";
            return;
    }
    else
    {
        qDebug() << "Camera" << cameraIndex << " is Opened";
    }
}

void VideoCaptureThread::run()
{
    qDebug() << "Qthread now";

    //ui->startBtn->setText("Stop");
    cv::Mat frame;

    while(video.isOpened())
    {
        if (stop)
            break;
        QMutex mutex;
        mutex.lock();
        video >> frame;
        cv::cvtColor(frame,frame,cv::COLOR_BGR2RGB);
        QImage qimgin (frame.data,
                    frame.cols,
                    frame.rows,
                    static_cast<int>(frame.step),
                    QImage::Format_RGB888);


        qDebug() << "in roop";
        emit vidoeCaptured(&qimgin);
        mutex.unlock();
        this->sleep(1);
    }
}
