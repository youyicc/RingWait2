#ifndef RINGWAIT2_H
#define RINGWAIT2_H

#include <QtMath>
#include <QDialog>
#include <QPainter>
#include <QTimerEvent>
#include <QPainterPath>

class RingWait2 : public QDialog
{
    Q_OBJECT

private:
    int offset;

public:
    RingWait2(QWidget *parent = nullptr);
    ~RingWait2();

protected:
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);
};
#endif
