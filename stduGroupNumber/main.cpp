#include <iostream>

using namespace std;

int main()
{
  int groupNumber = 0;
  cout << "Pleas enter group number here: ";
  cin >> groupNumber;
// младшая цифра номера не значит ни чего
  groupNumber /= 10; // делим на 10 что бы убрать младшую цифру
// средняя цифра номера означает год поступления в вуз
  int year = groupNumber % 10; // если разделить число на 10 то остатком
  // от деления будет как раз средняя цифра от введённого числа
  groupNumber /= 10; // уираем еще цифру т.к дальше требуется старшая от введённого

  string faculty;// строковая переменная для названия факультета
  // оператор ветсвления с множетвом вариантов
  switch ( groupNumber ) // в данной переменной осталась одна -- старшая цифра
  { // выбераем факультет в зависимоти от цифры
  // слуяай(case) с единичкой
  case 1:
    faculty = "history";
    break;
  case 2:// очередной случай
    faculty = "economy";
    break;
  case 3:
    faculty = "jurisprudence";
    break;
  case 4:
    faculty = "mathematics";
    break;
  case 5:
    faculty = "physics";
    break;
  case 6:
    faculty = "chimestry";
    break;
  case 7:
    faculty = "biological";
    break;
  case 8:
    faculty = "philological";
    break;
  case 9:
    faculty = "geografy";
    break;
  }

  cout << endl  << "faculty " << faculty
       << " year 200" << year;
  return 0;
}
