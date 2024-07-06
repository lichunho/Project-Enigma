#include "rotorClass.h"
#include "rotorOperations.h"
//#include <algorithm>
#include <iostream>
//#include <fstream>
//#include <vector>
using namespace std;

int main() {

  /*

  vector<char> message;
  string userInput;

  cout << "Input the message you would like to be encrypted" << endl;
  cout << "=> ";
  cin >> userInput;

  for (int i = 0; i < userInput.size(); i++) {
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
  */

  rotor rotorOne("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', 'A', 'A');
  rotor rotorTwo("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', 'A', 'A');
  rotor rotorThree("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', 'A', 'A');
  rotor reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT", ' ', 'A', 'A');
  char temp = ' ';

  bool rotateNext = false;

  for (int i = 0; i < 47; i++) {
    temp = 'A';
    rotateNext = rotorThree.shift();
    if(rotateNext)
    {
      rotateNext = rotorTwo.shift();
      if(rotateNext)
      {
        rotateNext = rotorThree.shift();
      }
    }

    temp = rotorThree.encodeChar(temp);
    temp = rotorTwo.encodeChar(temp);
    temp = rotorOne.encodeChar(temp);
    temp = reflector.encodeChar(temp);
    temp = rotorOne.decodeChar(temp);
    temp = rotorTwo.decodeChar(temp);
    temp = rotorThree.decodeChar(temp);

    cout << temp;

    if((i+1)%5 == 0)  cout << " ";
    
  }

  temp = ' ';
  rotateNext = false;

  return 0;
}
