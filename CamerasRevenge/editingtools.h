#ifndef EDITINGTOOLS_H
#define EDITINGTOOLS_H
#include <QImage>
#include <QColor>

/*
 *class that contains methods for the tools from the mainwindow view
 * */

class editingTools
{
public:
    editingTools();

    //pass in value of red RBG value and image which values will change and return altered image
    QImage adjustRed(int val,QImage image);

    //pass in value of green RBG value and image which values will change and return altered image
    QImage adjustGreen(int val,QImage image);

    //pass in value of blue RBG value and image which values will change and return altered image
    QImage adjustBlue(int val,QImage image);

    //pass in value of RBG value sand image which values will change and return altered image
    QImage adjustBrightness(int val,QImage image);

    //pass in image to convert to grayscale and return converted image
    QImage greyScale(QImage image);

    //pass in image to mirror and return converted image
    QImage mirror(QImage image);

    //pass in image to invert and return converted image
    QImage invert(QImage image);
};

#endif // EDITINGTOOLS_H
