#include "RingWait2.h"

RingWait2::RingWait2(QWidget *parent)
    : QDialog(parent)
{
    offset=0;
    //启动定时器
    startTimer(50);
    //设置控件大小
    setFixedSize(100,100);
    //去掉标题栏 设置置顶 去掉任务栏图标
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint);

    //设置窗口背景透明
    setAttribute(Qt::WA_TranslucentBackground, true);
}

RingWait2::~RingWait2()
{}

void RingWait2::timerEvent(QTimerEvent*)
{
    ++offset;
    if(offset>11)
        offset=0;
    update();
}

void RingWait2::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);  // 反锯齿

    int width=this->width();
    int height=this->height();

    //画笔移动到中间
    painter.translate(width >> 1, height>> 1);

    //计算偏移坐标
    int offsetDest=(width-30)/2;

    painter.setPen(Qt::NoPen);

    //计算小圆坐标
    for(int i=0;i<9;++i){
        QPoint point(0,0);
        painter.setBrush(QColor(255,190-i*20,i*15,255-i*30));
        point.setX(offsetDest*qSin((-offset+i)*M_PI/6));
        point.setY(offsetDest*qCos((-offset+i)*M_PI/6));

        QPainterPath bigRing;
        bigRing.addEllipse(point.x()-10-i/4, point.y()-10-i/4, 20+i/2, 20+i/2);

        QPainterPath smallRing;
        smallRing.addEllipse(point.x()-6+i, point.y()-6+i, 12-2*i, 12-2*i);

        painter.drawPath(bigRing.subtracted(smallRing));
    }
}
