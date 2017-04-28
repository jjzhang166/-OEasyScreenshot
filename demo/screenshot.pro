#版权所有 [2017] [瓯裔]

#   根据 Apache 许可证 2.0 版（以下简称“许可证”）授权；
#   除非遵守本许可，否则您不能使用这个文件。
#   您可以获得该许可的副本：

#        http://www.apache.org/licenses/LICENSE-2.0


#   除非适用法律需要或者书面同意，按本许可分发的软件
#   要按“原样”分发，没有任何形式的，明确或隐含的担保条款。
#   参见按照本许可控制许可权限及限制的特定语言的许可证。

#   你可以获得该代码的最新版本：

#        https://git.oschina.net/Mr_ChenLuYong/screenshot

#   开源社区的所有人都期待与你的共同维护。


#   如果你对这些代码还有不理解的地方可以通过最新的文章进行学习：

#        博客地址：http://blog.csdn.net/csnd_ayo

#        文章地址：http://blog.csdn.net/csnd_ayo/article/details/70197915

#	期待你提交Bug，欢迎Issues。



#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T22:20:59
#
#-------------------------------------------------

QT       += core gui
CONFIG += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = screenshot
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    oescreenshot.cpp \
    oeamplifier.cpp \
    oescreen.cpp \
    oerect.cpp \
    oecommonhelper.cpp

HEADERS  += oescreenshot.h \
    oeamplifier.h \
    oescreen.h \
    oerect.h \
    oecommonhelper.h

DISTFILES +=
