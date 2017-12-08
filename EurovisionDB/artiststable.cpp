#include "artiststable.h"

ArtistsTable::ArtistsTable()
{

}

void ArtistsTable::addRow(int id, FullName fullName)
{
  _rows[id] = fullName;
}

void ArtistsTable::addRow(int id, WString name, WString surname)
{
  _rows[id] = FullName(name, surname);
}
