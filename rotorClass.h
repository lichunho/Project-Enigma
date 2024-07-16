#ifndef rotorClass_H
#define rotorClass_H

#include <iostream>

using namespace std;

class rotor {

private:
  string rotorWiring;
  char notchChar;

public:
  char ringSetting;
  char currentPosition;

  /**************************************************************************
  CONSTRUCTOR default
  - Perform a shift on the rotor
  **************************************************************************/
  rotor() {
    rotorWiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    notchChar = 'Q';
    ringSetting = 'A';
    currentPosition = 'A';
  }

  /**************************************************************************
  CONSTRUCTOR
  - Perform a shift on the rotor
  **************************************************************************/
  rotor(string key, char notch, char ring, char pos) {
    rotorWiring = key;
    notchChar = notch;
    ringSetting = ring;
    currentPosition = pos;
  }

  /**************************************************************************
  getPosition
  - Get the current position of the rotor
  **************************************************************************/
  char getPosistion() { return currentPosition;}

  /**************************************************************************
  shift
    - Increment the rotor by one step and return to 'A' after 'Z'
  **************************************************************************/
  void shift(bool debug = false) {

    currentPosition++;

    if (currentPosition > 'Z') {
      currentPosition = 'A';
    }

    if (debug)
      cout << "Position after rotate: " << currentPosition << endl;
  }

  /**************************************************************************
  rotateNext
    - Decides based on the notch whether the next rotor should be incremented
  **************************************************************************/
  bool rotateNext(bool debug = false){

    bool rotateNext = false;

    if (currentPosition == notchChar) {
      rotateNext = true;
    }
      
    return rotateNext;
  }

  /**************************************************************************
  encodeChar
  - Handles the first half of the encoding (before reflector)
  **************************************************************************/
  char encodeChar(char input, bool debug = false) {
    int position = 0;
    char output = ' ';
    int rotorOffset = 0;

    rotorOffset = currentPosition - 'A';
    position = input - 'A' + rotorOffset;

    if (position >= 26) {
      position -= 26;
    }

    if (debug) {
      cout << "Input: " << input << endl;
      cout << "RotorOffset: " << rotorOffset << endl;
      cout << "Position: " << position << endl;
    }

    output = rotorWiring.at(position) - rotorOffset;

    if (output < 'A') {
      output += 26;
    }

    if (debug)
      cout << "Character after encode: " << output << endl;

    return output;
  }

  /**************************************************************************
  decodeChar
  - Handles the first half of the encoding (before reflector)
  **************************************************************************/
  char decodeChar(char input, bool debug = false) {
    int position = 0;
    char output = ' ';
    int rotorOffset = 0;
    char offsetChar = ' ';

    rotorOffset = currentPosition - 'A';
    offsetChar = input + rotorOffset;

    if (offsetChar > 'Z') {
      offsetChar -= 26;
    }

    position = rotorWiring.find(offsetChar);
    output = position + 'A' - rotorOffset;

    if (output < 'A') {
      output += 26;
    }

    if (debug)
      cout << "Character after decode: " << output << endl;

    return output;
  }
};
#endif
