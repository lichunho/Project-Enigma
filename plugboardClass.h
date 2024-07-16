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