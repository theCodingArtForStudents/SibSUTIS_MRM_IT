#include <iostream>

using namespace std;
// возведение в степень
int64_t overPow(int value, size_t power){
  int64_t result = 1; // будущий результат

  for (size_t i = 0; i < power; ++i) {
    result *= value; // домнодаем число на себя столько раз какая степень указана
  }

  return result;// возвращаем резкльтат наружу
}

int64_t overRoot( int value, size_t power ){
  int64_t result = 1;

  while ( value != overPow(result, power)) { // пока результат возведенный в указанную степень не сравняется с числом
    result++; // увеличиваем число на 1
  }

  return result;
}

int main()
{

  int result = 0;

  cout << "5^3  " << overPow(5, 3) << endl; // выводим 5 в степени 3
  cout << "2\\/121   " << overRoot(121, 2) << endl; // ищем корень и 121

  return 0;
}
