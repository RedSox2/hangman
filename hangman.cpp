#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime.>
#include <set>
#include <array>
#include <unistd.h>

using namespace std;
string readLine(const string& filename, int N);

// MAIN Function
int main()
{
  string pickWords[15] = {"ADOBE", "BLIZZARD", "CYCLE", "QUIZZES", "PUPPY", "LUCKY", "OBVIOUS", "SPHINX", "VORTEX", "ZIGZAG", "FJORD", "GLOWWORM", "PHLEGM", "UNZIP", "SUBWAY"};
  
  string myGuess;

  int wordPick;
  int length;
  string word;
  int n;
  int guesses = 15;
  int incrtGuesses = 0;
  auto guessed = array<bool, 26>();
  time_t myTime = time(0);
  char* dateTime = ctime(&myTime);
  ofstream highScores;
  string urName;
  string displayStr;
  ifstream highScoresDisplay;

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
  srand(time(NULL));
  wordPick = rand() % 15;
  


  word = pickWords[wordPick];
  n = word.length();
  string guessedWord (n, 95);
  

  cout << endl
       << endl
       << "WELCOME TO HANGMAN!!" << endl
       << endl;
  cout << endl
       << "----------------------------------------------------------------------------------------------------------" << endl
       << endl;
  cout << "Here are the rules:\n* you must enter one letter\n* that letter cannot be a symbol\n* you have ten guesses\n* correct guesses won't count against you\n* you cannot guess the same letter twice\n* and finally, if you need to give up enter any numeral\n* P.S. lower scores are better since you score is equal to the number of incorrect guesses you got" << endl
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
        incrtGuesses++;
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
    cout << "You took "<< incrtGuesses << " incorrect guesses." << endl;
    if (incrtGuesses < stoi(readLine("highscores.txt", 4)))
    {
      cout << "Yay, You got a high score!" << endl;
      cout << "Please enter your name here: ";
      cin >> urName;
      highScores.open("highscores.txt");
      highScores << "By: " << urName << endl;
      highScores << "Date: " << dateTime;
      highScores << "\bScore: " << endl;
      highScores << incrtGuesses;
      highScores.close();
    }
    cout << "The current high score is: " << endl;

    highScoresDisplay.open("highscores.txt", ios::in);
    if (highScoresDisplay.is_open()) 
    {
      while (getline(highScoresDisplay, displayStr))
      {
        cout << displayStr << endl;
      }
      highScores.close();
    }
    
    

    
    

    sleep(10);
  }
  else
  {
    cout << endl
         << endl
         << endl
         << "YOU WERE HANGED!" << endl;
    cout << "The word was " << word << endl;
    cout << "The current high score is: " << endl;

    highScoresDisplay.open("highscores.txt", ios::in);
    if (highScoresDisplay.is_open()) 
    {
      while (getline(highScoresDisplay, displayStr))
      {
        cout << displayStr << endl;
      }
      highScores.close();
    }
    sleep(10);
  }

  return 0;
}


string readLine(const string& filename, int N)
{
   std::ifstream in(filename.c_str());

   std::string s;
   //for performance
   s.reserve(100);    

   //skip N lines
   for(int i = 0; i < N-1; ++i)
       std::getline(in, s);

   std::getline(in,s);
   return s; 
}