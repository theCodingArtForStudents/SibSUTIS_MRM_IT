#ifndef COUNTRIESTABLE_H
#define COUNTRIESTABLE_H

#include <map>

#include <WString>

struct CountryInfo{
  WString _title;
  int _idArtist;
};

typedef std::map<int, CountryInfo> Countries;

class CountriesTable
{
private:
  Countries _rows;
public:
  CountriesTable();

  void addCountries(int id, CountryInfo info);
  void addCountries(int id, int idArtist, WString title);
};

#endif // COUNTRIESTABLE_H
