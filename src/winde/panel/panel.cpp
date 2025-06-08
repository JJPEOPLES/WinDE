#include "panel.h"
#include "taskbar.h"
#include "systray.h"
#include "startbutton.h"
#include "clock.h"
#include <QPainter>
#include <QResizeEvent>
#include <QScreen>
#include <QApplication>

Panel::Panel(QWidget *parent)
    : QWidget(parent)
    , m_taskBar(nullptr)
    , m_sysTray(nullptr)
    , m_startButton(nullptr)
    , m_clock(nullptr)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setupUI();
}

Panel::~Panel()
{
}

void Panel::setupUI()
{
    m_startButton = new StartButton(this);
    m_taskBar = new TaskBar(this);
    m_sysTray = new SysTray(this);
    m_clock = new Clock(this);

    updateLayout();
}

void Panel::updateLayout()
{
    const int height = 40;
    const int padding = 4;
    
    setFixedHeight(height);
    
    // Layout components from left to right
    int x = padding;
    
    // Start button
    m_startButton->setGeometry(x, padding, height - 2*padding, height - 2*padding);
    x += m_startButton->width() + padding;
    
    // Clock (right-aligned)
    m_clock->setGeometry(width() - height + padding, padding, height - 2*padding, height - 2*padding);
    
    // System tray (right-aligned before clock)
    const int systrayWidth = 120;
    m_sysTray->setGeometry(width() - height - systrayWidth, padding, systrayWidth, height - 2*padding);
    
    // Taskbar (fills remaining space)
    m_taskBar->setGeometry(x, padding, 
                          width() - x - systrayWidth - height - padding,
                          height - 2*padding);
}

void Panel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Draw semi-transparent background
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 255, 255, 230));
    painter.drawRoundedRect(rect(), 0, 0);
}

void Panel::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updateLayout();
} 