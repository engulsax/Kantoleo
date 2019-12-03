#pragma once
#include <QLabel>
#include <QMouseEvent>
#include <QWidget>

class ClickingLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickingLabel(QWidget* parent = nullptr);
    void mousePressEvent(QMouseEvent * event);
signals:
    void isClicked();
};

