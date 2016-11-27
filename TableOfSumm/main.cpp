#include <iostream>

using namespace std;

int main()
{
  int N = 4,
      M = 4;
  int **C;

  cout << "how many numbers are you want?" << endl;
  cin >> N;
  cin >> M;

  C = new int* [N];
  for (int i = 0; i < N; ++i) {
    C[i] = new int [M];
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if(i == 0 || j == 0)
        C[i][j] = 1;
      else
        C[i][j] = C[i-1][j] + C[i][j-1];

      cout << C[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
