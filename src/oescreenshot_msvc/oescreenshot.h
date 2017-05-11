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


#ifndef OESCREENSHOT_H
#define OESCREENSHOT_H

#include <memory>
#include <QRect>
#include <QWidget>

class OEScreen;
class OERect;
class OEAmplifier;
class QTimer;
class QMenu;


/**
 * @class : OEScreenshot
 * @brief : �������ܵ���Ҫ���,
 *          ����ȫ���ȼ�,��Դ�Ļ������ͷ�.
 * @remark: ����ʾ��( OEScreenshot::Instance(); )
*/
class OEScreenshot : public QWidget {
    Q_OBJECT

signals:

    /**
     * @brief : ����ƶ����źţ�
     * @param : int x�������
     * @param : int y�������
     * @date  : 2017��04��18��
     */
    void cursorPosChange(int, int);

    /**
     * @brief : ˫�����źţ�
     * @date  : 2017��04��18��
     */
    void doubleClick(void);

    /**
     * @brief : ��굱ǰλ����С���Ӵ��ڣ��źţ�
     * @param : QRect ��ǰ���ڵľ�������
     * @date  : 2017��04��18��
     */
    void findChildWind(QRect);

public:
    /**
     * @brief : ���캯��
     * @note  : ��ǰ�����ĸ����ڣ�һ�㲻�������ڣ�
     * @date  : 2017��04��16��
     */
    explicit OEScreenshot(QWidget *parent = 0);
    ~OEScreenshot(void);

    /**
     * @brief : ����ʵ��
     * @note  : ͨ�����������ý�ͼ��������ʵ��
     * @return: ���� OEScreenshot ʵ��ָ��
     * @date  : 2017��04��15��
     */
    static OEScreenshot *Instance(void);

    /**
     * @brief : �ݻٽ�ͼ����
     * @note  : ͨ������������Դݻ�������ͼ����
     * @date  : 2017��04��30��
     */
    static void destroy(void);

protected:

    /**
     * @brief : ���ش����¼�
     */
    virtual void hideEvent(QHideEvent *);
    /**
     * @brief : �رմ����¼�
     */
    virtual void closeEvent(QCloseEvent *);
    /**
     * @brief : ˫���¼�
     */
    virtual void mouseDoubleClickEvent(QMouseEvent*);
    /**
     * @brief : ��갴���¼�
     */
    virtual void mousePressEvent(QMouseEvent *);
    /**
     * @brief : ����ͷ��¼�
     */
    virtual void mouseReleaseEvent(QMouseEvent *e);
    /**
     * @brief : ����ƶ��¼�
     */
    virtual void mouseMoveEvent(QMouseEvent *e);

    /**
     * @brief : ���������¼�
     */
    virtual void keyPressEvent(QKeyEvent *e);
    /**
     * @brief : �Ի��¼�
     */
    virtual void paintEvent(QPaintEvent *);

    /**
     * @brief : ���µ�ǰ���ѡ���Ĵ���
     */
    void updateMouse(void);

private:


    /**
     * @brief : ��ʼ���Ŵ� (ɫ�ʲɼ���)
     * @note  : ����Ҫ��Ļ��ԭ����Ϊ�Ŵ����ķŴ�Ԫ��
     * @param : originPainting �Ŵ�����Ҫ��Ԫ�أ���Ϊ�գ���Ĭ����originPainting_ԭ��
     * @date  : 2017��04��15��
     * @remark: �����е���getGlobalScreen��
     */
    void initAmplifier(std::shared_ptr<QPixmap> originPainting = nullptr);

    /**
     * @brief : �����ؼ� (��С��֪��)
     * @date  : 2017��04��27��
     */
    void initMeasureWidget(void);

    /**
     * @brief : ��ʼ����������
     * @return: QPixmap ������ɫ�������Ļͼ
     * @date  : 2017��04��15��
     */
    std::shared_ptr<QPixmap> initGlobalScreen(void);


    /**
     * @brief : ��ʼ�����
     * @note  : Ϊ�������Ĭ��״̬�µ�ͼ����ʽ
     * @param : ico ���ͼƬ����Դ�ļ�·��
     * @date  : 2017��04��15��
     * @remark: ������δ��д����ʹ�ñ�����Ĭ�ϵ����Logo
     */
    void initCursor(const QString& ico = "");

