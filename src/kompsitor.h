#pragma once
#include "Synthesizer.h"
#include "sheet.h"
#include "clickinglabel.h"
#include <QMainWindow>

namespace Ui {
class Kompsitor;
}

class Kompsitor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kompsitor(QWidget *parent = nullptr);
    int pixelToHeigth(int yPixel);
    void mousePressEvent(QMouseEvent *event) override;
    void playNotes();
    void removeAllNotes();
    void changeCursorToForbiddenAndBack();
    ~Kompsitor() override;
public slots:
    void quaterNoteClicked();
    void eigthNoteClicked();
    void halfNoteClicked();
    void eigthrestNoteClicked();
    void quaterrestNoteClicked();
    void playButtonClicked();
    void pauseButtonClicked();
    void garbageButtonClicked();
private slots:
    void on_sliderVolume_sliderMoved(int position);

private:
    Synthesizer _notePlayer;
    Ui::Kompsitor *ui;
    Synthesizer * _pSynthesizer;
    Sheet * _pSheet;
    ClickingLabel * _pChoosenNote;
    int _volume;
    int _lastPlacedNotePosX;
    int _notetype;
};
