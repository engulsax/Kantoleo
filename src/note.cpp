#include "note.h"
#include <QLabel>
#include <QDebug>

Note::Note(int heigth, int length) : _height(heigth), _length(length)
{

}

void Note::printOut(int posX, QWidget *parent)
{
    _pNoteLabel = new QLabel(parent);
    _pNoteLabel->setPixmap(*_pNoteIcon);
    if(_height>=7)
        _pNoteLabel->move(posX,380-_height*8);
    else
        _pNoteLabel->move(posX,332-_height*8);
    _pNoteLabel->raise();
    _pNoteLabel->setFixedSize(QSize(55,91));
    _pNoteLabel->show();
    qDebug() << _height;
}


void Note::playNote(Synthesizer notePlayer, int volume)
{

}

Note::~Note()
{
    delete _pNoteLabel;
    delete _pNoteIcon;
}
