#include "editingtools.h"

editingTools::editingTools()
{

}

//pass in value of red RBG value and image which values will change

QImage editingTools::adjustRed(int value,QImage image){

    //copy image and convert for formatting
    QImage redImage = image.convertToFormat(QImage::Format_Indexed8);

    for(int i = 0; i < redImage.colorCount(); i++){

        QRgb col = redImage.color(i);

        int r = 0;
        int g = 0;
        int b = 0;
        int a =0;

        int *pr = &r;
        int *pg = &g;
        int *pb=  &b;
        int *pa = &a;


        QColor(col).getRgb(pr,pg,pb,pa);
        //change r value
        int e = qBound<int>(0, *pr+value *255/100,255);

        col = qRgb(e,g,b);

        redImage.setColor(i,col);
    }
    //returned altered image
    return redImage;

}

QImage editingTools::adjustBrightness(int value,QImage image){

    QImage brightenedImage = image.convertToFormat(QImage::Format_Indexed8);

    for(int i = 0; i < brightenedImage.colorCount(); i++){

        QRgb col = brightenedImage.color(i);

        int r = 0;
        int g = 0;
        int b = 0;
        int a =0;

        int *pr = &r;
        int *pg = &g;
        int *pb=  &b;
        int *pa = &a;

        QColor(col).getRgb(pr,pg,pb,pa);
        int e = qBound<int>(0, *pr+value *255/100,255);
        int f = qBound<int>(0, *pg+value *255/100,255);
        int h = qBound<int>(0, *pb+value *255/100,255);

        col = qRgb(e,f,h);

        brightenedImage.setColor(i,col);
    }

    return brightenedImage;

}

QImage editingTools::adjustBlue(int value,QImage image){

    QImage blueImage = image.convertToFormat(QImage::Format_Indexed8);

    for(int i = 0; i < blueImage.colorCount(); i++){

        QRgb col = blueImage.color(i);

        int r = 0;
        int g = 0;
        int b = 0;
        int a = 0;

        int *pr = &r;
        int *pg = &g;
        int *pb=  &b;
        int *pa = &a;


        QColor(col).getRgb(pr,pg,pb,pa);

        int h = qBound<int>(0, *pb+value *255/100,255);

        col = qRgb(r,g,h);

        blueImage.setColor(i,col);
    }
    return blueImage;

}

QImage editingTools::adjustGreen(int value,QImage image){

    QImage greenImage = image.convertToFormat(QImage::Format_Indexed8);

    for(int i = 0; i < greenImage.colorCount(); i++){

        QRgb col = greenImage.color(i);

        int r = 0;
        int g = 0;
        int b = 0;
        int a = 0;

        int *pr = &r;
        int *pg = &g;
        int *pb=  &b;
        int *pa = &a;


        QColor(col).getRgb(pr,pg,pb,pa);

        int f = qBound<int>(0, *pg+value *255/100,255);

        col = qRgb(r,f,b);

        greenImage.setColor(i,col);
    }
    return greenImage;

}

QImage editingTools::greyScale(QImage image){

    if(!image.isNull())
        return image.convertToFormat(QImage::Format_Mono);

}

QImage editingTools::mirror(QImage image){

    return image.mirrored(true,false);

}

QImage editingTools::invert(QImage image){

    image.invertPixels(QImage::InvertRgba);
    return image;

}
