#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  const char path[] = "./test.txt"; //путь файлу

  ifstream fin(path);

  if( ! fin.is_open()){
    cerr << " file is not found" << endl;
    return 1;
  }

  char ch[255];
  size_t countWords = 0;
  char **words;

  while ( fin ) {

    fin >> ch;

    countWords++;
    words = new char* [countWords-1];

    int symCount = 0;
    while ( ch[symCount] != '\0') {
      symCount++;
    }

    words[countWords-1] = new char [symCount];
    words[countWords-1] = ch;
    if( symCount == 4){
      cout << "word[" << countWords-1 << "] " << words[countWords-1] << endl;
    }
  }

  return 0;
}
