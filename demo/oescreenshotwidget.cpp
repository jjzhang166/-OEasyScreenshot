#include "oescreenshotwidget.h"

#include <QPushButton>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

#include "oescreenshot.h"
#include "qxt/qxtglobalshortcut.h"


OEScreenshotWidget::OEScreenshotWidget(QWidget *parent) : QWidget(parent),
    openScreenshotButton_(new QPushButton(this)) {
    openScreenshotButton_->setGeometry(0,0,300,300);
    openScreenshotButton_->setObjectName("OpenScreenshotButton");
    openScreenshotButton_->show();
    openScreenshotButton_->setText("单击我\n\n快捷键( Shift+A )");

    QxtGlobalShortcut* shortcut = new QxtGlobalShortcut(QKeySequence("Shift+A"), this);
    connect(shortcut, SIGNAL(activated()),
            this, SLOT(onScreenshot()));
    connect(openScreenshotButton_.get(), SIGNAL(clicked()),
            this, SLOT(onScreenshot()));
}

void OEScreenshotWidget::onScreenshot()
{
    OEScreenshot::Instance();
}
