#ifndef QUATERNOTE_H
#define QUATERNOTE_H
#include "note.h"

class QuaterNote : public Note
{
public:
    QuaterNote(int heigth);
    void playNote(Synthesizer notePlayer, int volume) override;
    ~QuaterNote() override;
};

#endif // QUATERNOTE_H
