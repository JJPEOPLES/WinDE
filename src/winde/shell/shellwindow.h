#pragma once

#include <QWidget>
#include <QScreen>

class TaskBar;
class StartMenu;
class DesktopGrid;

class ShellWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShellWindow(QScreen *screen, QWidget *parent = nullptr);
    ~ShellWindow();

    void updateActiveWindow(WId id);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void setupUI();
    void setupTaskBar();
    void setupStartMenu();
    void setupDesktop();
    void updateWallpaper();

    QScreen *m_screen;
    TaskBar *m_taskBar;
    StartMenu *m_startMenu;
    DesktopGrid *m_desktopGrid;
    QString m_wallpaperPath;
}; 