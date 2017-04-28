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

#ifndef OERECT_H
#define OERECT_H

#include <QWidget>
#include <QRect>

class OERect : public QWidget
{
    Q_OBJECT

signals:


public:

    explicit OERect(QWidget *parent = 0);

protected:

    void paintEvent(QPaintEvent *);

public slots:
    void onPostionChange(int x, int y);
    void onSizeChange(int w, int h);

private:
    QPixmap* backgroundPixmap_;
    QString info_;
    QRect rect_;
};

#endif // OERECT_H
