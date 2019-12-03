#include "quaternote.h"
#include "kompsitor.h"
#include <QLabel>
#include <QDebug>

QuaterNote::QuaterNote(int heigth): Note(heigth,500)
{
    if(heigth >= 7)
        _pNoteIcon = new QPixmap(":/notes/images/quater180.png");
    else if(heigth == 0)
        _pNoteIcon = new QPixmap(":/notes/images/quaterc.png");
    else
        _pNoteIcon = new QPixmap(":/notes/images/quater.png");

}

void QuaterNote::playNote(Synthesizer notePlayer, int volume)
{
    notePlayer.spela(_height,_length,volume);
}

QuaterNote::~QuaterNote()
{

}
