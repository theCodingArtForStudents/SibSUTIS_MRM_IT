#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n = 0;
  double sum = 0;
  cout << "Please enter number: ";
  cin >> n;

  int k = 1;
  for( int i = n; i > 0; i-- )
    k *= i;

  do
  {
    sum += pow( 10, n)/k;
  }
  while( sum < pow(10, -4) );

  cout << endl << "summ is: " << sum << endl;
  return 0;
}