    /**
     * @brief : ������ͼ��
     * @note  : ����ͼ���Ѵ��ڣ��򷵻ؽ�ͼ��ʾ���������ظ�������
     * @param : pos ��ͼ������ʼλ�� ������ǰ���λ�ü��ɣ�
     * @date  : 2017��04��16��
     * @remark: ������ͼ��ǰ����Ҫ������ص������(������С��֪�����Ŵ�ȡɫ��)
     */
    std::shared_ptr<OEScreen> createScreen(const QPoint &pos);

    /**
     * @brief : �ݻٽ�ͼ��
     * @note  : ����ͼ���Ѵ��ڣ���ݻ�ʾ����������ʾ��������������Դ
     * @date  : 2017��04��16��
     */
    void destroyScreen(void);


    /**
     * @brief : ��õ�ǰ��Ļ�Ĵ�С
     * @note  : ���������֧�ֶ���Ļ�ģ�ʾ����˫��Ļ QRect��-1920, 0, 3840, 1080��
     * @return: ���� QRect ����
     * @date  : 2017��04��15��
     */
    const QRect& getScreenRect(void);

    /**
     * @brief : �����Ļ��ԭ��
     * @note  : �������ظ������Ļԭ��������У��򷵻�ԭ�е�ԭ��
     * @return: QPixmap* ָ��
     * @date  : 2017��04��15��
     * @remark: �������»����Ļԭ������Ҫ����ԭ����Դ
     */
    std::shared_ptr<QPixmap> getGlobalScreen(void);


private:

    /// ���������Ƿ��Ѿ�չʾ
    bool isLeftPressed_;
    /// ���ڼ�������
    QPoint startPoint_;
    /// ��ǰ������Ļ�ľ�������
    QRect desktopRect_;
    /// ��Ļ��ɫ����ͼ
    std::shared_ptr<QPixmap> backgroundScreen_;
    /// ��Ļԭ��
    std::shared_ptr<QPixmap> originPainting_;
    /// ��ͼ��Ļ
    std::shared_ptr<OEScreen> screenTool_;
    /// ��ͼ����С��֪��
    std::shared_ptr<OERect> rectTool_;
    /// �Ŵ�ȡɫ��
    std::shared_ptr<OEAmplifier> amplifierTool_;
    /// ��ǰ���ѡ����С�ľ��δ���
    QRect windowRect_;
    /// ����ʵ������
    static OEScreenshot *self_;
    /// �ö���ʱ��
    QTimer* egoisticTimer_;
    /// �����
    static bool isActivity_;
private slots:

    /**
     * @brief : Window�°Ե��ö���Ψ�Ҷ���
     * @date  : 2017��04��28��
     * @remark: ʹ�øú���ʱ������ֹ�Ҽ��˵�����Ϊ������ʹ�ã�����BUG
     */
    void onEgoistic(void);
};




/**
 * @class : OERect
 * @brief : ��С��֪��
 * @note  : ��Ҫ�غ���ͼ�����Ϸ��Ĵ�С��֪�ؼ�
*/
class OERect : public QWidget {
    Q_OBJECT

signals:


public:

    explicit OERect(QWidget *parent = 0);

protected:

    /**
     * @brief : �Ի溯��
     */
    void paintEvent(QPaintEvent *);

public slots:

    /**
     * @brief : �ⲿ���λ���޸ģ��ۣ�
     * @note  : ��֪���޸�����λ��
     * @param : x ����λ��
     * @param : y ����λ��
     * @date  : 2017��04��15��
     */
    void onPostionChange(int x, int y);

    /**
     * @brief : �ⲿ�����С�޸� ���ۣ�
     * @note  : ��֪���޸���ʾ�Ĵ�С����
     * @param : w ���
     * @param : h �߶�
     * @date  : 2017��04��15��
     */
    void onSizeChange(int w, int h);

private:
    /// ����ɫ
    std::shared_ptr<QPixmap> backgroundPixmap_;
    /// ��ʾ��������Ϣ
    QString info_;
};


/**
 * @class : OEScreen
 * @brief : ��ͼ��
 * @note  : ��Ҫ�غ�ͼƬ�ı༭�뱣��
*/
class OEScreen : public QWidget {

    Q_OBJECT

signals:


    /**
     * @brief : ��ͼ����С�޸ģ��źţ�
     * @param : int ���
     * @param : int �߶�
     * @date  : 2017��04��17��
     */
    void sizeChange(int,int);

    /**
     * @brief : ��ͼ�����ڵ�λ�ã��źţ�
     * @param : int ���ڵĺ���λ��
     * @param : int ���ڵ�����λ��
     * @date  : 2017��04��17��
     */
    void postionChange(int,int);

