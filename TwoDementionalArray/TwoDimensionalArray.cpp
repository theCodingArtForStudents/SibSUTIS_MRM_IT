#include <iostream>

using namespace std;

int main()
{
  int n;

  cout << "Pleas enter array`s size: ";
  cin >> n;

  int **array = new int* [n];
  for (int i = 0; i < n; ++i) {
    array[i] = new int[n];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {

      if( j == n - i - 1 ){
        array[i][j] = 1;
      }
      else if( j < n - i - 1 ){
        array[i][j] = 0;
      }
      else{
        array[i][j] = 2;
      }

      cout << array[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
