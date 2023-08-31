#include "widget.h"
#include "ui_widget.h"

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QTimer>
#include <QString>
#include <QSplashScreen>
#include <QPixmap>
#include <QDir>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    //单独显示的QLabel 其大小为内容即图片的大小，若将QLabel放入QMainWindow中则QLabel的大小为其初始大小。

    QPoint cursorPos(1024,768);
    QCursor::setPos(cursorPos);

    QDir PictureDir;
    QString PicturePath = PictureDir.currentPath();
    QPalette BackGroundPalette = this->palette();
    qDebug() << "PicturePath: " << PicturePath;
    BackGroundPalette.setBrush(QPalette::Window,QBrush(QPixmap(PicturePath+"/Picture/LoadingNow.png").scaled(this->size(),
                                                       Qt::IgnoreAspectRatio,
                                                       Qt::SmoothTransformation)));// 使用平滑的缩放方式
    this->setPalette(BackGroundPalette);

    this->setWindowFlags(Qt::FramelessWindowHint);//没有边框
//    this->move(QPoint(0,0));

//-----------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------------
    //kill自己
    m_QT_playerTimer = new QTimer(this);
    connect(m_QT_playerTimer,SIGNAL(timeout()),this,SLOT(playerQTimerSlot()));

    m_QT_playerTimer->start(1000);
    m_showTimer = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::playerQTimerSlot()
{
    player->play();


    if (++m_showTimer > 12)
    {

        int pid = qApp->applicationPid();
        QString killCmd;

        //killCmd = QString("taskkill /pid %1 /f").arg(pid);
        killCmd = "kill  " + QString::number(pid);
        QProcess::startDetached(killCmd);

        qDebug() << "killCmd: " << killCmd;

        qDebug() << "m_showTimer: " << m_showTimer;
    }

}
