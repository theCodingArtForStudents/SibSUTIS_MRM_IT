#include <iostream>

using namespace std;

int main()
{
  int N = 0; // amount of numbers
  cout << "How many numbers do you want? : ";
  cin >> N;

  int *raw;
  if( N > 0 ){
    raw = new int[N];
  }
  else{
    cerr << endl << "!!! Amount of numbers must be bigger of 0 !!!" << endl;
    return 1;
  }

  int summ = 0, // переменная для суммы
      mux = 1, // переменная для произведения
      zeroCount = 0; //переменна для подсчета нулей
  bool zero = false; // есть ли ноль
// тип bool хранит в себе заначение либо истина(true) либо лож(false)

  for (int i = 0; i < N; ++i) {
    if( i > 0){
      cout << "Enter next number: ";
    }
    else{
      cout << endl << "Enter your number: ";
    }
    cin >> raw[i];

    if( i % 2 == 0 ){ // если номер элемента делится на 2 без остатка ( % -- остаток от деления)
      mux *= raw[i];
    }

    if( zero ){
      summ += raw[i];
    }

    if( raw[i] == 0 ){

      if( ( ! zero) && ( ! zeroCount) )
        zero = true;
      if( zero && zeroCount )
        zero = false;

      zeroCount++;
    }

  }

  cout << " raw: " ;
  for (int i = 0; i < N; ++i) {
    cout << " " << raw[i] << " ";
  }
  cout << endl;

  int swap; // переменная для замены
  for (int j = 0; j < N; ++j) {

    bool f = false; //
    int min = j; //минимальный номер

    for (int i = j; i < N - j; ++i) {

      if( raw[i] > raw[i+1] ){ // если элемент с текущим номером больше чем следующий
        swap = raw[i+1]; // перемещаем значение следующего в переменную для замены
        raw[i + 1] = raw[i]; // перемещаем значение текущего в следующий
        raw[i] = swap;// перемещаем из замены в текущий элемент

        f = true;
      }

      if( raw[i] < raw[min] )
        min = i;
    }

    if( ! f )
      break;

    if(min != j){
      swap = raw[min];
      raw[min] = raw[j];
      raw[j] = swap;
    }
  }

  cout << "sort raw: " ;
  for (int i = 0; i < N; ++i) {
    cout << " " << raw[i] << " ";
  }
  cout << endl;

  if( ! zeroCount )
    cout << " No zeros in array " << endl ;
  else
    cout << "Summ of numbers between zeros: " << summ << endl;

  cout << "Multiplex of even: " << mux << endl;

  return 0;
}
