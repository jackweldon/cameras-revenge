/********************************************************************************
** Form generated from reading UI file 'delayform.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELAYFORM_H
#define UI_DELAYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_delayForm
{
public:
    QLabel *label;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QDial *dialSeconds;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *delayForm)
    {
        if (delayForm->objectName().isEmpty())
            delayForm->setObjectName(QStringLiteral("delayForm"));
        delayForm->resize(348, 255);
        label = new QLabel(delayForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 291, 21));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        btnOK = new QPushButton(delayForm);
        btnOK->setObjectName(QStringLiteral("btnOK"));
        btnOK->setGeometry(QRect(240, 210, 75, 23));
        btnCancel = new QPushButton(delayForm);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(20, 200, 75, 23));
        dialSeconds = new QDial(delayForm);
        dialSeconds->setObjectName(QStringLiteral("dialSeconds"));
        dialSeconds->setGeometry(QRect(20, 30, 301, 181));
        dialSeconds->setMinimum(1);
        dialSeconds->setMaximum(5);
        lcdNumber = new QLCDNumber(delayForm);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(140, 90, 51, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lcdNumber->setFont(font1);
        lcdNumber->setFrameShape(QFrame::NoFrame);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setDigitCount(5);
        lcdNumber->setProperty("value", QVariant(0));

        retranslateUi(delayForm);
        QObject::connect(dialSeconds, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(delayForm);
    } // setupUi

    void retranslateUi(QWidget *delayForm)
    {
        delayForm->setWindowTitle(QApplication::translate("delayForm", "Form", 0));
        label->setText(QApplication::translate("delayForm", "Please Enter Delay Time (seconds)", 0));
        btnOK->setText(QApplication::translate("delayForm", "OK", 0));
        btnCancel->setText(QApplication::translate("delayForm", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class delayForm: public Ui_delayForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELAYFORM_H
