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

  for (int i = 0; i < 120; i++) {
    temp = 'A';
    
    if(rotorTwo.rotateNext()){
      rotorOne.shift();
      rotorTwo.shift();
      rotorThree.shift();
    }
    else if(rotorThree.rotateNext()){
      rotorTwo.shift();
      rotorThree.shift();
    }
    else{
      rotorThree.shift();
    }

    /*
    cout << rotorOne.getPosistion(); 
    cout << rotorTwo.getPosistion();
    cout << rotorThree.getPosistion();
    cout << endl;
    */

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
