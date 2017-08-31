#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <QUndoCommand>
#include <QStack>
#include <QUndoStack>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QtNetwork>
#include <QBuffer>
#include <QToolBar>
#include <QThread>
#include <QPalette>
#include <QStackedWidget>
#include <QtWidgets>
#include <QCameraViewfinder>
#include <QFileDialog>
#include <QCameraExposureControl>
#include <QTimer>
#include <delayform.h>
#include <QTime>
#include <editingtools.h>
#include <smtp.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setCamera(const QByteArray &stream);

    //camera methods
    void startCamera();
    void cameraOn();
    void cameraOff();

    //start a delay
    void startDelay(int seconds);

    //undo methods
    void undo();
    void pushToUndoStack(QImage img);
    void redo();
    void pushToRedoStack(QImage img);

    //open delay widget
    void showDelayForm();

    //open new image
    void openImage();

    //tools
    void on_chkInvert_clicked();
    void on_chkGray_clicked();

    //save & display
    void saveImage();

    //save image in frame
    void saveCaptured(int i ,QImage img);

    //capture image in frame
    void captureImage();

    //return image
    QImage getImage();

    //update image in frame after using editing tools
    void updateDisplay();
    void displayBrightness();
    void displayRed();
    void displayGreen();
    void displayBlue();
    void on_chkMirror_clicked();
    void on_actionMail_triggered();

    //email sent confirmatiom
    void confirmEmail();

private:
    Ui::MainWindow *ui;

    //global image variable, passed around between editing tools, widgets and stacks
    QImage image ;
    QImage img;
    QStack<QImage> undo_Stack;
    QStack<QImage> redo_Stack;

    //camera instance
    QCamera *camera;

    //viewfinder for camera within stacked widget
    QCameraViewfinder *viewFinder;
    QToolBar *toolBar;

    //editing tools class instance
    editingTools *tool;
    QCameraImageProcessing *imageProcessing;
    QPixmap *lblPixmap;
    QCameraImageCapture *imageCapture;

    //smtp class instance
    smtp *m_smtp;

    //delay widget instance
    delayForm *delay;

    //QTimer instance
    QTimer *countdown;

    //global file paths
    QString resourceFilePath;
    QString captureFilePath;

    bool isOn;
};
#endif // MAINWINDOW_H
