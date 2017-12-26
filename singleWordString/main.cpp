#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  char input[] = "Lorem ipsum ipsum dolor sit sit amet, " // строка для разбора
                 "consectetur adipiscing elit, "
                 "consectetur adipiscing elit, "
                 "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                 "Ut enim ad minim veniam, quis nostrud exercitation ullamco "
                 "laboris nisi ut aliquip ex ea commodo consequat. "
                 "laboris nisi ut aliquip ex ea commodo consequat. ";

  int wordsCount = 0; // число слов
  int i = 0; // счетчик 
  while ( input[i] != '\0') { // идем по строке до конца 
    if( input[i] == ' '){ // если нашли -- значит слово закончилось
      wordsCount++; // увеличиваем счетчик
    }
    i++;
  }

  char** words = new char* [wordsCount]; // выделяем память под указатели на слова

  int handleLeft = 0; // флаг на символ в слове при движении Слева -> направо
  for (int i = 0; i < wordsCount; ++i) { //движемся по массиву слов

    int symbolsCount = 0; // количество символов в слове
    while ( input[handleLeft] != ' ') { // пока не встретим пробел идем по стороке

      if( input[handleLeft] != ' '        // если встретили НЕ пробел
          && input[handleLeft] != '.'     // НЕ точку 
          && input[handleLeft] != ','){   // НЕ запятую

        symbolsCount++; // подсчитываем очередной символ
      }

      handleLeft++;// передвигаем флаг в общей строке вправо
    }
    // слово закончилось, мы остановились на пробеле, 
    handleLeft++; // перехрим на начало чледующего слова


    words[i] = new char [symbolsCount+1]; // выделяем память под очередное слово
    // флаг для движения сПрава наЛево
    int handleRight = handleLeft-1; // передаем флаг 

    words[i][symbolsCount] = '\0';// в конец слова вставляем нуль-символ чтобы избавиться от мусора, 
    //иначе в конце члов будет кракозябра
    while (handleRight >= 0 // ПОКА флаг не обнулился
           || input[handleRight] != ' ') { // ИЛИ( || ) символ под флагом не равен пробелу

      if(input[handleRight] != '.' // если не точка
         && input[handleRight] != ' ' // И( && ) не пробел
         && input[handleRight] != ',' // И не запятая
         && symbolsCount >= 0){ // И слово не закончилось

        symbolsCount--; // вычетаем чичло оставшихся сивлово
        words[i][symbolsCount] = input[handleRight]; // записываем слово из строки сПРава наЛево из общей строки

      }

      handleRight--;// передвигаем фолаг влево
    }
  }

  int *substrCount = new int [wordsCount];// массив для подсчета числа встреч определенного слова
  for (int i = 0; i < wordsCount; ++i) { // идем по массву отдельных слов
    substrCount[i] = 0; // число встреч с определённым словос
    for (int j = 0; j < wordsCount; ++j) { // идем по тому же массиву
      if( strcmp(words[i], words[j]) == 0 ){ // срвниваем одно слово со всеми остальными
        substrCount[i]++; // если встретил конкретное слово увеличиваем счетчик
      }
    }
    cout << "word[" << i << "]" << words[i] << endl; // выводим слова по очереди
  }

  cout << "Alone in the darkness: [" << endl; // вывод одиноких солов
  for (int i = 0; i < wordsCount; ++i) {
    if(substrCount[i] == 1){
      cout << i << "\t\"" << words[i] << "\"," << endl;
    }
  }
  cout << "]" << endl;

  return 0;
}
