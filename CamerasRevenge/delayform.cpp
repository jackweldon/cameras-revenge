#include "delayform.h"
#include "ui_delayform.h"

delayForm::delayForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delayForm)
{
    ui->setupUi(this);

    //delete from memory
    setAttribute(Qt::WA_DeleteOnClose);

    //connect for dial and lcddisplay
    connect(ui->dialSeconds,SIGNAL(valueChanged(int)),this,SLOT(timeChanged(int)));
    connect(this,SIGNAL(setSeconds(int)),ui->dialSeconds,SLOT(setValue(int)));

    //connect for buttons
    connect(ui->btnOK,SIGNAL(clicked()),this,SLOT(getDelay()));
    connect(ui->btnCancel,SIGNAL(clicked()),this,SLOT(close()));

}

delayForm::~delayForm()
{
    delete ui;
}

void delayForm::getDelay(){
    //emit value of delay
    emit setSeconds(delay);
    //close widget
    this->close();

}

void delayForm::timeChanged(int seconds)
{
    //prevent infinite loop
    if(delay==seconds)
        return;

     delay=seconds;

}
