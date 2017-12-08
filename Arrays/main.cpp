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
    cerr << endl << "!!! Amount of numbers must be biger of 0 !!!" << endl;
    return 1;
  }

  int summ = 0,
      mux = 1,
      zeroCount = 0;;
  bool zero = false;

  for (int i = 0; i < N; ++i) {
    if( i > 0){
      cout << endl << "Enter next number: ";
    }
    else{
      cout << "Enter your number: ";
    }
    cin >> raw[i];

    if( i % 2 == 0 ){
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

  int swap;
  for (int j = 0; j < N; ++j) {

    bool f = false;
    int min = j;

    for (int i = j; i < N - j; ++i) {

      if( raw[i] > raw[i+1] ){
        swap = raw[i+1];
        raw[i + 1] = raw[i];
        raw[i] = swap;

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
