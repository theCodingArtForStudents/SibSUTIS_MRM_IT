#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  uint64_t n = 0; // длинный-длинный беззнаковый целый
  // максимальное значение 2^64
  double sum = 0, // переменная для суммы по условию задачи
         sum2 = 0, // для суммы с взаимнообратным членом ряда
         an = 1, // общий член ряда
         eps = pow(10, 4), // 10^4
         eps2 = pow(10, -4) ; // 10^-4

// (10^n) / n!
  while( an < eps ) // 10^n растет быстрее чем n!
  {// поэтому общий член ряда всегда возрастает и не может стать < 10^-4
    uint64_t k = 1;
    sum += an; // прибавляем общий член ряда к сумме

    for( uint64_t i = n; i > 0; i-- ) // n! == k
      k *= i; // получаем факториал

    double po = pow( 10, n);// возводим 10 в степень n
    an = po/k; // получаем общий член рада == (10^n)/ n!
    n++;
  }

  an = 1;
  n = 0;
  // a если n! / 10^n
  while( an > eps2 ) //  то an совсем скоро станет <= 10^-4
  {
    uint64_t k = 1;
    sum2 += an;

    for( uint64_t i = n; i > 0; i-- ) // n! == k
      k *= i;

    double po = pow( 10, n);
    an = k/po;
    n++;
  }

  cout << endl << "summ is: " << sum << endl;
  cout << endl << "summ is: " << sum2 << endl;
  return 0;
}
