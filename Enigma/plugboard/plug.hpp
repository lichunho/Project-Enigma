#ifndef PLUG_H
#define PLUG_H

#include <iostream>

using namespace std;

class PlugPair {
  private:
    char letterOne;
    char letterTwo;

  public:
    PlugPair();
    PlugPair(char letterA, char letterB);

    /**************************************************************************
    contains
      - Returns true if the pair contains the userInput
      - i.e. to check if the letter is already plugged in
    **************************************************************************/
    bool contains(char input);

    bool validChar(char input);

    /**************************************************************************
    swapChar
      - Perform the swap
    **************************************************************************/
    char swapChar(char input, bool debug = false);

    void printPlug();
};

#endif
