#include "deletebarline.h"

#include <powertabdocument/system.h>

using std::shared_ptr;

DeleteBarline::DeleteBarline(shared_ptr<System> system, Barline* barline) :
    system(system),
    barline(barline),
    barlineCopy(new Barline(*barline))
{
    setText(QObject::tr("Delete Barline"));
}

void DeleteBarline::redo()
{
    system->RemoveBarline(barline->GetPosition());
}

void DeleteBarline::undo()
{
    barline = new Barline(*barlineCopy);
    system->InsertBarline(barline);
}
