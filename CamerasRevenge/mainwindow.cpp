#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <editingtools.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    camera(0),
    imageProcessing(0),
    imageCapture(0)

{
    //check for cameras, if none turn camea off
    if(QCamera::availableDevices().isEmpty()){
        printf("%s","No camera devices");
        cameraOff();
        ui->actionStart->setEnabled(false);

    }
    else
    {
    //set up camera and ui
    isOn=true;
    ui->setupUi(this);
    QByteArray stream;
    setCamera(stream);
    imageCapture = new QCameraImageCapture(camera);
    }

    // connect action button signals to slots
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveImage()));
    connect(ui->actionStart,SIGNAL(triggered()),this,SLOT(startCamera()));
    connect(ui->actionCapture,SIGNAL(triggered()),this,SLOT(captureImage()));
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openImage()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionDelay,SIGNAL(triggered()),this,SLOT(showDelayForm()));
    connect(ui->actionUndo,SIGNAL(triggered()),this,SLOT(undo()));
    connect(ui->actionRedo,SIGNAL(triggered()),this,SLOT(redo()));

     //connnect sliders to slots for editing image in frame
     connect(ui->brightnessSlider,SIGNAL(valueChanged(int)),this,SLOT(displayBrightness()));
     connect(ui->sliderBlue,SIGNAL(valueChanged(int)),this,SLOT(displayBlue()));
     connect(ui->greenSlider,SIGNAL(valueChanged(int)),this,SLOT(displayGreen()));
     connect(ui->redSlider,SIGNAL(valueChanged(int)),this,SLOT(displayRed()));

    //when each slider is released, repaint current frame with edited image
     connect(ui->brightnessSlider,SIGNAL(sliderReleased()),this,SLOT(updateDisplay()));
     connect(ui->sliderBlue,SIGNAL(sliderReleased()),this,SLOT(updateDisplay()));
     connect(ui->greenSlider,SIGNAL(sliderReleased()),this,SLOT(updateDisplay()));
     connect(ui->redSlider,SIGNAL(sliderReleased()),this,SLOT(updateDisplay()));

    //connect imageCapture
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(saveCaptured(int,QImage)));

    //setFilePaths
    captureFilePath=QDir::currentPath();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * SLOT
 * Called when the action delay button is triggered
 * creates a new instance of Delayform and shows the UI for the instance
 * then recives a SIGNAL from the delay for how long the delay will be  as an int between 1-5
 * the delay is then passed to the startDelay METHOD
 * */
void MainWindow::showDelayForm(){

        delay= new delayForm();
        delay->show();
        //connect to widget delayForm
        connect(delay,SIGNAL(setSeconds(int)),this,SLOT(startDelay(int)));
}
/*
 * METHOD
 * recives seconds as a parameter and uses the QTimer class to create a delay
 * before calling the captureImage() SLOT
 * */
void MainWindow::startDelay(int seconds){

    QTimer::singleShot(seconds*1000, this, SLOT(captureImage()));

}
/*
 * METHOD
 * Sets the camera passing in the stream to use
 * checks if the stream is empty and displays the new/exsisting stream
 * onto the camera widget which is on the stacked widget
 * */
void MainWindow::setCamera(const QByteArray &stream){

    delete camera;

    if (stream.isEmpty())
        camera = new QCamera;
    else
        camera = new QCamera(stream);

    camera->setViewfinder(ui->cameraWidget);
    camera->start();
    cameraOn();
    ui->stackedWidget->setCurrentWidget(ui->cameraWidget);
}
/*
 * METHOD
 * Is used to toggel the boolean state of the camera and initate the camera
 * when the program is opened
 * */
void MainWindow::startCamera()
{
    if(isOn ==true){
        cameraOff();
        isOn=false;
    }
    else{
        cameraOn();
        isOn=true;
    }
}
/*
 * METHOD
 * This METHOD controls the state of the programme when the camera is on
 * changing which buttons are enabled and what should be displayed
 * */
