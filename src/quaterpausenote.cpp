#include "quaterpausenote.h"

QuaterPauseNote::QuaterPauseNote(int heigth): Note(heigth,500)
{
    _pNoteIcon = new QPixmap(":/notes/images/quaterrest.png");
}

void QuaterPauseNote::printOut(int posX, QWidget *parent)
{
    _pNoteLabel = new QLabel(parent);
    _pNoteLabel->setPixmap(*_pNoteIcon);
    _pNoteLabel->move(posX,300);
    _pNoteLabel->raise();
    _pNoteLabel->setFixedSize(QSize(55,91));
    _pNoteLabel->show();
}

void QuaterPauseNote::playNote(Synthesizer notePlayer, int volume)
{
    notePlayer.spela(_height,_length,0);
}

QuaterPauseNote::~QuaterPauseNote()
{

}
