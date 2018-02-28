#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char input[] = "Lorem ipsum ipsum dolor sit sit amet, "
                 "consectetur adipiscing elit, "
                 "consectetur adipiscing elit, "
                 "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                 "Ut enim ad minim veniam, quis nostrud exercitation ullamco "
                 "laboris nisi ut aliquip ex ea commodo consequat. "
                 "laboris nisi ut aliquip ex ea commodo consequat. ";

  size_t wordsCount = 0;
  int i = 0;
  while ( input[i] != '\0') {
    if( input[i] == ' '){
      wordsCount++;
    }
    i++;
  }

  char** words = new char* [wordsCount];
  char *lexema = strtok(input, ", .-");

  for (size_t i = 0; i < wordsCount; ++i) {
    size_t symbolsCount = strlen(lexema);

    words[i] = new char [symbolsCount];
    words[i] = lexema;

    lexema = strtok(NULL, ", .-");
  }

//  cout << words[0] << endl;


  int *substrCount = new int [wordsCount];
  for (size_t i = 0; i < wordsCount; ++i) {
    substrCount[i] = 0;
    for (size_t j = 0; j < wordsCount; ++j) {
      if( strcmp(words[i], words[j]) == 0 ){
        substrCount[i]++;
      }
    }
    cout << "word[" << i << "]" << words[i] << endl;
  }

  cout << "Alone in the darkness: [" << endl;
  for (size_t i = 0; i < wordsCount; ++i) {
    if(substrCount[i] == 1){
      cout << i << "\t\"" << words[i] << "\"," << endl;
    }
  }
  cout << "]" << endl;

  return 0;
}
