#ifndef DELAYFORM_H
#define DELAYFORM_H

#include <QWidget>

/*
 * This is the .h file for the delay form class
 * emits a signal to parent class when closed
 * */

namespace Ui {
class delayForm;
}

class delayForm : public QWidget
{
    Q_OBJECT

public:
    explicit delayForm(QWidget *parent = 0);
    //destructor
    ~delayForm();



public slots:

     void timeChanged(int seconds);
      void getDelay();
private:
    Ui::delayForm *ui;
    int delay;

signals:
    void setSeconds(int);


};

#endif // DELAYFORM_H
