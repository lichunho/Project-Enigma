#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "plug.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Plugboard {
  private:
    vector<PlugPair> pairs;

  public:
    Plugboard();
    Plugboard(vector<PlugPair> pairs);

    /**************************************************************************
    occupiedLetter
    - Rerurns true if the letter is already used in a pair
    **************************************************************************/
    bool occupiedLetter(char letter);

    /**************************************************************************
    createPair
    - Create a plugboard pair if both letters are available
    **************************************************************************/
    void createPair(char letterA, char letterB);

    /**************************************************************************
    plugboardOperations
    - Perform the plugboard operations
    **************************************************************************/
    char operations(char input);

    int getNumPairs();

    void printPlugboard();
};

#endif
