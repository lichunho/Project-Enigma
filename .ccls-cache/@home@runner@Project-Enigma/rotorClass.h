#ifndef rotorClass_H
#define rotorClass_H

#include <iostream>
//#include <string>
using namespace std;

class rotor {

private:
  string rotorWiring;
  string notchPosition;
  char ringSetting;
  char currentPosition;

public:
  /**************************************************************************
  CONSTRUCTOR default
  **************************************************************************/
  rotor() {
    rotorWiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    notchPosition = "Q";
    ringSetting = 'A';
    currentPosition = 'A';
  }

  /**************************************************************************
  CONSTRUCTOR
  **************************************************************************/
  rotor(string rotorWiring, string notchPosition) {
    this -> rotorWiring = rotorWiring;
    this -> notchPosition = notchPosition;
    this -> ringSetting = 'A';
    this -> currentPosition = 'A';
  }

  /**************************************************************************
  setters
  - Set the parimeters of the rotor class
  **************************************************************************/
  void setWiring(string key) { rotorWiring = key; }
  void setNotch(string notch) { notchPosition = notch; }
  void setRing(char ring) { ringSetting = ring; }
  void setPosition(char pos) { currentPosition = pos; }

  /**************************************************************************
  getters
  - Get the parameters of the rotor class
  **************************************************************************/
  string getWiring() { return rotorWiring; }
  string getNotch() { return notchPosition; }
  char getRing() { return ringSetting; }
  char getPosistion() { return currentPosition; }

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
  advanceNext
    - Decides based on the notch whether the next rotor should be incremented
  **************************************************************************/
  bool advanceNext(bool debug = false) {

    bool advanceNext = false;

    if (notchPosition.find(currentPosition) != notchPosition.npos) {
      advanceNext = true;
    }
    
    return advanceNext;
  }

  /**************************************************************************
  encodeChar
  - Handles the first half of the encoding (before reflector)
  **************************************************************************/
  char encodeChar(char input, bool debug = false) {
    int position = 0;
    char output = ' ';
    int rotorOffset = 0;

    rotorOffset = currentPosition - ringSetting;
    position = input - 'A' + rotorOffset;

    if (position >= 26) {
      position -= 26;
    } else if (position < 0) {
      position += 26;
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
    if (output > 'Z') {
      output -= 26;
    }

    if (debug)
      cout << "Character after encode: " << output << endl;

    return output;
  }

  /**************************************************************************
  decodeChar
  - Handles the second half of the encoding (after reflector)
  **************************************************************************/
  char decodeChar(char input, bool debug = false) {
    int position = 0;
    char output = ' ';
    int rotorOffset = 0;
    char offsetChar = ' ';

    rotorOffset = currentPosition - ringSetting;
    offsetChar = input + rotorOffset;

    if (offsetChar > 'Z') {
      offsetChar -= 26;
    } else if (offsetChar < 'A') {
      offsetChar += 26;
    }

    position = rotorWiring.find(offsetChar);
    output = position + 'A' - rotorOffset;

    if (output < 'A') {
      output += 26;
    }
    if (output > 'Z') {
      output -= 26;
    }

    if (debug)
      cout << "Character after decode: " << output << endl;

    return output;
  }

  /**************************************************************************
  printRotor
  - prints out the rotor settings
  **************************************************************************/
  void printRotor() {
    cout << "-------------------------------------------------------" << endl;
    cout << "Printing rotor details" << endl;
    cout << "Rotor wiring: " << rotorWiring << endl;
    cout << "Rotor notch position: " << notchPosition << endl;
    cout << "Ring setting: " << ringSetting << endl;
    cout << "Current position: " << currentPosition << endl;
  }
};
#endif
