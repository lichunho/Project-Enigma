#include "plug.hpp"

PlugPair::PlugPair()
{
    letterOne = ' ';
    letterTwo = ' ';
}

PlugPair::PlugPair(char letterA, char letterB)
{
    letterOne = letterA;
    letterTwo = letterB;
}

/**************************************************************************
contains
  - Returns true if the pair contains the userInput
  - i.e. to check if the letter is already plugged in
**************************************************************************/
bool PlugPair::contains(char input)
{
    if (input == letterOne || input == letterTwo) {
        return true;
    } else {
        return false;
    }
}

bool PlugPair::validChar(char input)
{
    if (input < 'A' || input > 'Z') {
        return false;
    }

    return true;
}

/**************************************************************************
swapChar
  - Perform the swap
**************************************************************************/
char PlugPair::swapChar(char input, bool debug)
{
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

void PlugPair::printPlug()
{
    cout << "Pair: " << letterOne << " <-> " << letterTwo << endl;
}
