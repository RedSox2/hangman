#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime.>
#include <set>
#include <array>
#include <unistd.h>

using namespace std;

// MAIN Function
int main()
{
  string fiveLetter[26] = {"abode"};
  string fourLetter[26] = {};
  string sixLetter[26] = {};
  string sevenLetter[26] = {};
  string myGuess;

  int wordPick;
  int length;
  string word;
  string guessedWord;
  int guesses = 15;
  auto guessed = array<bool, 26>();

  // srand(time(NULL));
  // cout << "What length would you like the word to be? ";
  // cin >> length;
  // switch (length)
  // {
  //   case 4:
  //     wordPick = rand() % 26;
  //     // word = fourLetter[wordPick];
  //     break;
  //   case 5:

  //     break;
  //   case 6:

  //     break;
  //   case 7:

  //     break;
  //   default:

  //     break;

  // }

  word = "OBVIOUS";
  guessedWord = "_______";

  cout << endl
       << endl
       << "WELCOME TO HANGMAN!!" << endl
       << endl;
  cout << endl
       << "----------------------------------------------------------------------------------------------------------" << endl
       << endl;
  cout << "Here are the rules:\n* you must enter one letter\n* that letter cannot be a symbol\n* you have ten guesses\n* correct guesses won't count against you\n* you cannot guess the same letter twice\n* and finally, if you need to give up enter any numeral" << endl
       << endl
       << endl
       << endl;
  while (guessedWord != word && guesses > 0)
  {
    cout << "You have " << guesses << " incorrect guesses left" << endl;
    cout << "The word so far is\n\n";
    for (int i = 0; i < word.length(); i++)
    {
      if (i == word.length() - 1)
      {
        cout << guessedWord[i] << endl;
      }
      else
      {
        cout << guessedWord[i] << " ";
      }
    }
    cout << "\n\nYou have guessed: ";
    for (int i = 0; i < guessed.size(); ++i)
    {
      if (guessed[i])
      {
        cout << static_cast<char>(i + 'A') << ", ";
      }
    }
    cout << "\nWhat is your guess?" << endl;
    cin >> myGuess;
    istringstream myGuess2(myGuess);
    char guess = toupper(myGuess2.peek());
    if (isalpha(guess) == false)
    {
      if (isdigit(guess) == true)
      {
        break;
      }
      else
      {
        cout << "That is not a letter, please try again" << endl;
        continue;
      }
    }
    else if (guessed[guess - 'A'])
    {
      cout << "You have already guessed this." << endl;
      continue;
    }
    else
    {

      guessed[guess - 'A'] = true;
      size_t found = word.find(guess);
      if (found != string::npos)
      {
        cout << "Correct, \'" << guess << "\' is in the word." << endl;
        for (int i = 0; i < word.length(); i++)
        {
          if (word[i] == guess)
          {
            guessedWord[i] = guess;
          }
        }
      }
      else
      {
        cout << "Incorrect, \'" << guess << "\' is not in the word." << endl;
        guesses--;
      }
      cout << "-----------------------------------------------------" << endl;
    }
  }

  if (guessedWord == word)
  {
    cout << endl
         << endl
         << endl
         << "YOU WIN!" << endl;
    cout << "The word was " << word << endl;
    sleep(10);
  }
  else
  {
    cout << endl
         << endl
         << endl
         << "YOU WERE HANGED!" << endl;
    cout << "The word was " << word << endl;
    sleep(10);
  }

  return 0;
}