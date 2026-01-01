#ifndef rotorClass_H
#define rotorClass_H

#include <iostream>
#include <string>
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
  rotor();

  /**************************************************************************
  CONSTRUCTOR
  **************************************************************************/
  rotor(string rotorWiring, string notchPosition);

  /**************************************************************************
  setters
  - Set the parimeters of the rotor class
  **************************************************************************/
  void setWiring(string key);
  void setNotch(string notch);
  void setRing(char ring);
  void setPosition(char pos);

  /**************************************************************************
  getters
  - Get the parameters of the rotor class
  **************************************************************************/
  string getWiring();
  string getNotch();
  char getRing();
  char getPosistion();

  /**************************************************************************
  shift
  - Increment the rotor by one step and return to 'A' after 'Z'
  **************************************************************************/
  void shift(bool debug = false);

  /**************************************************************************
  advanceNext
    - Decides based on the notch whether the next rotor should be incremented
  **************************************************************************/
  bool advanceNext(bool debug = false);

  /**************************************************************************
  encodeChar
  - Handles the first half of the encoding (before reflector)
  **************************************************************************/
  char encodeChar(char input, bool debug = false);

  /**************************************************************************
  decodeChar
  - Handles the second half of the encoding (after reflector)
  **************************************************************************/
  char decodeChar(char input, bool debug = false);

  /**************************************************************************
  printRotor
  - prints out the rotor settings
  **************************************************************************/
  void printRotor();
};
#endif
