#ifndef EIGTHPAUSENOTE_H
#define EIGTHPAUSENOTE_H
#include "note.h"


class EigthPauseNote : public Note
{
public:
    EigthPauseNote(int heigth);
    void printOut(int posX,QWidget* parent = nullptr) override;
    void playNote(Synthesizer notePlayer, int volume) override;
    ~EigthPauseNote() override;
};

#endif // EIGTHPAUSENOTE_H
