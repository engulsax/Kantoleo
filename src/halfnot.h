#ifndef HALFNOT_H
#define HALFNOT_H
#include "note.h"

class HalfNot : public Note
{
public:
    HalfNot(int heigth);
    void playNote(Synthesizer notePlayer, int volume) override;
    ~HalfNot() override;
};

#endif // HALFNOT_H
