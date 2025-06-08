#include "clock.h"
#include <QPainter>
#include <QTime>
#include <QMouseEvent>
#include <QMenu>
#include <QAction>

Clock::Clock(QWidget *parent)
    : QWidget(parent)
    , m_timeFormat("hh:mm")
    , m_timer(new QTimer(this))
{
    m_timer->setInterval(1000);  // Update every second
    connect(m_timer, &QTimer::timeout, this, &Clock::updateTime);
    m_timer->start();
    
    updateTime();
}

Clock::~Clock()
{
}

void Clock::updateTime()
{
    m_currentTime = QTime::currentTime().toString(m_timeFormat);
    update();
}

void Clock::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw background
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(150, 150, 150, 100));
    painter.drawRoundedRect(rect(), 2, 2);

    // Draw time
    painter.setPen(Qt::black);
    painter.drawText(rect(), Qt::AlignCenter, m_currentTime);
}

void Clock::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        QMenu menu(this);
        
        QAction *format24h = menu.addAction("24-hour");
        QAction *format12h = menu.addAction("12-hour");
        
        format24h->setCheckable(true);
        format12h->setCheckable(true);
        
        format24h->setChecked(m_timeFormat == "HH:mm");
        format12h->setChecked(m_timeFormat == "hh:mm AP");
        
        connect(format24h, &QAction::triggered, this, [this]() {
            m_timeFormat = "HH:mm";
            updateTime();
        });
        
        connect(format12h, &QAction::triggered, this, [this]() {
            m_timeFormat = "hh:mm AP";
            updateTime();
        });
        
        menu.exec(event->globalPos());
    }
    
    QWidget::mousePressEvent(event);
} 