#include "halfnot.h"

HalfNot::HalfNot(int heigth): Note(heigth,1000)
{   
    if(heigth >= 7)
        _pNoteIcon = new QPixmap(":/notes/images/half180.png");
    else if(heigth == 0)
        _pNoteIcon = new QPixmap(":/notes/images/halfc.png");
    else
        _pNoteIcon = new QPixmap(":/notes/images/half.png");

}

void HalfNot::playNote(Synthesizer notePlayer, int volume)
{
    notePlayer.spela(_height,_length,volume);
}

HalfNot::~HalfNot()
{

}
