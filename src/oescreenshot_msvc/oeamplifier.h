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



#ifndef OEAMPLIFIER_H
#define OEAMPLIFIER_H
#include <memory>
#include <QWidget>


/**
 * @class : OEAmplifier
 * @brief : �Ŵ�ȡɫ��
 * @note  : �������λ�þֲ��Ŵ�Ĳ����Լ�ɫ��ȡֵ�Ĳ���
 */
class OEAmplifier : public QWidget
{
    Q_OBJECT
public:
    explicit OEAmplifier(std::shared_ptr<QPixmap> originPainting, QWidget *parent = 0);

signals:

public slots:


    /**
     * @brief : ��С�޸�
     * @param : w ���
     * @param : h �߶�
     * @date  : 2017��4��29��
     */
    void onSizeChange(int w, int h);

    /**
     * @brief : ��С�޸�
     * @param : w ���
     * @param : h �߶�
     * @date  : 2017��4��29��
     */
    void onPostionChange(int x, int y);

protected:

    /**
     * @brief : �����Ի��¼�
     * @date  : 2017��4��29��
     */
    virtual void paintEvent(QPaintEvent *);

private:

    /// �ⲿ����Ĵ�С��Ϣ
    QSize screenSize_;
    /// ����λ��
    QPoint cursorPoint_;
    /// ȡɫ�Ŵ����ı߳�
    int sideLength_;
    /// �Ŵ����ĸ߶�
    int imageHeight_;
    /// ��Ļԭ��
    std::shared_ptr<QPixmap> originPainting_;

};

#endif /// OEAMPLIFIER_H
