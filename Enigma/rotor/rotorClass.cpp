#include "rotorClass.hpp"

/**************************************************************************
CONSTRUCTOR default
**************************************************************************/
rotor::rotor() {
  rotorWiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
  notchPosition = "Q";
  ringSetting = 'A';
  currentPosition = 'A';
}

/**************************************************************************
CONSTRUCTOR
**************************************************************************/
rotor::rotor(string rotorWiring, string notchPosition) {
  this -> rotorWiring = rotorWiring;
  this -> notchPosition = notchPosition;
  this -> ringSetting = 'A';
  this -> currentPosition = 'A';
}

/**************************************************************************
setters
- Set the parimeters of the rotor class
**************************************************************************/
void rotor::setWiring(string key) { rotorWiring = key; }
void rotor::setNotch(string notch) { notchPosition = notch; }
void rotor::setRing(char ring) { ringSetting = ring; }
void rotor::setPosition(char pos) { currentPosition = pos; }

/**************************************************************************
getters
- Get the parameters of the rotor class
**************************************************************************/
string rotor::getWiring() { return rotorWiring; }
string rotor::getNotch() { return notchPosition; }
char rotor::getRing() { return ringSetting; }
char rotor::getPosistion() { return currentPosition; }

/**************************************************************************
shift
- Increment the rotor by one step and return to 'A' after 'Z'
**************************************************************************/
void rotor::shift(bool debug) {

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
bool rotor::advanceNext(bool debug) {

  bool advanceNext = false;

  int ringOffset = ringSetting - 'A';
  for (size_t i = 0; i < notchPosition.size(); i++) {
    char notch = notchPosition.at(i);
    char effectiveNotch = notch - ringOffset;
    if (effectiveNotch < 'A') {
      effectiveNotch += 26;
    }
    if (effectiveNotch > 'Z') {
      effectiveNotch -= 26;
    }
    if (effectiveNotch == currentPosition) {
      advanceNext = true;
      break;
    }
  }
  
  return advanceNext;
}

/**************************************************************************
encodeChar
- Handles the first half of the encoding (before reflector)
**************************************************************************/
char rotor::encodeChar(char input, bool debug) {
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
char rotor::decodeChar(char input, bool debug) {
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
void rotor::printRotor() {
  cout << "-------------------------------------------------------" << endl;
  cout << "Printing rotor details" << endl;
  cout << "Rotor wiring: " << rotorWiring << endl;
  cout << "Rotor notch position: " << notchPosition << endl;
  cout << "Ring setting: " << ringSetting << endl;
  cout << "Current position: " << currentPosition << endl;
}
