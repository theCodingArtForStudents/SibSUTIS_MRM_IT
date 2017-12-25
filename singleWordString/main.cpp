#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  char input[] = "Lorem ipsum ipsum dolor sit sit amet, "
                 "consectetur adipiscing elit, "
                 "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                 "Ut enim ad minim veniam, quis nostrud exercitation ullamco "
                 "laboris nisi ut aliquip ex ea commodo consequat. ";

  int wordsCount = 0;
  int i = 0;
  while ( input[i] != '\0') {
    if( input[i] == ' '){
      wordsCount++;
    }
    i++;
  }

  char** words = new char* [wordsCount];

  int handleLeft = 0;
  for (int i = 0; i < wordsCount; ++i) {

    int symbolsCount = 0;
    while ( input[handleLeft] != ' ') {

      if( input[handleLeft] != ' '
          && input[handleLeft] != '.'
          && input[handleLeft] != ','){

        symbolsCount++;
      }

      handleLeft++;
    }

//    cout << "symbolsCount " << symbolsCount << " input << endl;
    handleLeft++;


    words[i] = new char [symbolsCount+1];

    int handleRight = handleLeft-1;

    words[i][symbolsCount] = '\0';
    while (handleRight >= 0
           || input[handleRight] != ' ') {

      if(input[handleRight] != '.'
         && input[handleRight] != ' '
         && input[handleRight] != ','
         && symbolsCount >= 0){

        symbolsCount--;
        words[i][symbolsCount] = input[handleRight];

      }

      handleRight--;
    }
  }

  int *substrCount = new int [wordsCount];
  for (int i = 0; i < wordsCount; ++i) {
    substrCount[i] = 0;
    for (int j = 0; j < wordsCount; ++j) {
      if( strcmp(words[i], words[j]) == 0 ){
        substrCount[i]++;
      }
    }
    cout << "word[" << i << "]" << words[i] << endl;
  }

  cout << "Alone in the darkness: [" << endl;
  for (int i = 0; i < wordsCount; ++i) {
    if(substrCount[i] == 1){
      cout << i << "\t\"" << words[i] << "\"," << endl;
    }
  }
  cout << "]" << endl;

  return 0;
}
