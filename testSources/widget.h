#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QDir>
#include <QProcess>
#include <QString>

#include <QVideoWidget>
#include <QMediaPlayer>
#include <QTimer>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void playerQTimerSlot();


private:
    Ui::Widget *ui;


    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QString filename;

    QTimer   *m_QT_playerTimer;
    int m_showTimer;
};

#endif // WIDGET_H
