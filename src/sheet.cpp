#include "sheet.h"
#include "quaternote.h"
#include "eigthnote.h"
#include "eigthpausenote.h"
#include "halfnot.h"
#include "quaterpausenote.h"
#include "noteenums.h"

Sheet::Sheet()
{

}

void Sheet::addNote(int noteType, int heigth)
{
    switch(noteType){
    case quater:{
        _notesVector.push_back(new QuaterNote(heigth));
        break;
    }
    case eigth:{
        _notesVector.push_back(new EigthNote(heigth));
        break;
    }
    case half:{
        _notesVector.push_back(new HalfNot(heigth));
        break;
    }
    case quaterrest:{
        _notesVector.push_back(new QuaterPauseNote(heigth));
        break;
    }
    case eigthrest:{
        _notesVector.push_back(new EigthPauseNote(heigth));
        break;
    }
    }
}

std::vector<Note*> Sheet::getNotes()
{
    return _notesVector;
}

Sheet::~Sheet()
{
    int vectorSize = _notesVector.size();
    for(int i = 0; i < vectorSize; i+=1)
        _notesVector.at(i)->~Note();
}
