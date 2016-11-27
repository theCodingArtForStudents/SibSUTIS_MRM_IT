#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int N = 45; // переменная для размера массива
  float *arr; // указатель на массив размером N

  cout << "please entering count of your numbers: "; // пожалуйста введите количество ваших чисел
  cin >> N; // процедура ввода

  arr = new float [N]; // создаем массив размером N по адресу arr

  cout << "entring your numbers:" << endl; // введите ваши числа


  for (int i = 0; i < N; ++i) { // запроняем массив рядом чисел
    cin >> arr[i];
  }

  float max = arr[0]; // создаем переменную мах и присваиваем значение элемента номер 0
  int countNegPos = 0; // колтчество отрицательных чисел
  for (int i = 0; i < N; ++i) { // идем от начала до конца массива
    if ( abs(max) < abs(arr[i])) // если мах меньше модуля очередного элемента
     max = arr[i]; // перемещаем значение последнего в мах

    if (arr[i] < 0)// если элемент отрицтелен
      countNegPos++;// запишем что таких на 1 большe
  }

  cout << "Max absolute value having this item: " << max << endl; // отображаем на экране мах

  int *negPos = new int[countNegPos]; // позиция отрицательного числа

  int j = 0;
  for (int i = 0; i < N; ++i) { // цикл для подсчета отрицательных и нулевых значений
    if( arr[i] < 0){ // если элемент отрицтелен
      negPos[j] = i; // запомним его положение в ряду
      j++;
    }
  }

  float *summsArray = new float [countNegPos]; // массив для сумм эдементов между отрицательными

  for (int i = 0; i < N; ++i) { // занулим знацения
    summsArray[i] = 0;
  }

  if ( countNegPos == 0 ) { // если отрицательных нет
    cout << "In your series don`t have negative numbers." << endl; // сообщим печальный факт
  } if ( countNegPos == 1 ) { // если одно
    for (int i = 0; i < N; ++i) { // суммируем все кроме отрицательного
      if( i != negPos[0] ) // пример: [1.6; 7.2; -3; 8; 6.7] в сумме будут все кроме -3
        summsArray[0] += arr[i]; // запишем единственную сумму
    }

    cout << "In row just one negative number.\n" // В ряду только одно отриц. число
            "Summ items besides on " << negPos[0] << " position is: " << summsArray[0] << endl;
              // сумма элементов кроме на ^^^^^^^       позиции равно    ^^^^^^^^^
  } else {

    cout << "Summs between positions:" << endl; // сумма между позициями

    for (int i = 0; i < countNegPos; ++i) // от первой до последней отрицательной позиции
    {
      for (int j = negPos[i] + 1; j < negPos[i+1]; ++j)// от отрицательнго до отрицательнго
        summsArray[i] += arr[j]; // суммируем и запоминем

      if( summsArray[i] != 0 ) // если сумма не нулевая
        cout << "from pos[" << negPos[i] << "]"  // от позиции №i
             << " to pos[" << negPos[i+1] << "]" // до очередной позиции
             << " equally: " << summsArray[i] << endl; // (сумма) равна: #
    }
  }

  float tmp = 0; // временная
  for (int j = 0; j < N; ++j) { // проходим по массиву столько раз сколько там чисел(чтоб наверняка)
    for (int i = 0; i < N-1; ++i) { // цикл сортировки
      if( abs(arr[i]) < abs(arr[i+1]) ){ // если элемент под номером i больше чем -- под № i+1
        tmp = arr[i+1];  // тогда
        arr[i+1] = arr[i]; // меняем их
        arr[i] = tmp; // местами
      }
    }
  }

  cout << "All zeros in the tail: " << endl; //все нули в хвосте
  for (int i = 0; i < N; ++i) { // выводим отсортированный массив
    cout << arr[i] << " ";
  }

  cout << endl; // оконечный перенос строки

  delete[] arr;
//  delete summsArray;
  delete[] negPos;

  return 0;
}
