#include <iostream>
#include <map>

using namespace std;

int main()
{
  string input;

  cout << "Please enter your string: ";

  getline(cin, input);

  if( input.back() != '.'){
    cout << "You forgot '.' !" << endl;
    input.push_back('.');
  }
  cout << "Your string: \"" << input << '\"' << endl << endl;

  map<string, int> words;

  string word;
  for( auto letter : input ){
    if( letter != ' ' && letter != '.' ){
      word.push_back(letter);
      continue;
    }

    if( words.find(word) == words.end() )
      words[word] = 1;
    else
      words[word]++;

    word = "";
  }

  cout << "Alone in the darkness: [" << endl;
  for( auto _word : words){
    if( _word.second == 1){
      cout << "\t\"" << _word.first << "\"," << endl;
    }
  }
  cout << "]" << endl;


  return 0;
}
