#include <iostream>

using namespace std;

int main()
{
  int groupNumber = 0;
  cout << "Pleas enter group number here: ";
  cin >> groupNumber;

  groupNumber /= 10;

  int year = groupNumber % 10;
  groupNumber /= 10;

  string faculty;
  switch ( groupNumber % 10 )
  {
  case 1:
    faculty = "history";
    break;
  case 2:
    faculty = "economy";
    break;
  case 3:
    faculty = "jurisprudence";
    break;
  case 4:
    faculty = "mathematics";
    break;
  case 5:
    faculty = "physics";
    break;
  case 6:
    faculty = "chimestry";
    break;
  case 7:
    faculty = "biological";
    break;
  case 8:
    faculty = "philological";
    break;
  case 9:
    faculty = "geografy";
    break;
  }

  cout << endl  << "faculty " << faculty
       << " year 200" << year;
  return 0;
}