void MainWindow::cameraOn(){

    QPixmap pixmapStop(":/Icons/Resource/stop.png");
    QIcon stopIcon(pixmapStop);

    ui->actionStart->setText("Stop");

    ui->actionStart->setIcon(stopIcon);
    ui->actionCapture->setEnabled(true);
    ui->actionSave->setEnabled(false);
    ui->actionDelay->setEnabled(true);

    ui->chkGray->setEnabled(false);
    ui->chkInvert->setEnabled(false);
    ui->chkMirror->setEnabled(false);

    ui->chkGray->setChecked(false);
    ui->chkInvert->setChecked(false);
    ui->chkMirror->setChecked(false);

    ui->stackedWidget->setCurrentWidget(ui->cameraWidget);

    isOn = true;
}
/*
 * This METHOD controls the state of the programme when the camera is off
 * changing which buttons are enabled and what should be displayed
 * */
void MainWindow::cameraOff(){

    QPixmap pixmapStart(":/Icons/Resource/start.png");
    QIcon startIcon(pixmapStart);

    ui->actionCapture->setEnabled(false);
    ui->actionSave->setEnabled(true);
    ui->actionStart->setText("Start");
    ui->actionStart->setIcon(startIcon);
    ui->actionDelay->setEnabled(false);
    ui->chkGray->setEnabled(true);
    ui->chkInvert->setEnabled(true);
    ui->chkMirror->setEnabled(true);

    isOn = false;

    ui->stackedWidget->setCurrentWidget(ui->page);
}
/*
 * SLOT
 * Saves the images that is captured within the image label for editing
 * int i is unused but required
 * Qimage img is the passed in image being saved which is required when using the SIGNAL imageCaptured
 * from the qimagecapture.h file
 * */
void MainWindow::saveCaptured(int i, QImage img){

        Q_UNUSED(i);
        image = img;// sets global image as img in label
        image.save(captureFilePath);//save to file path

        image.scaled(ui->lblImage->size());

        ui->lblImage->setPixmap(QPixmap().fromImage(image));

}
/*
 * SLOT
 * This slot is called when the SIGNAL for the action camera is clicked
 * */
void MainWindow::captureImage()
{
    ui->actionSave->setEnabled(true);
    camera->setCaptureMode(QCamera::CaptureStillImage);

    imageCapture->capture();
    cameraOff();
}
/*
 * SLOT
 * Used when open image action button is clicked, opens a file dialog for the user
 * to select an image which is then diplayed in the lblImage
 * */
void MainWindow::openImage()
{
    cameraOff();

    ui->actionCapture->setEnabled(false);

    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open File"),QDir::currentPath(),"Image Files (*.png *.jpg *.bmp)");

    if(fileName!= NULL){

    image.load(fileName);
    image.scaled(ui->lblImage->size());

    ui->lblImage->setPixmap(QPixmap().fromImage(image));

    }
    else{

    }
}

/*
 * Returns current image of the class
 * */
QImage MainWindow::getImage(){
    return image;
}

/*
 * SLOT
 * opens a file dialog for the user o save the current image in the label
 * initiated when the action button for save is clicked
 * */
void MainWindow::saveImage()
{
   QString filePath= QFileDialog::getSaveFileName
    (this,"Save File",QDir::currentPath(),"Image Files (*.png *.jpg *.bmp)");

   if(filePath != NULL ){
    image.save(filePath);
   }else{
      printf("%s","Did Not Save");
   }
}

/*
 * SLOT
 * activated when check box inverted is clicked and uses the editingTools
 * check invert METHOD to invert the colours of the image within the label
 * */
void MainWindow::on_chkInvert_clicked()
{
    pushToUndoStack(image);

    image = tool->invert(image);//invert pixels

    ui->lblImage->setPixmap(QPixmap().fromImage(image));//convert back to qpixmap and display in label


}
/*
 * SLOT
 * activated when gray box inverted is clicked and uses the editingTools
 * check gray METHOD to grayscale the colours of the image within the label
 * */

void MainWindow::on_chkGray_clicked()
{
    pushToUndoStack(image);

    if(ui->chkGray->isChecked())
        image = tool->greyScale(image);

    ui->lblImage->setPixmap(QPixmap().fromImage(image));
}
/*
 * SLOT
 * Activated when the slider is clicked, calls a METHOD from editing tools to adjust the brightness using RGB
 * value of the current image in the label, which is passed in. The changes are then displayed in the label as they are changed
 * the changed value of the image is not changed until the slider is released, when updateDisplay() is called
 * */
