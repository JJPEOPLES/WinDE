#pragma once

#include <QWidget>
#include <QList>

class TaskButton;

class TaskBar : public QWidget
{
    Q_OBJECT

public:
    explicit TaskBar(QWidget *parent = nullptr);
    ~TaskBar() override;

    void setActiveWindow(WId id);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onWindowAdded(WId id);
    void onWindowRemoved(WId id);
    void onActiveWindowChanged(WId id);

private:
    void setupUI();
    void updateLayout();
    TaskButton* findButton(WId id) const;

    QList<TaskButton*> m_buttons;
    WId m_activeWindow;
}; 