    /**
     * @brief : ˫�� ���źţ�
     * @date  : 2017��04��17��
     */
    void doubleClick(void);

protected:

    /// �ڱ߾࣬������ק�Ĵ�����
    const int PADDING_ = 6;

    /// ��λö��
    enum DIRECTION {
        UPPER=0,
        LOWER=1,
        LEFT,
        RIGHT,
        LEFTUPPER,
        LEFTLOWER,
        RIGHTLOWER,
        RIGHTUPPER,
        NONE
    };

public:

    explicit OEScreen(std::shared_ptr<QPixmap> originPainting, QPoint pos, QWidget *parent = 0);

    ~OEScreen() { isInit_ = false; }

    /**
     * @brief : ��õ�ǰ��ͼ���Ƿ����
     * @return: true : ����
     * @date  : 2017��04��17��
     */
    static bool state(void) { return isInit_; }

protected:

    /**
     * @brief : ��õ�ǰ�����ı߽緽λ
     * @param : cursor ��ǰ����λ��
     * @return: DIRECTION ���ķ�λö��
     * @date  : 2017��04��17��
     */
    DIRECTION getRegion(const QPoint &cursor);


    /**
     * @brief : �����˵��¼�
     */
    virtual void contextMenuEvent(QContextMenuEvent *);

    /**
     * @brief : ˫���¼�
     */
    virtual void mouseDoubleClickEvent(QMouseEvent *e);

    /**
     * @brief : ��갴���¼�
     */
    virtual void mousePressEvent(QMouseEvent *e);

    /**
     * @brief : ����ͷ��¼�
     */
    virtual void mouseReleaseEvent(QMouseEvent *e);
    /**
     * @brief : ����ƶ��¼�
     */
    virtual void mouseMoveEvent(QMouseEvent *e);

    /**
     * @brief : �����ƶ��¼�
     */
    virtual void moveEvent(QMoveEvent *);

    /**
     * @brief : ���ڴ�С�޸��¼�
     */
    virtual void resizeEvent(QResizeEvent *);


    /**
     * @brief : ������ʾ�¼�
     */
    virtual void showEvent(QShowEvent *);

    /**
     * @brief : ���������¼�
     */
    virtual void hideEvent(QHideEvent *);

    /**
     * @brief : �����봰���¼�
     */
    virtual void enterEvent(QEvent *e);

    /**
     * @brief : ����뿪�����¼�
     */
    virtual void leaveEvent(QEvent *e);

    /**
     * @brief : ���ڹر��¼�
     */
    virtual void closeEvent(QCloseEvent *);

    /**
     * @brief : �����Ի��¼�
     */
    virtual void paintEvent(QPaintEvent *);

private:

    /**
     * @brief : ���һ����ʱ���ʽ�������ļ���
     * @return: QString �ļ���
     * @date  : 2017��04��16��
     */
    virtual const QString getFileName(void);

public slots:


    /**
     * @brief : �������λ���޸Ĵ��ڴ�С
     * @param : x ���ĺ���λ��
     * @param : y ��������λ��
     * @date  : 2017��04��16��
     */
    void onMouseChange(int x,int y);

    /**
     * @brief : ������Ļ�����а���
     * @date  : 2017��04��16��
     */
    void onSaveScreen(void);

protected slots:

    /**
     * @brief : ����༭��Ļ������·����
     * @note  : �����·��ѡ��Ĵ���
     * @date  : 2017��04��16��
     */
    void onSaveScreenOther(void);

    /**
     * @brief : �˳���ǰ��ͼ����
     * @date  : 2017��04��16��
     */
    void quitScreenshot(void);

private:

    /// �Ƿ��Ѿ����ó�ʼ��С
    static bool isInit_;
    /// ���ڴ�С�ı�ʱ����¼�ı䷽��
    DIRECTION direction_;
    /// ���
    QPoint originPoint_;
    /// ����Ƿ���
    bool isPressed_;
    /// �϶��ľ���
    QPoint movePos_;
    /// ���ê��
    QPolygon listMarker_;
    /// ��Ļԭ��
    std::shared_ptr<QPixmap> originPainting_;
    /// ��ǰ���ڼ������� ���ڻ��ƽ�ͼ����
    QRect currentRect_;
    /// �Ҽ��˵�����
    QMenu *menu_;

};



#endif /// OESCREENSHOT_H
