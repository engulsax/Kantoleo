#ifndef EIGTHQUATER_H
#define EIGTHQUATER_H
#include "note.h"

class EigthNote : public Note
{
public:
    EigthNote(int heigth);
    void playNote(Synthesizer notePlayer, int volume) override;
    ~EigthNote() override;
};

#endif // EIGTHQUATER_H
