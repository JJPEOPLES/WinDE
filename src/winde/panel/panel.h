#pragma once

#include <QWidget>
#include <QScreen>

class TaskBar;
class SysTray;
class StartButton;
class Clock;

class Panel : public QWidget
{
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = nullptr);
    ~Panel() override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void setupUI();
    void updateLayout();

    TaskBar *m_taskBar;
    SysTray *m_sysTray;
    StartButton *m_startButton;
    Clock *m_clock;
}; 