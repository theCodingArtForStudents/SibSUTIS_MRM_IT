#include <iostream>
#include <cstdarg>

using namespace std;


// принимает количество чисел
// и саптсок чисел
// находит синимальное
int min(int a, ... )
{
    int *flag = &a;

    int min = *flag;
    while ( flag != 0 ) {
      if(min > *flag){
        min = *flag;
      }
      ++flag;
    }

    return min;
}

int sum (int k, ...)
{
  int *p = &k; //настроили указатель на параметр k
  int s=0;
  for ( ; k!=0;k--)
    s+=*(++p);
  return s;
}


int main()
{
//  cout << "min of 9 6 4 3 2 8 : " << min( 9, 6, 4, 3, 2, 8) << endl;
    cout << "sum: " << sum( 9, 6, 4, 3, 2, 8) << endl;

  return 0;
}
