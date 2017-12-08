#include "countriestable.h"

CountriesTable::CountriesTable()
{

}

void CountriesTable::addCountries(int id, CountryInfo info)
{
  _rows[id] = info;
}

void CountriesTable::addCountries(int id, int idArtist, WString title)
{
  _rows[id] = SongInfo(idArtist, title);
}
