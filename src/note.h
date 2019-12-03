#ifndef NOTE_H
#define NOTE_H
#include <QPixmap>
#include <QLabel>
#include <Synthesizer.h>

class Note
{
public:
    Note(int heigth, int length=0);
    virtual void printOut(int posX, QWidget* parent = nullptr);
    virtual void playNote(Synthesizer notePlayer, int volume);
    virtual ~Note();
protected:
    int _length;
    int _height;
    QPixmap * _pNoteIcon;
    QLabel * _pNoteLabel;
};

#endif // NOTE_H
