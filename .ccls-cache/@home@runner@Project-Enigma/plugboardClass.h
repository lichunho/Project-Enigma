#ifndef plugboardClass_H
#define plugboardClass_H

#include <iostream>

using namespace std;

class plugboardPair {
private:
  char letterOne;
  char letterTwo;

public:
  plugboardPair() {
    letterOne = ' ';
    letterTwo = ' ';
  }

  plugboardPair(char letterA, char letterB) {
    letterOne = letterA;
    letterTwo = letterB;
  }

  char swapChar(char input, bool debug) {
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