/*
Copyright [2017] [LuYong Chen]

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include "oerect.h"
#include <QPainter>
#ifndef QT_NO_DEBUG
#include <QDebug>
#endif
#include "oecommonhelper.h"
OERect::OERect(QWidget *parent) : QWidget(parent) {
    backgroundPixmap_ = new QPixmap(width(),height());
    backgroundPixmap_->fill((QColor(8, 8, 8, 160)));

    setFixedSize(95 * OECommonHelper::getWindowWidthMultiplyingPower(),
                 20 * OECommonHelper::getWindowHeightMultiplyingPower());
    hide();
}


void OERect::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(rect(),*backgroundPixmap_);
    painter.setPen(QPen(QColor(Qt::white)));
    painter.drawText(rect(), Qt::AlignCenter, info_);
}

void OERect::onPostionChange(int x, int y) {
    const int& ry = y - height();
    if (ry < 0) {
        this->raise();
    }
    move(x, ((ry < 0) ? y : ry));
}

void OERect::onSizeChange(int w, int h) {
    info_ = QString("%1 × %2").arg(w).arg(h);
}
