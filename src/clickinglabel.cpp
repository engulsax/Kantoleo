#include "clickinglabel.h"

ClickingLabel::ClickingLabel(QWidget * parent) : QLabel(parent)
{}

void ClickingLabel::mousePressEvent(QMouseEvent *event)
{
    emit isClicked();
}

