#ifndef plugboardClass_H
#define plugboardClass_H

#include <iostream>

using namespace std;

class plugboard {
private:
  char letterOne;
  char letterTwo;

public:
  plugboard() {
    letterOne = ' ';
    letterTwo = ' ';
  }

  plugboard(char letterA, char letterB) {
    letterOne = letterA;
    letterTwo = letterB;
  }

  /**************************************************************************
  contains
    - Returns true if the pair contains the userInput
    - i.e. to check if the letter is already plugged in
  **************************************************************************/
  bool contains(char input) {
    if (input == letterOne || input == letterTwo) {
      return true;
    } else {
      return false;
    }
  }

  /**************************************************************************
  swapChar
    - Perform the swap
  **************************************************************************/
  char swapChar(char input, bool debug = false) {
    char output = ' ';

    if (input == letterOne) {
      output = letterTwo;
    } else if (input == letterTwo) {
      output = letterOne;
    } else {
      output = input;
    }

    return output;
  }
};

#endif