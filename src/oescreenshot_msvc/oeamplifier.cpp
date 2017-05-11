/**
 * @author : ��³��
 * @date   : 2017��04��
 * @version: 1.0
 * @note   : ���� Apache ���֤ 2.0 �棨���¼�ơ����֤������Ȩ;
 *           �������ر���ɣ�����������ʹ������ļ���
 * @remarks: �����Ի�ø���ɵĸ�����
 *           http://www.apache.org/licenses/LICENSE-2.0
 *           �������÷�����Ҫ��������ͬ�⣬������ɷַ������
 *           Ҫ����ԭ�����ַ���û���κ���ʽ�ģ���ȷ�������ĵ������
 *           �μ����ձ���ɿ������Ȩ�޼����Ƶ��ض����Ե����֤��
 *
 *   ����Ի�øô�������°汾��
 *
 *        https://git.oschina.net/Mr_ChenLuYong/screenshot
 *
 *   ��Դ�����������˶��ڴ�����Ĺ�ͬά����
 *
 *
 *   ��������Щ���뻹�в����ĵط�����ͨ�����µ����½���ѧϰ��
 *
 *        ���͵�ַ��http://blog.csdn.net/csnd_ayo
 *
 *        ���µ�ַ��http://blog.csdn.net/csnd_ayo/article/details/70197915
 *
 * 	 �ڴ����ύBug����ӭIssues��
 *
*/



#include "oeamplifier.h"


#include <QPixmap>
#include <QPainter>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif


#include "oecommonhelper.h"

OEAmplifier::OEAmplifier(std::shared_ptr<QPixmap> originPainting, QWidget *parent) :
    QWidget(parent), originPainting_(originPainting) {
    /// ���ó��ޱ߿�Ի���
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint);
    /// �������ʵʱ׷��
    setMouseTracking(true);

    /// ����Ĭ�ϴ�С
    sideLength_ = 122 * OECommonHelper::getWindowHeightMultiplyingPower();
    imageHeight_ = 90 * OECommonHelper::getWindowHeightMultiplyingPower();
    setFixedSize(sideLength_,sideLength_);

    /// Ĭ������
    hide();
}

void OEAmplifier::onSizeChange(int w, int h) {
    screenSize_ = QSize(w, h);
}

void OEAmplifier::onPostionChange(int x, int y) {
    cursorPoint_ = QPoint(x, y);
    raise();
    int dest_x = x + 4;
    int dest_y = y + 26;

    /// ������Ļ���
    const QSize& parent_size = parentWidget()->size();
    if (dest_y + height() > parent_size.height()) {
        dest_y = y - 26 - height();
    }
    if (dest_x + width() > parent_size.width()) {
        dest_x = x - 4 - width();
    }

    move(dest_x, dest_y);
}



/// ���������קʱѡ�����ε����¶���ķŴ�ͼ;
void OEAmplifier::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    /// ���Ʊ���
    painter.fillRect(rect(), QColor(0, 0, 0, 160));

    QPixmap endPointImage;
    /// ���ƷŴ�ͼ;
    const QSize& parent_size = parentWidget()->size();
    /**
     * @bug   : ����Ļ��Ե���ƷŴ�ͼʱ�����ͼƬ����
     *          ������ʱ���˱�Ե��⣬������Ļ��Ե�򲻽��зŴ�ͼ�Ļ��ƣ���QQ��ͼ�Ĳ�ȡ��ʽ��һ�µġ�
     *
     * @marker: ��ɫ��������ʶ�𣬵��Ǿֲ��Ŵ��Ч����ʱ����
     *
     * @note  : ������������Է��ֱ�Եʱ�������ܷŴ�ĵط�������棬������ɫ���Ա���ͼƬ����Ԥ�ڵ��������⡣
     */
    if ((cursorPoint_.x() + 15 < parent_size.width() && cursorPoint_.x() - 15 > 0)
      && (cursorPoint_.y() + 11 < parent_size.height() && cursorPoint_.y() - 11 > 0)) {
        endPointImage = originPainting_->
                copy(QRect(cursorPoint_.x() - 15,
                     cursorPoint_.y() - 11, 30, 22))
                .scaled(sideLength_, imageHeight_);
        painter.drawPixmap(0,0, endPointImage);
    }
    else {
        endPointImage = originPainting_->
                copy(QRect(cursorPoint_.x() - 15,
                     cursorPoint_.y() - 11, 30, 22));
    }


    /// ����ʮ��
    painter.setPen(QPen(QColor(0, 180, 255 , 180), 4));
    // ����;
    painter.drawLine(QPoint(sideLength_ >> 1, 0),
                     QPoint(sideLength_ >> 1,
                            imageHeight_ - 4));
    // ����;
    painter.drawLine(QPoint(0, imageHeight_ >> 1),
                     QPoint(sideLength_,
                            imageHeight_ >> 1));

    /// ���ƴ�ͼ�ڱ߿�
    painter.setPen(QPen(Qt::white, 2));
    painter.drawRect(2,2,width()-4, imageHeight_-4);

    /// ������߿�
    painter.setPen(QPen(Qt::black, 1));
    painter.drawRect(0,0,width()-1,height()-1);

    /// ��ǰѡ�о��εĿ����Ϣ;
    QString select_screen_info = QStringLiteral("%1��%2")
            .arg(screenSize_.width()).arg(screenSize_.height());

    /// ��ǰ�������ֵ��RGB��Ϣ
    QImage image = originPainting_->toImage();
    QColor cursor_pixel = image.pixel(cursorPoint_);
    QString select_pt_rgb = QStringLiteral("RGB:(%1,%2,%3)")
                                    .arg(cursor_pixel.red())
                                    .arg(cursor_pixel.green())
                                    .arg(cursor_pixel.blue());

    /// �����������������
    painter.setPen(Qt::white);
    painter.drawText(QPoint(6, imageHeight_+14),select_screen_info);
    painter.drawText(QPoint(6, imageHeight_+27),select_pt_rgb);
}
