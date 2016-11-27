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
  /// max of abs \\completed
  /// summ of items between negative numbers \\completed
  ///
  /// Sotr the array that zeros has been settled in a tail \\completed

  max = arr[0];

  for (int i = 0; i < N; ++i) {
    if ( max < abs(arr[i]))
     max = arr[i];
  }

  cout << "Max absolute value have this item: " << max << endl;

  int negPos[N],
      countNegPos = 0,
      zerosCount = 0;

  for (int i = 0; i < n; ++i) {
    if( arr[i] < 0){
      negPos[i] = i;
      countNegPos++;
    }
    if ( arr[i] == 0 )
      zerosCount++;
  }

  int summsArray[N];

  for (int i = 0; i < N; ++i) {
    summsArray[i] = 0;
  }

  if ( countNegPos = 0 ) {
    cout << "In your series don`t have negative numbers." << endl;
  } if ( countNegPos = 1 ) {
    for (int i = 0; i < N; ++i) {
      if( i != negPos[0] )
        summsArray[0] += arr[i];
    }

    cout << "In row just one negative number.\n"
            "Summ items besides on " << negPos[0] << " position is: " << summsArray[0] << endl;

  } else {

    cout << "Summs between positions:" << endl;

    for (int i = 0; i < countNegPos; ++i)
    {
      for (int j = negPos[i] + 1; j < negPos[i+1]; ++j)
        summsArray[i] += arr[j];

      if( summsArray[i] != 0 )
        cout << "from pos[" << i << "]: " << negPos[i]
             << " to pos[" << i+1 << "]: " << negPos[i+1]
             << " equally: " << summsArray[i] << endl;
    }
  }

  int tmp = 0;
  for (int j = 0; j < N; ++j) {
    for (int i = 0; i < N-1; ++i) {
      if( arr[i] < arr[i+1] ){
        tmp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = tmp;
      }
    }
  }

  cout << "All zeros in the tail: " << endl;
  for (int i = 0; i < N; ++i) {
    cout << arr[i] << " ";
  }

  cout << endl;

  return 0;
}
