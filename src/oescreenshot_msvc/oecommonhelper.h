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



#ifndef COMMONHELPER_H
#define COMMONHELPER_H
#include <QString>
#include <QRect>

class QWidget;

/**
 * @class : OECommonHelper
 * @brief : ͨ������
 * @note  : ���һЩ�Ƚϳ�����ͨ�õĹ���
 */
class OECommonHelper
{
public:

    /**
    * @brief : ����QSS�ļ�
    * @param : style �ļ���
    * @author: ��³��
    * @date  : 2017��04��10��
    * @remark: �����qrc·��������� qrc:/
    **/
    static void setStyle(const QString &style);

    /**
    * @brief : �������԰�
    * @param : language ���԰����ļ���
    * @author: ��³��
    * @date  : 2017��04��10��
    **/
    static void setLanguagePack(const QString& language);

    /**
    * @brief : �������ƶ�������
    * @param : widget Ҫ�ƶ��Ĵ���
    * @param : parentRect ���μ�������
    * @author: ��³��
    * @date  : 2017��04��10��
    **/
    static void moveCenter(QWidget* widget, QRect parentRect = {});


    /**
    * @brief : ��õ�ǰ�����뿪��ʱ�Ľ���֮��ĺ�����
    * @return: float ����
    * @author: ��³��
    * @date  : 2017��04��10��
    **/
    static const float& getWindowWidthMultiplyingPower(void);


    /**
    * @brief : ��õ�ǰ�����뿪��ʱ�Ľ���֮���������
    * @return: float ����
    * @author: ��³��
    * @date  : 2017��04��10��
    **/
    static const float& getWindowHeightMultiplyingPower(void);


    /**
    * @brief : ��õ�ǰ���λ����С���Ӵ���
    * @param : out_rect ���� (����)
    * @return: �ɹ�:true
    * @author: ��³��
    * @date  : 2017��04��10��
    **/
    static bool getSmallestWindowFromCursor(QRect &out_rect);

    /**
    * @brief : ��õ�ǰ���λ�õĴ���
    * @param : out_rect ���� (����)
    * @return: �ɹ�:true
    * @author: ��³��
    * @date  : 2017��04��10��
    **/
    static bool getCurrentWindowFromCursor(QRect &out_rect);

protected:

    /**
    * @brief : ���´��ڱ���
    * @author: ��³��
    * @date  : 2017��04��10��
    **/
    static void upWindowSizeMultiplyingPower(void);


private:
    /// ���ں�����
    static float widthMultiplyingPower_;
    /// ����������
    static float heightMultiplyingPower_;
};

#endif /// COMMONHELPER_H
