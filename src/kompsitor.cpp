#include "kompsitor.h"
#include "ui_kompsitor.h"
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>
#include "noteenums.h"

Kompsitor::Kompsitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kompsitor),
    _notetype(-1),
    _pChoosenNote(nullptr),
    _lastPlacedNotePosX(0),
    _volume(0)
{
    ui->setupUi(this);
    this->setFixedSize(1000,675);
    connect(ui->labelNoteQuater, SIGNAL(isClicked()), this, SLOT(quaterNoteClicked()));
    connect(ui->labelNoteEight, SIGNAL(isClicked()), this, SLOT(eigthNoteClicked()));
    connect(ui->labelNoteHalf, SIGNAL(isClicked()), this, SLOT(halfNoteClicked()));
    connect(ui->labelNoteEgithrest, SIGNAL(isClicked()), this, SLOT(eigthrestNoteClicked()));
    connect(ui->labelNoteQuaterrest, SIGNAL(isClicked()), this, SLOT(quaterrestNoteClicked()));
    connect(ui->labelPlay,SIGNAL(isClicked()), this, SLOT(playButtonClicked()));
    connect(ui->labelPause,SIGNAL(isClicked()), this, SLOT(pauseButtonClicked()));
    connect(ui->labelStop,SIGNAL(isClicked()), this, SLOT(garbageButtonClicked()));
    _pSheet = new Sheet;

}

int Kompsitor::pixelToHeigth(int yPixel)
{
    float eLevel = 386;
    float step = 8;
    int heigth = -1;
    for (int i = 0; i < 12; i++){
        if (yPixel <= (eLevel + (2 - i)*step + step / 2) && yPixel >
                (eLevel + (2 - i)*step - step / 2))
            heigth = i;
    }
    return heigth;
}


void Kompsitor::quaterNoteClicked()
{
    if(_pChoosenNote != nullptr)
        delete _pChoosenNote;
    _pChoosenNote = new ClickingLabel(this);
    _pChoosenNote->setPixmap(QPixmap(":/notes/images/quaterClicked.png"));
    _pChoosenNote->setFixedSize(ui->labelNoteQuater->size());
    _pChoosenNote->move(ui->labelNoteQuater->pos());
    _pChoosenNote->raise();
    _pChoosenNote->show();
    _notetype = quater;
    this->ui->labelNote->setCursor(Qt::PointingHandCursor);
}

void Kompsitor::eigthNoteClicked()
{
    if(_pChoosenNote != nullptr)
        delete _pChoosenNote;
    _pChoosenNote = new ClickingLabel(this);
    _pChoosenNote->setPixmap(QPixmap(":/notes/images/eightClicked.png"));
    _pChoosenNote->setFixedSize(ui->labelNoteEight->size());
    _pChoosenNote->move(ui->labelNoteEight->pos());
    _pChoosenNote->raise();
    _pChoosenNote->show();
    _notetype = eigth;
    this->ui->labelNote->setCursor(Qt::PointingHandCursor);
}

void Kompsitor::halfNoteClicked()
{
    if(_pChoosenNote != nullptr)
        delete _pChoosenNote;
    _pChoosenNote = new ClickingLabel(this);
    _pChoosenNote->setPixmap(QPixmap(":/notes/images/halfClicked.png"));
    _pChoosenNote->setFixedSize(ui->labelNoteHalf->size());
    _pChoosenNote->move(ui->labelNoteHalf->pos());
    _pChoosenNote->raise();
    _pChoosenNote->show();
    _notetype = half;
    this->ui->labelNote->setCursor(Qt::PointingHandCursor);
}

void Kompsitor::eigthrestNoteClicked()
{
    if(_pChoosenNote != nullptr)
        delete _pChoosenNote;
    _pChoosenNote = new ClickingLabel(this);
    _pChoosenNote->setPixmap(QPixmap(":/notes/images/eightrestClicked.png"));
    _pChoosenNote->setFixedSize(ui->labelNoteEgithrest->size());
    _pChoosenNote->move(ui->labelNoteEgithrest->pos());
    _pChoosenNote->raise();
    _pChoosenNote->show();
    _notetype = eigthrest;
    this->ui->labelNote->setCursor(Qt::PointingHandCursor);
}

void Kompsitor::quaterrestNoteClicked()
{
    if(_pChoosenNote != nullptr)
        delete _pChoosenNote;
    _pChoosenNote = new ClickingLabel(this);
    _pChoosenNote->setPixmap(QPixmap(":/notes/images/quaterrestClicked.png"));
    _pChoosenNote->setFixedSize(ui->labelNoteQuaterrest->size());
    _pChoosenNote->move(ui->labelNoteQuaterrest->pos());
    _pChoosenNote->raise();
    _pChoosenNote->show();
    _notetype = quaterrest;
    this->ui->labelNote->setCursor(Qt::PointingHandCursor);
}

void Kompsitor::playButtonClicked()
{
    playNotes();
}

void Kompsitor::pauseButtonClicked()
{
    //Maybe do something?
}

void Kompsitor::garbageButtonClicked()
{
    removeAllNotes();
}

void Kompsitor::changeCursorToForbiddenAndBack()
{
    this->ui->labelNote->setCursor(Qt::ForbiddenCursor);
    Sleep(500);
    this->ui->labelNote->setCursor(Qt::PointingHandCursor);
}

void Kompsitor::mousePressEvent(QMouseEvent *event)
{
    if(_notetype != -1){
        int noteHeigth = pixelToHeigth(event->y());
        if(noteHeigth==-1 || event->x() <= 105 || event->x() >= 930 || event->x() <= _lastPlacedNotePosX + 10){
            changeCursorToForbiddenAndBack();
            return;
        }
        _pSheet->addNote(_notetype,noteHeigth);
        std::vector<Note*> noteVector =_pSheet->getNotes();
        noteVector.back()->printOut(event->x(),this);
        _lastPlacedNotePosX = event->x();
    }
}

void Kompsitor::playNotes()
{
    int vectorSize =_pSheet->getNotes().size();
    for(int i = 0;i<vectorSize; i+=1)
        _pSheet->getNotes().at(i)->playNote(_notePlayer, _volume);
}

void Kompsitor::removeAllNotes()
{
    delete _pSheet;
    _pSheet = new Sheet;
    _lastPlacedNotePosX = 0;
}

Kompsitor::~Kompsitor()
{
    delete ui;
}

void Kompsitor::on_sliderVolume_sliderMoved(int position)
{
    _volume = position;
    qDebug()<<_volume;
}
