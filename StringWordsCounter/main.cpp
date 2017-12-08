#include <iostream>
#include <string.h>

using namespace std;

int main()
{
//  char text[] = "Lorem ipsum dolor sit amet. "
//                "Sed ut labore et quas molestias excepturi. "
//                "Culpa, qui in ea voluptate velit esse, quam nihil impedit. "
//                "Quas molestias excepturi sint, obcaecati cupiditate non numquam eius.";


  char **text;
  char inC;

  int wordsCount = 1,
      symbolCount = 0;

  while ( cin >> inC ) {
    text = new char* [wordsCount];
    if ( inC != ' ' ) {
      symbolCount++;
      text[wordsCount-1] = new char [symbolCount];

      text[wordsCount-1][symbolCount-1] = inC;
    }
    wordsCount++;
  }



//  char tmp[128][32];
//  int i = 0,
//      jj = 0;

//  char c = text[0];

//  text = strtok(text, " ,.");

//  while( text != NULL ){

//    cout << text << endl;
//    text = strtok(NULL, " ,.");

//  }



  return 0;
}