void MainWindow::displayBrightness(){
    pushToUndoStack(image);

    img = tool->adjustBrightness(ui->brightnessSlider->value(),image);

    ui->lblImage->setPixmap(QPixmap().fromImage(img));
}
/*
 * SLOT
 * Activated when the slider is clicked, calls a METHOD from editing tools to adjust the Green using RGB
 * value of the current image in the label, which is passed in. The changes are then displayed in the label as they are changed
 * the changed value of the image is not changed until the slider is released, when updateDisplay() is called
 * */
void MainWindow::displayGreen(){
    pushToUndoStack(image);

    img = tool->adjustGreen(ui->greenSlider->value(),image);

    ui->lblImage->setPixmap(QPixmap().fromImage(img));
}
/*
 * SLOT
 * Activated when the slider is clicked, calls a METHOD from editing tools to adjust the blue using RGB
 * value of the current image in the label, which is passed in. The changes are then displayed in the label as they are changed
 * the changed value of the image is not changed until the slider is released, when updateDisplay() is called
 * */
void MainWindow::displayBlue(){
    pushToUndoStack(image);

    img = tool->adjustBlue(ui->sliderBlue->value(),image);

    ui->lblImage->setPixmap(QPixmap().fromImage(img));
}
/*
 * SLOT
 * Activated when the slider is clicked, calls a METHOD from editing tools to adjust the Red using RGB
 * value of the current image in the label, which is passed in. The changes are then displayed in the label as they are changed
 * the changed value of the image is not changed until the slider is released, when updateDisplay() is called
 * */
void MainWindow::displayRed(){

    pushToUndoStack(image);

    img = tool->adjustRed(ui->redSlider->value(),image);

    ui->lblImage->setPixmap(QPixmap().fromImage(img));


}
/*
 * SLOT
 * called when sliders are released to update the display the newly edited image
 * within the image label
 * */
void MainWindow::updateDisplay(){

    image=img;
    ui->lblImage->setPixmap(QPixmap().fromImage(image));
}

/*
 * METHOD
 * Called before any METHOD that changes the image within the label are started
 * pushes the image to the top of the undostack
 * */
void MainWindow::pushToUndoStack(QImage img){
    if(!img.isNull())
         undo_Stack.push(img);
}

/*
 * METHOD
 * Activated when undo METHOD is called
 * img is pushed to the top of the redostack
 * */
void MainWindow::pushToRedoStack(QImage img){
    if(!img.isNull())
         redo_Stack.push(img);
}
/*
 * SLOT
 * When action redo or ctrl+y is pressed, if the redo stack is not empty
 * it pops the last image on the stack and displays it within the image label
 * */
void MainWindow::redo(){

    if(!redo_Stack.empty()){
         pushToUndoStack(image);
        image = redo_Stack.pop();
        ui->lblImage->setPixmap(QPixmap().fromImage(image));

    }

}
/*
 * SLOT
 * When action undo or ctrl+z is pressed, if the undo stack is not empty
 * it pops the last image on the stack and displays it within the image label
 * */
void MainWindow::undo()
{
    if(!undo_Stack.empty()){
        pushToRedoStack(image);
        image = undo_Stack.pop();

        ui->lblImage->setPixmap(QPixmap().fromImage(image));
    }else{
    printf("%s","Stack is Empty");
    }
}
/*
 * SLOT
 * activated when mirrorbox inverted is clicked and uses the editingTools
 * check mirror METHOD to flip the image horizonatlly
 * */

void MainWindow::on_chkMirror_clicked()
{
    pushToUndoStack(image);
    img=   tool->mirror(image);
    image = img;
    ui->lblImage->setPixmap(QPixmap().fromImage(img));//convert back to qpixmap and display in label
}
/*
 * SLOT
 * activated when actionmail is triggered and creates and instance of SMTP and
 * opens a new SMTP window, when the email is sent from SMTP a signal is emitted and a confirm email dialog box is displayed
 * */
void MainWindow::on_actionMail_triggered()
{
    m_smtp= new smtp();
    m_smtp->show();

    connect(m_smtp,SIGNAL(complete(bool)),this,SLOT(confirmEmail()));

}
/*
 * METHOD
 * Opens a new Qmessga box to confirm an email has been sent
 * called within the actionmail slot
 * */
void MainWindow::confirmEmail(){
    QMessageBox::information(this,"Success","Message Sent",QMessageBox::Ok);

}
