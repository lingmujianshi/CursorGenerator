#include "mainwindow.h"
#include <thread>
MainWindow::MainWindow()
{
    renderarea = new RenderArea(this);
    //this->setGeometry(-500,100,500,500);
    upButton = new QPushButton("up");
    downButton = new QPushButton("down");
    leftButton = new QPushButton("left");
    rightButton = new QPushButton("right");
    expandButton = new QPushButton("expand");
    shrinkButton = new QPushButton("shrink");
    resetButton = new QPushButton("reset");
    videoStartButton = new QPushButton("video");

    upButton->setAutoRepeat(true);
    downButton->setAutoRepeat(true);
    leftButton->setAutoRepeat(true);
    rightButton->setAutoRepeat(true);
    expandButton->setAutoRepeat(true);
    shrinkButton->setAutoRepeat(true);


    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->addWidget(renderarea,0,0,1,4);
    mainLayout->addWidget(upButton,1,1);
    mainLayout->addWidget(downButton,3,1);
    mainLayout->addWidget(leftButton,2,0);
    mainLayout->addWidget(rightButton,2,2);
    mainLayout->addWidget(expandButton,1,3);
    mainLayout->addWidget(shrinkButton,2,3);
    mainLayout->addWidget(resetButton,4,3);
    mainLayout->addWidget(videoStartButton,4,2);
    setLayout(mainLayout);

    connect(upButton,&QPushButton::pressed,this,&MainWindow::upButtonPressed);
    connect(downButton,&QPushButton::pressed,this,&MainWindow::downButtonPressed);
    connect(leftButton,&QPushButton::pressed,this,&MainWindow::leftButtonPressed);
    connect(rightButton,&QPushButton::pressed,this,&MainWindow::rightButtonPressed);
    connect(expandButton,&QPushButton::pressed,this,&MainWindow::expandButtonPressed);
    connect(shrinkButton,&QPushButton::pressed,this,&MainWindow::shrinkButtonPressed);
    connect(resetButton,&QPushButton::pressed,this,&MainWindow::resetButtonPressed);
    connect(videoStartButton,&QPushButton::pressed,this,&MainWindow::videoStartButtonClicked);
    connect(this,&MainWindow::move,renderarea,&RenderArea::moveCursor);

}

void MainWindow::upButtonPressed()
{
    qDebug() << "up";
    emit move(QPoint(0,-10), 0);
}

void MainWindow::downButtonPressed()
{
    qDebug() << "down";
    emit move(QPoint(0,10), 0);
}

void MainWindow::leftButtonPressed()
{
    qDebug() << "left";
    emit move(QPoint(-10,0), 0);
}

void MainWindow::rightButtonPressed()
{
    qDebug() << "right";
    emit move(QPoint(10,0), 0);
}

void MainWindow::expandButtonPressed()
{
    qDebug() << "expand";
    emit move(QPoint(0,0), +10);
}

void MainWindow::shrinkButtonPressed()
{
    qDebug() << "shrink";
    emit move(QPoint(0,0), -10);
}

void MainWindow::resetButtonPressed()
{
    qDebug() << "reset";
    renderarea->cursorDefalut();
    renderarea->update();
}

void MainWindow::videoStartButtonClicked()
{
    qDebug() << "videoStart";
    renderarea->videoCapture();
}
