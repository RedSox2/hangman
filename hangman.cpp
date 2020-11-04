#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <array>
#include <unistd.h>

using namespace std;
string readLine(const string &filename, int N);
void displayHighScore(void);
void checkHighScore(int n);
void clearScreen(void);

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
  #ifdef _WIN32
  array<bool, 26> guessed{};
  #else
  array<bool, 26> guessed;
  #endif
<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> 45788458f18eb04630850d430850f6c5ec7eb584
>>>>>>> 52e780004c36eeb54260980e96209f7e1bd6f14e
  time_t myTime = time(0);
  char *dateTime = ctime(&myTime);
  ofstream highScores;
  string urName;
  string displayStr;
  ifstream highScoresDisplay;

  srand(time(NULL));
  wordPick = rand() % 15;

  word = pickWords[wordPick];
  n = word.length();
  string guessedWord(n, 95);
  cout << flush;
  /*
   * Beginning of program
   * clear screen an introduce game/rules
   * 
   */
  clearScreen();
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
  // show the current highscore
  displayHighScore();
  while (guessedWord != word && guesses > 0)
  {
    // print how many guesses you have left, the letter you have guessed so far, and what of the word you have guessed
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
    // get the user's guess
    cout << "\nWhat is your guess?" << endl;
    cin >> myGuess;
    istringstream myGuess2(myGuess);
    char guess = toupper(myGuess2.peek());
    // check if user has entered a letter, or if they have guessed a letter they have already guessed, or if they give up
    if (isalpha(guess) == false)
    {
      // did they give up?
      if (isdigit(guess) == true)
      {
        break;
      }
      // did they enter a non-alphabetical character?
      else
      {
        cout << flush;
        clearScreen();
        cout << "That is not a letter, please try again" << endl
             << endl
             << endl;
        continue;
      }
    }
    // did they already guess this letter ?
    else if (guessed[guess - 'A'])
    {
      cout << flush;
      clearScreen();
      cout << "You have already guessed this." << endl
           << endl
           << endl;
      continue;
    }
    // if they haven't done anything wrong
    else
    {

      guessed[guess - 'A'] = true;        // set that letter that they guessed to 'true'
      size_t found = word.find(guess);
      // check if their letter is correct
      if (found != string::npos)        // if letter is correct
      {
        clearScreen();
        cout << "Correct, \'" << guess << "\' is in the word." << endl
             << endl
             << endl
             << flush;
        for (int i = 0; i < word.length(); i++)
        {
          if (word[i] == guess)
          {
            guessedWord[i] = guess;
            continue;
          }
        }
      }
      else        // if it's incorrect
      {
        cout << flush;
        clearScreen();
        cout << "Incorrect, \'" << guess << "\' is not in the word." << endl
             << endl
             << endl
             << flush;

        guesses--;
        incrtGuesses++;
        continue;
      }
    }
  }
  // check if they won or lost
  if (guessedWord == word)        // if they won
  {
    cout << flush;
    clearScreen();        // clear screen
    cout << "YOU WIN!" << endl;
    cout << "The word was " << word << endl;
    cout << "You took " << incrtGuesses << " incorrect guesses." << endl;
    checkHighScore(incrtGuesses);       // check if they got a high score
    displayHighScore();       // display the current high score

    sleep(10);        // wait ten seconds before closing the program
  }
  else        // if they lost
  {
    cout << flush;
    clearScreen();        // clear screen
    cout << "YOU WERE HANGED!" << endl;
    cout << "The word was " << word << endl;
    displayHighScore();     // display the current high score
    sleep(10);        // wait ten seconds befpre closing the program
  }

  return 0;       // end main function
}

/*
 * string readLine(const string& filename, int N):
 * function to read the nth line of a txt file
 * (in this case to read the high score)
 * 
 * void displayHighScore(void):
 * function to display the current high score
 * reads the lines of the file and prints them out as it reads them
 * 
 * void checkHighScore(int n):
 * checks current high score and replaces it if neccesary 
 * n is the score to check
 * (also uses readLine function)
 * 
 */


// read line N of file filename
string readLine(const string& filename, int N)
{
  std::ifstream in(filename.c_str());

  std::string s;
  //for performance
  s.reserve(100);

  //skip N lines
  for (int i = 0; i < N - 1; ++i)
    std::getline(in, s);

  std::getline(in, s);
  return s;
}

// display current high score
void displayHighScore(void)
{
  #ifdef _WIN32
  ifstream highScoreDisplay("C:\\Downloads\\hangman-master\\highscores.txt");
  string displayStr;
  cout << endl
       << endl
       << endl
       << "The current high score is: " << endl
       << endl
       << endl;

  while (!highScoreDisplay.eof())
  {
    getline(highScoreDisplay, displayStr);
    cout << "" << displayStr << "\n";
  }
  #else
  ifstream highScoreDisplay("\highscores.txt");
  string displayStr;
  cout << endl
    << endl
    << endl
    << "The current high score is: " << endl
    << endl
    << endl;

  while (!highScoreDisplay.eof())
  {
    getline(highScoreDisplay, displayStr);
    cout << "" << displayStr << "\n";
  }
  #endif
}

// chech the current high score against n, and replace if necessary
void checkHighScore(int score)
{
  ofstream highScores;
  string urName;
  time_t myTime = time(0);
  char *dateTime = ctime(&myTime);
  #ifdef _WIN32
  if (score < stoi(readLine("C:\\downloads\\hangman-master\\hangman-master\\highscores.txt", 4)))
  {
    cout << "Yay, You got a high score!" << endl;
    cout << "Please enter your name here: ";
    cin >> urName;
    highScores.open("C:\\downloads\\hangman-master\\hangman-master\\highscores.txt");
    highScores << "By: " << urName << endl;
    highScores << "Date: " << dateTime;
    highScores << "Score: " << endl;
    highScores << score;
    highScores.close();
  }
  #else
  if (score < stoi(readLine("highscores.txt", 4)))
  {
    cout << "Yay, You got a high score!" << endl;
    cout << "Please enter your name here: ";
    cin >> urName;
    highScores.open("highscores.txt");
    highScores << "By: " << urName << endl;
    highScores << "Date: " << dateTime;
    highScores << "Score: " << endl;
    highScores << score;
    highScores.close();
  }
  #endif
}



void clearScreen(void)
{
  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif

}

