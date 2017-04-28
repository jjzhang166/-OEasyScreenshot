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

  In the oschina source download:

    https://git.oschina.net/Mr_ChenLuYong/screenshot

*/


#ifndef COMMONHELPER_H
#define COMMONHELPER_H
#include <QString>
#include <QRect>

class QWidget;
class OECommonHelper
{
public:
    /**
    * setStyle
    * 功能：设置QSS文件
    * 参数：style 文件名
    * 作者：陈鲁勇
    * 日期：2017年04月10日
    **/
    static void setStyle(const QString &style);
    /**
    * setLanguagePack
    * 功能：设置语言包
    * 参数：language 语言包的文件名
    * 作者：陈鲁勇
    * 日期：2017年04月10日
    **/
    static void setLanguagePack(const QString& language);
    /**
    * moveCenter
    * 功能：将窗口移动到中心
    * 参数：widget 要移动的窗口
    * 参数：parentRect 矩形几何数据
    * 作者：陈鲁勇
    * 日期：2017年04月10日
    **/
    static void moveCenter(QWidget* widget, QRect parentRect = {});

    /**
    * getWindowWidthMultiplyingPower
    * 功能：获得当前界面与开发时的界面之间的横向倍率
    * 返回：float 倍率
    * 作者：陈鲁勇
    * 日期：2017年04月10日
    **/
    static const float& getWindowWidthMultiplyingPower(void);
    /**
    * 函数名：getWindowHeightMultiplyingPower
    * 功能：获得当前界面与开发时的界面之间的纵向倍率
    * 返回：float 倍率
    * 作者：陈鲁勇
    * 日期：2017年04月10日
    **/
    static const float& getWindowHeightMultiplyingPower(void);

protected:
    /**
    * 函数名：upWindowSizeMultiplyingPower
    * 功能：更新窗口倍率
    * 作者：陈鲁勇
    * 日期：2017年04月10日
    **/
    static void upWindowSizeMultiplyingPower(void);

private:
    static float widthMultiplyingPower_;
    static float heightMultiplyingPower_;
};

#endif // COMMONHELPER_H
