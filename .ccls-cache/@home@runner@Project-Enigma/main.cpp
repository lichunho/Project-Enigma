#include "rotorOperations.h"
//#include <algorithm>
#include <iostream>
//#include <fstream>
//#include <vector>
using namespace std;


int main() 
{
  vector <char> message;
  string userInput;

  cout << "Input the message you would like to be encrypted" << endl;
  cout << "=> ";
  cin >> userInput;

  for (int i = 0; i < userInput.size(); i ++)
  {
    message.push_back(toupper(userInput[i]));
  }

  rotorOperations(message);

  cout << "Performing the encryption: " << endl;
  for (int i = 0; i < message.size(); i++)
    cout << message.at(i);
  cout << endl;

  rotorOperations(message);

  cout << "Performing the decryption: " << endl;
  for (int i = 0; i < message.size(); i++)
    cout << message.at(i);
  cout << endl;




  return 0;
}
