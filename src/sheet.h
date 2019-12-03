#ifndef SHEET_H
#define SHEET_H
#include "note.h"
#include <vector>
class Sheet
{
    public:
        Sheet();
        void addNote(int noteType, int heigth);
        std::vector<Note*> getNotes();
        ~Sheet();
    private:
    std::vector<Note*> _notesVector;

};

#endif // SHEET_H
