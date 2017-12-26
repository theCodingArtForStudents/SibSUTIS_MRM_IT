#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  const char path[] = "./test.txt"; //путь файлу

  ifstream fin(path);// создаем файловый поток по указанному пути

  if( ! fin.is_open()){// если файл не открыт
    cerr << " file is not found" << endl;// вероятно его не удалось найти
    return 1; // возвращаем код ошибки
  }

  char buffer[255]; // буфер доля временного хранения слов
  size_t countWords = 0; // счетчик слов
  char **words; // динамический массив слов
  int countFourSymWords = 0; //  количество слов из не более 4 букв
  while ( fin ) { // движемся по стриму пока он не заканчится

    fin >> buffer; // извслекаем очередное словао из потока в переменную

    countWords++; // увеличиваем количество найденных слов
    words = new char* [countWords-1]; // выделяем память под указатель на новое слово

    int symCount = 0;// счетчик символов
    while ( buffer[symCount] != '\0') { // подсчет символов в слове пока не встретим нуль-символ( символ нулевой байт, иначе)
      symCount++; // инкрементиркем счетчик символов
    }

    words[countWords-1] = new char [symCount];// выделяем память длинной в очередное слово
    words[countWords-1] = buffer; // записываем словав массив

    if( symCount <= 4){ // если слово состаит из четырех букв
      countFourSymWords++; // увеличиваем счетчик
      cout << "FOUR SYMBOLS word[" << countFourSymWords << "] " << words[countWords-1] << endl;// выводим это слово
    }
  }

  return 0;
}
