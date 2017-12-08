#include "songtable.h"

SongTable::SongTable()
{

}

void SongTable::addSong(int id, SongInfo info)
{
  _rows[id] = info;
}

void SongTable::addSong(int id, int idArtist, WString title)
{
  _rows[id] = SongInfo(idArtist, title);
}
