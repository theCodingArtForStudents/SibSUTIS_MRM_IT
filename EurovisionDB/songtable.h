#ifndef SONGTABLE_H
#define SONGTABLE_H

#include <map>

#include <WString>

struct SongInfo{
  SongInfo(){}
  SongInfo(int id, WString title)
    : _idArtist(id), _title(title){}
  int _idArtist;
  WString _title = L"Hard Rock Hallelujah";
};

typedef std::map<int, SongInfo> Songs;

class SongTable
{
private:
  Songs _rows;
public:
  SongTable();

  void addSong(int id, SongInfo info);
  void addSong(int id, int idArtist, WString title);
};

#endif // SONGTABLE_H
