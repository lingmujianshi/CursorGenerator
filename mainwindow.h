#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "renderarea.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private:
    RenderArea *renderarea;
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *expandButton;
    QPushButton *shrinkButton;
    QPushButton *resetButton;
    QPushButton *videoStartButton;

private slots:
    void upButtonPressed();
    void downButtonPressed();
    void leftButtonPressed();
    void rightButtonPressed();
    void expandButtonPressed();
    void shrinkButtonPressed();
    void resetButtonPressed();
    void videoStartButtonClicked();

signals:
    void move(QPoint shift, int r);
};

#endif // MAINWINDOW_H
