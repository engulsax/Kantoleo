#include "eigthpausenote.h"

EigthPauseNote::EigthPauseNote(int heigth): Note(heigth,250)
{
    _pNoteIcon = new QPixmap(":/notes/images/eightrest.png");
}

void EigthPauseNote::printOut(int posX, QWidget *parent)
{
    _pNoteLabel = new QLabel(parent);
    _pNoteLabel->setPixmap(*_pNoteIcon);
    _pNoteLabel->move(posX,280);
    _pNoteLabel->raise();
    _pNoteLabel->setFixedSize(QSize(55,91));
    _pNoteLabel->show();
}

void EigthPauseNote::playNote(Synthesizer notePlayer, int volume)
{
    notePlayer.spela(_height,_length,0);
}

EigthPauseNote::~EigthPauseNote()
{

}
