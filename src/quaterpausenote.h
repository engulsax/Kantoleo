#ifndef QUATERPAUSENOTE_H
#define QUATERPAUSENOTE_H
#include "note.h"

class QuaterPauseNote : public Note
{
public:
    QuaterPauseNote(int heigth);
    void printOut(int posX,QWidget* parent = nullptr) override;
    void playNote(Synthesizer notePlayer, int volume) override;
    ~QuaterPauseNote() override;
};

#endif // QUATERPAUSENOTE_H
