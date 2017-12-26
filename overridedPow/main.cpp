#include <iostream>

using namespace std;

int64_t overPow(int value, size_t power){
  int64_t result = 1;

  for (size_t i = 0; i < power; ++i) {
    result *= value;
  }

  return result;
}

int64_t overRoot( int value, size_t power ){
  int64_t result = 1;

  while ( value != overPow(result, power)) {
    result++;
  }

  return result;
}

int main()
{

  int result = 0;

  cout << "5^3  " << overPow(5, 3) << endl;
  cout << "2\\/121   " << overRoot(121, 2) << endl;

  return 0;
}
