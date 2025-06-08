#pragma once

#include <QPushButton>
#include <KWindowSystem>

class TaskButton : public QPushButton
{
    Q_OBJECT

public:
    explicit TaskButton(WId windowId, QWidget *parent = nullptr);
    ~TaskButton() override;

    WId windowId() const { return m_windowId; }
    void setActive(bool active);

protected:
    void paintEvent(QPaintEvent *event) override;
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void updateWindowInfo();

private:
    WId m_windowId;
    bool m_isActive;
    bool m_isHovered;
    QString m_title;
    QIcon m_icon;
}; 