/********************************************************************************
** Form generated from reading UI file 'smtp.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMTP_H
#define UI_SMTP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_smtp
{
public:
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *editReciepient;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *editAtttach;
    QPushButton *btnAttach;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *editSubject;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QPlainTextEdit *textBody;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnExit;
    QPushButton *btnSend;

    void setupUi(QWidget *smtp)
    {
        if (smtp->objectName().isEmpty())
            smtp->setObjectName(QStringLiteral("smtp"));
        smtp->resize(493, 409);
        formLayout = new QFormLayout(smtp);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(smtp);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        editReciepient = new QLineEdit(smtp);
        editReciepient->setObjectName(QStringLiteral("editReciepient"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        editReciepient->setFont(font);

        horizontalLayout_3->addWidget(editReciepient);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(smtp);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        editAtttach = new QLineEdit(smtp);
        editAtttach->setObjectName(QStringLiteral("editAtttach"));
        editAtttach->setFont(font);

        horizontalLayout_4->addWidget(editAtttach);

        btnAttach = new QPushButton(smtp);
        btnAttach->setObjectName(QStringLiteral("btnAttach"));

        horizontalLayout_4->addWidget(btnAttach);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(smtp);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);

        editSubject = new QLineEdit(smtp);
        editSubject->setObjectName(QStringLiteral("editSubject"));
        editSubject->setFont(font);

        horizontalLayout_5->addWidget(editSubject);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(smtp);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        textBody = new QPlainTextEdit(smtp);
        textBody->setObjectName(QStringLiteral("textBody"));
        textBody->setFont(font);

        horizontalLayout_6->addWidget(textBody);


        formLayout->setLayout(3, QFormLayout::LabelRole, horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        btnExit = new QPushButton(smtp);
        btnExit->setObjectName(QStringLiteral("btnExit"));

        horizontalLayout_7->addWidget(btnExit);

        btnSend = new QPushButton(smtp);
        btnSend->setObjectName(QStringLiteral("btnSend"));

        horizontalLayout_7->addWidget(btnSend);


        formLayout->setLayout(4, QFormLayout::LabelRole, horizontalLayout_7);


        retranslateUi(smtp);

        QMetaObject::connectSlotsByName(smtp);
    } // setupUi

    void retranslateUi(QWidget *smtp)
    {
        smtp->setWindowTitle(QApplication::translate("smtp", "Form", 0));
        label_3->setText(QApplication::translate("smtp", "Recipients E-Mail Address", 0));
        editReciepient->setText(QString());
        label_4->setText(QApplication::translate("smtp", "Attachment", 0));
        editAtttach->setText(QString());
        btnAttach->setText(QApplication::translate("smtp", "Browse", 0));
        label_5->setText(QApplication::translate("smtp", "Subject", 0));
        editSubject->setText(QString());
        label_6->setText(QApplication::translate("smtp", "Body", 0));
        btnExit->setText(QApplication::translate("smtp", "Exit", 0));
        btnSend->setText(QApplication::translate("smtp", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class smtp: public Ui_smtp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMTP_H
