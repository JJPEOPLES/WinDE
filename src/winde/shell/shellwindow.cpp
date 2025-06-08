#include "shellwindow.h"
#include <QPainter>
#include <QResizeEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

ShellWindow::ShellWindow(QScreen *screen, QWidget *parent)
    : QWidget(parent)
    , m_screen(screen)
    , m_taskBar(nullptr)
    , m_startMenu(nullptr)
    , m_desktopGrid(nullptr)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
    setAttribute(Qt::WA_X11NetWmWindowTypeDesktop);
    
    // Initialize UI components
    setupUI();
    
    // Set geometry to match screen
    setGeometry(screen->geometry());
    
    // Connect screen geometry changes
    connect(screen, &QScreen::geometryChanged,
            this, [this](const QRect &geometry) {
                setGeometry(geometry);
            });
}

ShellWindow::~ShellWindow()
{
}

void ShellWindow::setupUI()
{
    setupDesktop();
    setupTaskBar();
    setupStartMenu();
    updateWallpaper();
}

void ShellWindow::setupTaskBar()
{
    // Create and setup the Windows-style taskbar
    m_taskBar = new TaskBar(this);
    m_taskBar->setGeometry(0, height() - 40, width(), 40);
}

void ShellWindow::setupStartMenu()
{
    // Create and setup the Windows-style start menu
    m_startMenu = new StartMenu(this);
    m_startMenu->hide(); // Only show when clicking start button
}

void ShellWindow::setupDesktop()
{
    // Create and setup the desktop icons grid
    m_desktopGrid = new DesktopGrid(this);
    m_desktopGrid->setGeometry(0, 0, width(), height() - 40);
}

void ShellWindow::updateWallpaper()
{
    // Set default Windows-style wallpaper
    m_wallpaperPath = QStringLiteral("/usr/share/winde/wallpapers/default.jpg");
    update();
}

void ShellWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(m_wallpaperPath));
}

void ShellWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    
    if (m_taskBar) {
        m_taskBar->setGeometry(0, height() - 40, width(), 40);
    }
    
    if (m_desktopGrid) {
        m_desktopGrid->setGeometry(0, 0, width(), height() - 40);
    }
}

void ShellWindow::updateActiveWindow(WId id)
{
    if (m_taskBar) {
        m_taskBar->setActiveWindow(id);
    }
} 