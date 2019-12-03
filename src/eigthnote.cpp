#include "eigthnote.h"

EigthNote::EigthNote(int heigth): Note(heigth,250)
{
    if(heigth >= 7)
        _pNoteIcon = new QPixmap(":/notes/images/eight180.png");
    else if(heigth == 0)
        _pNoteIcon = new QPixmap(":/notes/images/eightc.png");
    else
        _pNoteIcon = new QPixmap(":/notes/images/eight.png");
}

void EigthNote::playNote(Synthesizer notePlayer, int volume)
{
    notePlayer.spela(_height,_length,volume);
}

EigthNote::~EigthNote()
{

}
