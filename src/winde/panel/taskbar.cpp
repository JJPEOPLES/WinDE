#include "taskbar.h"
#include "taskbutton.h"
#include <QPainter>
#include <QResizeEvent>
#include <KWindowSystem>

TaskBar::TaskBar(QWidget *parent)
    : QWidget(parent)
    , m_activeWindow(0)
{
    setupUI();
    
    // Connect to window system signals
    connect(KWindowSystem::self(), &KWindowSystem::windowAdded,
            this, &TaskBar::onWindowAdded);
    connect(KWindowSystem::self(), &KWindowSystem::windowRemoved,
            this, &TaskBar::onWindowRemoved);
    connect(KWindowSystem::self(), &KWindowSystem::activeWindowChanged,
            this, &TaskBar::onActiveWindowChanged);
            
    // Add existing windows
    const QList<WId> windows = KWindowSystem::windows();
    for (WId id : windows) {
        onWindowAdded(id);
    }
}

TaskBar::~TaskBar()
{
    qDeleteAll(m_buttons);
}

void TaskBar::setupUI()
{
    setAttribute(Qt::WA_TranslucentBackground);
}

void TaskBar::updateLayout()
{
    if (m_buttons.isEmpty())
        return;

    const int buttonWidth = width() / m_buttons.count();
    const int buttonHeight = height();
    
    int x = 0;
    for (TaskButton *button : m_buttons) {
        button->setGeometry(x, 0, buttonWidth, buttonHeight);
        x += buttonWidth;
    }
}

void TaskBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    // Draw semi-transparent background
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 255, 255, 200));
    painter.drawRoundedRect(rect(), 2, 2);
}

void TaskBar::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updateLayout();
}

void TaskBar::onWindowAdded(WId id)
{
    if (!KWindowSystem::hasWId(id))
        return;

    // Skip if we already have a button for this window
    if (findButton(id))
        return;

    // Create new button
    auto *button = new TaskButton(id, this);
    m_buttons.append(button);
    button->show();
    
    updateLayout();
}

void TaskBar::onWindowRemoved(WId id)
{
    if (TaskButton *button = findButton(id)) {
        m_buttons.removeOne(button);
        delete button;
        updateLayout();
    }
}

void TaskBar::onActiveWindowChanged(WId id)
{
    m_activeWindow = id;
    
    // Update button states
    for (TaskButton *button : m_buttons) {
        button->setActive(button->windowId() == id);
    }
}

void TaskBar::setActiveWindow(WId id)
{
    if (id != m_activeWindow) {
        onActiveWindowChanged(id);
    }
}

TaskButton* TaskBar::findButton(WId id) const
{
    for (TaskButton *button : m_buttons) {
        if (button->windowId() == id)
            return button;
    }
    return nullptr;
} 