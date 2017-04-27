#include "commonhelper.h"

#include <QFile>
#include <QTranslator>
#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif


#define WINDOW_BASESIZE_WIDTH (1920)
#define WINDOW_BASESIZE_HEIGHT (1080)

float CommonHelper::widthMultiplyingPower_ = 0;
float CommonHelper::heightMultiplyingPower_ = 0;

void CommonHelper::setStyle(const QString &style)
{
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

void CommonHelper::setLanguagePack(const QString &language)
{
    // 加载中文包
    QTranslator translator;
    translator.load(language);
    qApp->installTranslator(&translator);
}

void CommonHelper::moveCenter(QWidget *widget, QRect parentRect)
{
    if (parentRect.isEmpty()) {
        parentRect = QApplication::desktop()->rect();
    }
    widget->move (((parentRect.width() - widget->width()) >> 1),
          ((parentRect.height() - widget->height()) >> 1));
}

const float &CommonHelper::getWindowWidthMultiplyingPower()
{
    if (widthMultiplyingPower_ == 0) {
        upWindowSizeMultiplyingPower();
    }
    return widthMultiplyingPower_;
}

const float & CommonHelper::getWindowHeightMultiplyingPower()
{
    if (heightMultiplyingPower_ == 0) {
        upWindowSizeMultiplyingPower();
    }
    return heightMultiplyingPower_;
}

void CommonHelper::upWindowSizeMultiplyingPower()
{
   QSize temp_size = QApplication::desktop()->size();
   widthMultiplyingPower_ = (float)temp_size.width()
           / (float)WINDOW_BASESIZE_WIDTH;
   heightMultiplyingPower_ = (float)temp_size.height()
           / (float)WINDOW_BASESIZE_HEIGHT;
}
