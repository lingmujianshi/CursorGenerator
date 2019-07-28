#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    :QWidget(parent)
{
    this->setFixedSize(640,480);
    //this->setStyleSheet("background-color:black");
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    pixmap.load("/Users/lmjs/work/CursorGenerator/Text.bmp");
    mThread = new VideoCaptureThread(this);

    cursorDefalut();
    connect(mThread,&VideoCaptureThread::vidoeCaptured,this,&RenderArea::videoUpdate);
    //std::thread th(&RenderArea::videoCapture,this);
    //th.detach();

}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if(qimg != nullptr)
    {
        painter.drawImage(QRect( 0, 0,this->width(),this->height()), *qimg);
    }
    else {
        qDebug() << "qimg is null";
    }
    //painter.drawPixmap(QRect(0,0,this->width(),this->height()), pixmap);

    QPen pen(Qt::blue);

    painter.setPen(pen);
    painter.drawLine(0,center.y(),this->width(),center.y());
    painter.drawLine(center.x(), 0 , center.x(), this->height());
    painter.drawEllipse(center.x()-radius,center.y()-radius,radius*2,radius*2);
}

void RenderArea::cursorDefalut()
{
    center.setX(this->width() / 2);
    center.setY(this->height() / 2);
    radius = 30;
}

void RenderArea::videoCapture()
{
    qDebug() << "renderArea videoCapture()";
    if(mThread->stop)
        mThread->stop = false;
    else
        mThread->stop = true;

    mThread->start();
}

void RenderArea::moveCursor(QPoint p,int r)
{
    qDebug() << p;
    center.setX(center.x() + p.x());
    center.setY(center.y() + p.y());
    radius += r;

    if(center.x() < 0 ) center.setX(0);
    if(center.x() > this->width() ) center.setX(this->width());
    if(center.y() < 0 ) center.setY(0);
    if(center.y() > this->height() ) center.setY(this->height());
    if(radius < 0)  radius = 0;
    if(radius > this->height() / 2) radius = this->height() / 2;


    qDebug() << "(" << center.x() << "," << center.y() << ",r:" << radius << ")";
    update();
}

void RenderArea::videoUpdate(QImage *img)
{
    qDebug() << "videoUpdate";
    qimg = img;
    update();
}

