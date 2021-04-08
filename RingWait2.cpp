#include "RingWait2.h"

RingWait2::RingWait2(QWidget *parent)
    : QDialog(parent)
{
    offset=0;
    //������ʱ��
    startTimer(50);
    //���ÿؼ���С
    setFixedSize(100,100);
    //ȥ�������� �����ö� ȥ��������ͼ��
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint);

    //���ô��ڱ���͸��
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
    painter.setRenderHint(QPainter::Antialiasing,true);  // �����

    int width=this->width();
    int height=this->height();

    //�����ƶ����м�
    painter.translate(width >> 1, height>> 1);

    //����ƫ������
    int offsetDest=(width-30)/2;

    painter.setPen(Qt::NoPen);

    //����СԲ����
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
