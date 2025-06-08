#pragma once

#include <QWidget>
#include <QTimer>

class Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = nullptr);
    ~Clock() override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void updateTime();

private:
    QString m_timeFormat;
    QTimer *m_timer;
    QString m_currentTime;
}; 