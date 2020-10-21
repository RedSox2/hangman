#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string readLine(const string& filename, int N);
void checkHighScore(int n, const string& filename);

int main () 

{
  int score = 5;
  // if (score > stoi(ReadNthLine(("test.txt"), 3)))
  // {
  //   cout << "NICE THAT IS A HIGHSCORE!";
  // }
  // else
  // {
  //   cout << "Sorry, not a highscore";
  // }
  checkHighScore(5, "test.txt");
  
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

void checkHighScore(int n, const string& filename) 
{
  ofstream highScores;
  string urName;
  time_t myTime = time(0);
  char* dateTime = ctime(&myTime);

  if (n < stoi(readLine(filename, 4)))
    {
      cout << "Yay, You got a high score!" << endl;
      cout << "Please enter your name here: ";
      cin >> urName;
      highScores.open("testScores.txt");
      highScores << "By: " << urName << endl;
      highScores << "Date: " << dateTime;
      highScores << "Score: " << endl;
      highScores << n;
      highScores.close();
    }
    
    
}