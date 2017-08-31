/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcameraviewfinder.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionStart;
    QAction *actionOpen;
    QAction *actionCapture;
    QAction *actionDelay;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionMail;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QLabel *lblImage;
    QCameraViewfinder *cameraWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chkInvert;
    QCheckBox *chkMirror;
    QCheckBox *chkGray;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSlider *redSlider;
    QSlider *brightnessSlider;
    QVBoxLayout *verticalLayout_3;
    QLabel *lblBlue;
    QSlider *sliderBlue;
    QLabel *lblBright;
    QVBoxLayout *verticalLayout_4;
    QLabel *lblGreen;
    QSlider *greenSlider;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(885, 487);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/Resource/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setAutoFillBackground(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/Resource/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/Resource/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart->setIcon(icon2);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/Resource/folder_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon3);
        actionCapture = new QAction(MainWindow);
        actionCapture->setObjectName(QStringLiteral("actionCapture"));
        actionCapture->setIcon(icon);
        actionDelay = new QAction(MainWindow);
        actionDelay->setObjectName(QStringLiteral("actionDelay"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/Resource/timer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelay->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("Resource/Undo-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon5);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icons/Resource/Redo-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon6);
        actionMail = new QAction(MainWindow);
        actionMail->setObjectName(QStringLiteral("actionMail"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icons/Resource/mail.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMail->setIcon(icon7);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(391, 311));
        stackedWidget->setFrameShape(QFrame::HLine);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(page->sizePolicy().hasHeightForWidth());
        page->setSizePolicy(sizePolicy1);
        page->setMinimumSize(QSize(391, 311));
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lblImage = new QLabel(page);
        lblImage->setObjectName(QStringLiteral("lblImage"));
        lblImage->setEnabled(true);
        sizePolicy.setHeightForWidth(lblImage->sizePolicy().hasHeightForWidth());
        lblImage->setSizePolicy(sizePolicy);
        lblImage->setScaledContents(true);

        gridLayout_3->addWidget(lblImage, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        cameraWidget = new QCameraViewfinder();
        cameraWidget->setObjectName(QStringLiteral("cameraWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cameraWidget->sizePolicy().hasHeightForWidth());
        cameraWidget->setSizePolicy(sizePolicy2);
        cameraWidget->setMinimumSize(QSize(391, 311));
        stackedWidget->addWidget(cameraWidget);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        chkInvert = new QCheckBox(groupBox);
        chkInvert->setObjectName(QStringLiteral("chkInvert"));

        verticalLayout_2->addWidget(chkInvert);

        chkMirror = new QCheckBox(groupBox);
        chkMirror->setObjectName(QStringLiteral("chkMirror"));

        verticalLayout_2->addWidget(chkMirror);

        chkGray = new QCheckBox(groupBox);
        chkGray->setObjectName(QStringLiteral("chkGray"));

        verticalLayout_2->addWidget(chkGray);


        gridLayout->addLayout(verticalLayout_2, 7, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        redSlider = new QSlider(groupBox);
        redSlider->setObjectName(QStringLiteral("redSlider"));
        redSlider->setToolTipDuration(2);
        redSlider->setMinimum(-100);
        redSlider->setMaximum(100);
        redSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(redSlider, 5, 0, 1, 1);

        brightnessSlider = new QSlider(groupBox);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setMinimumSize(QSize(151, 19));
        brightnessSlider->setMinimum(-20);
        brightnessSlider->setMaximum(20);
        brightnessSlider->setPageStep(1);
        brightnessSlider->setSliderPosition(0);
        brightnessSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(brightnessSlider, 1, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        lblBlue = new QLabel(groupBox);
        lblBlue->setObjectName(QStringLiteral("lblBlue"));

        verticalLayout_3->addWidget(lblBlue);

        sliderBlue = new QSlider(groupBox);
        sliderBlue->setObjectName(QStringLiteral("sliderBlue"));
        sliderBlue->setMinimum(-100);
        sliderBlue->setMaximum(100);
        sliderBlue->setValue(0);
        sliderBlue->setSliderPosition(0);
        sliderBlue->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(sliderBlue);


        gridLayout->addLayout(verticalLayout_3, 2, 0, 1, 1);

        lblBright = new QLabel(groupBox);
        lblBright->setObjectName(QStringLiteral("lblBright"));
        lblBright->setMinimumSize(QSize(71, 16));

        gridLayout->addWidget(lblBright, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lblGreen = new QLabel(groupBox);
        lblGreen->setObjectName(QStringLiteral("lblGreen"));

        verticalLayout_4->addWidget(lblGreen);

        greenSlider = new QSlider(groupBox);
        greenSlider->setObjectName(QStringLiteral("greenSlider"));
        greenSlider->setMinimum(-100);
        greenSlider->setMaximum(100);
        greenSlider->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(greenSlider);


        gridLayout->addLayout(verticalLayout_4, 3, 0, 1, 1);


        verticalLayout->addWidget(groupBox);


        gridLayout_2->addWidget(widget, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 885, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionUndo);
        menuFile->addAction(actionRedo);
        menuFile->addAction(actionExit);
        mainToolBar->addAction(actionStart);
        mainToolBar->addAction(actionCapture);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionDelay);
        mainToolBar->addAction(actionMail);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CameraS ", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save Current Image", 0));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0));
        actionStart->setShortcut(QApplication::translate("MainWindow", "Enter", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open Image", 0));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionCapture->setText(QApplication::translate("MainWindow", "Capture", 0));
#ifndef QT_NO_TOOLTIP
        actionCapture->setToolTip(QApplication::translate("MainWindow", "Capture Image", 0));
#endif // QT_NO_TOOLTIP
        actionCapture->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionDelay->setText(QApplication::translate("MainWindow", "delay", 0));
#ifndef QT_NO_TOOLTIP
        actionDelay->setToolTip(QApplication::translate("MainWindow", "Delay Capture", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Esc", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("MainWindow", "Undo Last Image Edit", 0));
#endif // QT_NO_TOOLTIP
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0));
        actionMail->setText(QApplication::translate("MainWindow", "mail", 0));
#ifndef QT_NO_TOOLTIP
        actionMail->setToolTip(QApplication::translate("MainWindow", "EMail an image", 0));
#endif // QT_NO_TOOLTIP
        lblImage->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Effects", 0));
        chkInvert->setText(QApplication::translate("MainWindow", "Invert Colours", 0));
        chkMirror->setText(QApplication::translate("MainWindow", "Mirror Image", 0));
        chkGray->setText(QApplication::translate("MainWindow", "Gray Scale", 0));
        label->setText(QApplication::translate("MainWindow", "Red", 0));
        lblBlue->setText(QApplication::translate("MainWindow", "Blue", 0));
        lblBright->setText(QApplication::translate("MainWindow", "Brightness", 0));
        lblGreen->setText(QApplication::translate("MainWindow", "Green", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
#ifndef QT_NO_WHATSTHIS
        mainToolBar->setWhatsThis(QApplication::translate("MainWindow", "Delay the image cature", 0));
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
