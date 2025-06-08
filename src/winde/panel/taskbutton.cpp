#include "taskbutton.h"
#include <QPainter>
#include <QMouseEvent>
#include <KWindowInfo>
#include <KWindowSystem>

TaskButton::TaskButton(WId windowId, QWidget *parent)
    : QPushButton(parent)
    , m_windowId(windowId)
    , m_isActive(false)
    , m_isHovered(false)
{
    setMouseTracking(true);
    updateWindowInfo();

    // Connect to window system signals for updates
    connect(KWindowSystem::self(), &KWindowSystem::windowChanged,
            this, [this](WId id, const unsigned long *properties) {
                if (id == m_windowId) {
                    updateWindowInfo();
                }
            });
}

TaskButton::~TaskButton()
{
}

void TaskButton::setActive(bool active)
{
    if (m_isActive != active) {
        m_isActive = active;
        update();
    }
}

void TaskButton::updateWindowInfo()
{
    KWindowInfo info(m_windowId, NET::WMName | NET::WMIcon);
    m_title = info.name();
    m_icon = KWindowSystem::icon(m_windowId);
    update();
}

void TaskButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw background
    QColor bgColor = m_isActive ? QColor(200, 200, 200, 200) :
                    m_isHovered ? QColor(180, 180, 180, 150) :
                                 QColor(150, 150, 150, 100);
    
    painter.setPen(Qt::NoPen);
    painter.setBrush(bgColor);
    painter.drawRoundedRect(rect(), 2, 2);

    // Draw icon
    if (!m_icon.isNull()) {
        QRect iconRect(4, (height() - 16) / 2, 16, 16);
        m_icon.paint(&painter, iconRect);
    }

    // Draw text
    if (!m_title.isEmpty()) {
        painter.setPen(Qt::black);
        QRect textRect = rect().adjusted(24, 0, -4, 0);
        painter.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter,
                        painter.fontMetrics().elidedText(m_title, Qt::ElideRight, textRect.width()));
    }
}

void TaskButton::enterEvent(QEnterEvent *event)
{
    m_isHovered = true;
    update();
    QPushButton::enterEvent(event);
}

void TaskButton::leaveEvent(QEvent *event)
{
    m_isHovered = false;
    update();
    QPushButton::leaveEvent(event);
}

void TaskButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (KWindowSystem::activeWindow() == m_windowId) {
            KWindowSystem::minimizeWindow(m_windowId);
        } else {
            KWindowSystem::activateWindow(m_windowId);
        }
    }
    QPushButton::mousePressEvent(event);
} 