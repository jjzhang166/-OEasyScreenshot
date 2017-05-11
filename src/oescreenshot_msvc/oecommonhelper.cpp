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


#include "oecommonhelper.h"

#include <QFile>
#include <QTranslator>
#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>

#include <windows.h>

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif


#define WINDOW_BASESIZE_WIDTH (1920)
#define WINDOW_BASESIZE_HEIGHT (1080)

float OECommonHelper::widthMultiplyingPower_ = 0;
float OECommonHelper::heightMultiplyingPower_ = 0;

void OECommonHelper::setStyle(const QString &style) {
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

void OECommonHelper::setLanguagePack(const QString &language) {
    // �������İ�
    QTranslator translator;
    translator.load(language);
    qApp->installTranslator(&translator);
}

void OECommonHelper::moveCenter(QWidget *widget, QRect parentRect) {
    if (parentRect.isEmpty()) {
        parentRect = QApplication::desktop()->rect();
    }
    widget->move (((parentRect.width() - widget->width()) >> 1),
          ((parentRect.height() - widget->height()) >> 1));
}

const float &OECommonHelper::getWindowWidthMultiplyingPower() {
    if (widthMultiplyingPower_ == 0) {
        upWindowSizeMultiplyingPower();
    }
    return widthMultiplyingPower_;
}

const float & OECommonHelper::getWindowHeightMultiplyingPower() {
    if (heightMultiplyingPower_ == 0) {
        upWindowSizeMultiplyingPower();
    }
    return heightMultiplyingPower_;
}

void OECommonHelper::upWindowSizeMultiplyingPower() {
   QSize temp_size = QApplication::desktop()->size();
   widthMultiplyingPower_ = (float)temp_size.width()
           / (float)WINDOW_BASESIZE_WIDTH;
   heightMultiplyingPower_ = (float)temp_size.height()
           / (float)WINDOW_BASESIZE_HEIGHT;
}

bool OECommonHelper::getSmallestWindowFromCursor(QRect& out_rect) {
    HWND hwnd;
    POINT pt;
    // ��õ�ǰ���λ��
    ::GetCursorPos(&pt);
    // ��õ�ǰλ�������ϵ��Ӵ���
    hwnd = ::ChildWindowFromPointEx(::GetDesktopWindow(), pt, CWP_SKIPDISABLED | CWP_SKIPINVISIBLE);
    if (hwnd != NULL) {
        HWND temp_hwnd;
        temp_hwnd = hwnd;
        while (true) {
            ::GetCursorPos(&pt);
            ::ScreenToClient(temp_hwnd, &pt);
            temp_hwnd = ::ChildWindowFromPointEx(temp_hwnd, pt, CWP_SKIPINVISIBLE);
            if (temp_hwnd == NULL || temp_hwnd == hwnd)
                break;
            hwnd = temp_hwnd;
        }
        RECT temp_window;
        ::GetWindowRect(hwnd, &temp_window);
        out_rect.setRect(temp_window.left,temp_window.top,
                         temp_window.right - temp_window.left,
                         temp_window.bottom - temp_window.top);
        return true;
    }
    return false;
}

bool OECommonHelper::getCurrentWindowFromCursor(QRect &out_rect)
{
    HWND hwnd;
    POINT pt;
    // ��õ�ǰ���λ��
    ::GetCursorPos(&pt);
    // ��õ�ǰλ�������ϵ��Ӵ���
    hwnd = ::ChildWindowFromPointEx(::GetDesktopWindow(), pt, CWP_SKIPDISABLED | CWP_SKIPINVISIBLE);
    if (hwnd != NULL) {
        RECT temp_window;
        ::GetWindowRect(hwnd, &temp_window);
        out_rect.setRect(temp_window.left, temp_window.top,
                         temp_window.right - temp_window.left,
                         temp_window.bottom - temp_window.top);
        return true;
    }
    return false;
}
