#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int N = 45;
  float arr[N];

  cout << "please entering count of your numbers: ";
  cin >> N;

  cout << "entring your numbers:" << endl;

  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  ///todo
  ///
  /// max of abs <---------making
  /// summ of items between negative numbers
  ///
  /// Sotr the array that zeros has been settled in a tail

  max = arr[0];

  for (int i = 0; i < N; ++i) {
    if ( max < abs(arr[i]))
     max = arr[i];
  }

  return 0;
}
