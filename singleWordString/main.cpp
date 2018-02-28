#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[] = "Lorem ipsum ipsum dolor sit sit amet, "
                 "consectetur adipiscing elit, "
                 "consectetur adipiscing elit, "
                 "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                 "Ut enim ad minim veniam, quis nostrud exercitation ullamco "
                 "laboris nisi ut aliquip ex ea commodo consequat. "
                 "laboris nisi ut aliquip ex ea commodo consequat. ";

  size_t wordsCount = 0; // variable for amount of words
  size_t i = 0; // counter for next loop
  while ( input[i] != '\0') { // цикл от начала строки до тех пор, пока не встретим нуль-символ
    if( input[i] == ' '){ // привстрече пробела
      wordsCount++; // увеличиваем количество найденных слов
    }
    i++; // номер следующей итерации 
  }

  char** words = new char* [wordsCount]; // динамический символьный* массив для слов с размером в [количество слов]
  char *lexema = strtok(input, ", .-"); // выделение слов из строки input в массив lexemа c разграничением по разделителю

  for (size_t i = 0; i < wordsCount; ++i) {
    size_t symbolsCount = strlen(lexema); // узнаём размер текущего слова

    words[i] = new char [symbolsCount]; // выделение памяти под количество символов в текущем слове
    words[i] = lexema; // передача слова в массив

    lexema = strtok(NULL, ", .-"); // выделение следующего слова из исходной строки
  }

  int *substrCount = new int [wordsCount]; // динамический массив для подсчета количества повторений слов
  for (size_t i = 0; i < wordsCount; ++i) { // начинаем цикл с нулевого слова
    substrCount[i] = 0; // изначално текущее слово не повторялось ни разу
    for (size_t j = 0; j < wordsCount; ++j) { // цикл для нахождения повторов
      if( strcmp(words[i], words[j]) == 0 ){ // берем очередное слово и сравниваем со всеми остальными
        substrCount[i]++; // если найдено повторение увеличиваем счетчик
      }
    }
  }

  cout << "Alone in the darkness: [" << endl; // одинокие во тьме
  for (size_t i = 0; i < wordsCount; ++i) {// цикл для вывода слов-одиночек
    if(substrCount[i] == 1){ // если текущее слово не повторялось 
      cout << i << "\t\"" << words[i] << "\"," << endl; // выводим это слово
    }
  }
  cout << "]" << endl; // конец вывода

  for(size_t i = 0; i < wordsCount; ++i){
    if(strlen(words[i]) > 0){
      delete [] words[i];
    }
  }
  delete [] words;

  return 0;
}
