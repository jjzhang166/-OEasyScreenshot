#ifndef OEMODELVIEW_H
#define OEMODELVIEW_H

#include <QWidget>
#include <QMap>
#include <QColor>
#include <QPoint>

class OEModelView : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief : ģ������
    */
    enum MODEL{
        Arrows = 0, /// ��ͷ
        Rectangle = 1, /// ����
        Roundness /// Բ��
    };

private:
    typedef void (OEModelView::*PDRAWFUNC)
                (const QPoint &,const QPoint &, QPainter&);


signals:

public:
    explicit OEModelView(MODEL model = MODEL::Arrows,
                         QWidget *parent = 0);

protected:

    /**
     * @brief : �Ի��¼�
     */
    virtual void paintEvent(QPaintEvent *);

private:

    void drawArrows(const QPoint &startPoint,
                    const QPoint &endPoint,
                    QPainter& paiter);

public slots:

    void onColor(const QColor &color);

private:
    QColor color_;
    PDRAWFUNC drawFunc_;
    /// @bug  : Ī���������˴�����������������ͻ������
//    QPoint ssPoint331_;
//    QPoint esoint233_;
};


#endif // OEMODELVIEW_H
