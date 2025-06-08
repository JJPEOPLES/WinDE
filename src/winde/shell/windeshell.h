#pragma once

#include <QObject>
#include <QScreen>
#include <KWindowSystem>

class ShellWindow;

class WinDEShell : public QObject
{
    Q_OBJECT

public:
    explicit WinDEShell(QObject *parent = nullptr);
    ~WinDEShell();

    void initialize();

private slots:
    void setupScreen(QScreen *screen);
    void handleScreenRemoved(QScreen *screen);
    void handleActiveWindowChanged(WId id);

private:
    QHash<QScreen*, ShellWindow*> m_shellWindows;
    void createShellWindow(QScreen *screen);
    void initializeWindowManager();
    void initializeCompositor();
}; 