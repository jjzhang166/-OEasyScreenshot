#include "oemodelview.h"

#include <QPen>
#include <QPainter>
#include <QPoint>
#include <QDebug>

/// @test : ���Ա���
QPoint startPoint_;
QPoint endPoint_;


OEModelView::OEModelView(MODEL model,
        QWidget *parent) : QWidget(parent),
        color_(Qt::red) {
    /// ȷ����ͼ��ʽ
    switch (model) {
    case MODEL::Arrows:
    {
        drawFunc_ = &OEModelView::drawArrows;
        break;
    }
    default:
    {
        drawFunc_ = &OEModelView::drawArrows;
    }
    }
}


void OEModelView::paintEvent(QPaintEvent *) {
    QPainter paiter(this);

    /// @test : ���Ա���
    startPoint_ = QPoint(width(),height());
    endPoint_ = {};

    /// ����ͼ��
    (this->*drawFunc_)(startPoint_, endPoint_, paiter);
}


void OEModelView::drawArrows(const QPoint& startPoint,
                             const QPoint& endPoint,
                             QPainter &paiter) {
    /// �����
    paiter.setRenderHint(QPainter::Antialiasing, true);
    /// ��������,���û�ˢ
    QPen pen;
    pen.setColor(color_);
    pen.setWidth(1);
    paiter.setPen(pen);
    paiter.setBrush(color_);


    /// ��ͷ���������ε�����
    double par = 15.0;
    double slopy = atan2((endPoint.y() - startPoint.y()),
                         (endPoint.x() - startPoint.x()));
    double cos_y = cos(slopy);
    double sin_y = sin(slopy);
    QPoint head_point1 = QPoint(endPoint.x() + int(-par*cos_y - (par / 2.0 * sin_y)),
                           endPoint.y() + int(-par*sin_y + (par / 2.0 * cos_y)));
    QPoint head_point2 = QPoint(endPoint.x() + int(-par*cos_y + (par / 2.0 * sin_y)),
                           endPoint.y() - int(par / 2.0*cos_y + par * sin_y));
    QPoint head_points[3] = { endPoint, head_point1, head_point2 };
    /// ���Ƽ�ͷ����
    paiter.drawPolygon(head_points, 3);


    /// ���������
    int offset_x = int(par*sin_y / 3);
    int offset_y = int(par*cos_y / 3);
    QPoint body_point1, body_point2;
    body_point1 = QPoint(endPoint.x() + int(-par*cos_y - (par / 2.0*sin_y)) +
                    offset_x, endPoint.y() + int(-par*sin_y + (par / 2.0*cos_y)) - offset_y);
    body_point2 = QPoint(endPoint.x() + int(-par*cos_y + (par / 2.0*sin_y) - offset_x),
                    endPoint.y() - int(par / 2.0*cos_y + par*sin_y) + offset_y);
    QPoint body_points[3] = { startPoint, body_point1, body_point2 };
    /// ���Ƽ�����
    paiter.drawPolygon(body_points, 3);

}
void OEModelView::onColor(const QColor &color) {
    color_ = color;
}
