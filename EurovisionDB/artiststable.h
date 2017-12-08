#ifndef ARTISTSTABLE_H
#define ARTISTSTABLE_H

#include <map>

#include "WString"

struct FullName{
  FullName(){}
  FullName(WString title)
    : _title(title){}
  WString _title = L"Lordi";
};

typedef std::map<int, FullName> Artists;

class ArtistsTable
{
private:
  Artists _rows;
public:
  ArtistsTable();

  void addRow(int id, FullName fullName);
  void addRow(int id, WString name, WString surname);
};

#endif // ARTISTSTABLE_H
