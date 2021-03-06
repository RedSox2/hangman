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
string urUsername;
char theUsername;

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
  std::cout << flush;
  /*
   * Beginning of program
   * clear screen an introduce game/rules
   * 
   */
  clearScreen();
  std::cout << endl
       << endl
       << "WELCOME TO HANGMAN!!" << endl
       << endl;
  std::cout << endl
       << "----------------------------------------------------------------------------------------------------------" << endl
       << endl;
  std::cout << "Here are the rules:\n* you must enter one letter\n* that letter cannot be a symbol\n* you have ten guesses\n* correct guesses won't count against you\n* you cannot guess the same letter twice\n* and finally, if you need to give up enter any numeral\n* P.S. lower scores are better since you score is equal to the number of incorrect guesses you got" << endl
       << endl
       << endl
       << endl;
  std::cout << "If you would like to display the highscore, we need your computer username. We assure you this is perfectly safe. If you are however suspicious, then you may enter 0 in which we will not dusplay the highscore. Also please check your username, if you go to file explorer and 'This PC' then Users. Then take note of which one you are and then put it here." << endl;
  std::cout << "What is your username? ";
  std::cin >> urUsername;
  istringstream myUsername(urUsername);
  theUsername = myUsername.peek();
  if (isdigit(theUsername))
  {
    cout << "Ok, no highscores then" << endl;
  }
  // show the current highscore
  displayHighScore();

  
  
  while (guessedWord != word && guesses > 0)
  {
    // print how many guesses you have left, the letter you have guessed so far, and what of the word you have guessed
    std::cout << "You have " << guesses << " incorrect guesses left" << endl;
    std::cout << "The word so far is\n\n";
    for (int i = 0; i < word.length(); i++)
    {
      if (i == word.length() - 1)
      {
        std::cout << guessedWord[i] << endl;
      }
      else
      {
        std::cout << guessedWord[i] << " ";
      }
    }
    std::cout << "\n\nYou have guessed: ";
    for (int i = 0; i < guessed.size(); ++i)
    {
      if (guessed[i])
      {
        std::cout << static_cast<char>(i + 'A') << ", ";
      }
    }
    // get the user's guess
    std::cout << "\nWhat is your guess?" << endl;
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
        std::cout << flush;
        clearScreen();
        std::cout << "That is not a letter, please try again" << endl
             << endl
             << endl;
        continue;
      }
    }
    // did they already guess this letter ?
    else if (guessed[guess - 'A'])
    {
      std::cout << flush;
      clearScreen();
      std::cout << "You have already guessed this." << endl
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
        std::cout << "Correct, \'" << guess << "\' is in the word." << endl
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
        std::cout << flush;
        clearScreen();
        std::cout << "Incorrect, \'" << guess << "\' is not in the word." << endl
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
    std::cout << flush;
    clearScreen();        // clear screen
    std::cout << "YOU WIN!" << endl;
    std::cout << "The word was " << word << endl;
    std::cout << "You took " << incrtGuesses << " incorrect guesses." << endl;
    checkHighScore(incrtGuesses);       // check if they got a high score
    displayHighScore();       // display the current high score

    sleep(10);        // wait ten seconds before closing the program
  }
  else        // if they lost
  {
    std::cout << flush;
    clearScreen();        // clear screen
    std::cout << "YOU WERE HANGED!" << endl;
    std::cout << "The word was " << word << endl;
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
  if (isdigit(theUsername))
  {
    cout << "Highscores are disabled";
  }
  else
  {

  
  #ifdef _WIN32
  ifstream highScoreDisplay;
  
  string displayStr;
  std::cout << endl
       << endl
       << endl
       << "The current high score is: " << endl
       << endl
       << endl;
  highScoreDisplay.open(("C:\\Users\\" + urUsername + "\\downloads\\hangman-master\\hangman-master\\highscores.txt"));
  if (highScoreDisplay.is_open())
  {
    while (!highScoreDisplay.eof())
  {
    getline(highScoreDisplay, displayStr);
    std::cout << "" << displayStr << "\n";
  }
  #else
  highScoreDisplay.open("highscores.txt")
  if (highScoreDisplay.is_open())
  {
    string displayStr;
    std::cout << endl
      << endl
      << endl
      << "The current high score is: " << endl
      << endl
      << endl;

    while (!highScoreDisplay.eof())
    {
      getline(highScoreDisplay, displayStr);
      std::cout << "" << displayStr << "\n";
    }
  }
  
  #endif
  }
  }
  
}

// chech the current high score against n, and replace if necessary
void checkHighScore(int score)

{
  if (isdigit(theUsername)) 
  {
    cout << "Highscores are disabled";
  }
  else
  {
  
  
  ofstream highScores;
  string urName;
  time_t myTime = time(0);
  char *dateTime = ctime(&myTime);
  #ifdef _WIN32
  if (score < stoi(readLine("C:\\Users\\" + urUsername + "\\downloads\\hangman-master\\hangman-master\\highscores.txt", 4)))
  {
    std::cout << "Yay, You got a high score!" << endl;
    std::cout << "Please enter your name here: ";
    cin >> urName;
    highScores.open("C:\\Users\\" + urUsername + "\\downloads\\hangman-master\\hangman-master\\highscores.txt");
    if(highScores.is_open()) 
    {
      highScores << "By: " << urName << endl;
      highScores << "Date: " << dateTime;
      highScores << "Score: " << endl;
      highScores << score;
      highScores.close();
    } else
    {
      std::cout << "Unable to open highscores file. Sorry!" << endl;
    }
    
    
  }
  #else
  if (score < stoi(readLine("highscores.txt", 4)))
  {
    std::cout << "Yay, You got a high score!" << endl;
    std::cout << "Please enter your name here: ";
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
}



void clearScreen(void)
{
  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif

}

