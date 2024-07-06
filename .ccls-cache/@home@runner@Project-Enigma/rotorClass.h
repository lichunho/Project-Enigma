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

  /*******************************************************************************
  CONSTRUCTOR default
  - Perform a shift on the rotor
  *******************************************************************************/
  rotor() {
    rotorWiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    notchChar = 'Q';
    ringSetting = 'A';
    currentPosition = 'A';
  }

  /*******************************************************************************
  CONSTRUCTOR
  - Perform a shift on the rotor
  *******************************************************************************/
  rotor(string key, char notch, char ring, char pos) {
    rotorWiring = key;
    notchChar = notch;
    ringSetting = ring;
    currentPosition = pos;
  }

  /*******************************************************************************
    rotorShift
    - Roate the rotor and decide whether the next rotor needs to be rotated
  *******************************************************************************/
  bool shift(bool debug = false) {
    bool rotateNext = false;

    if (debug)
      cout << "Position before rotate: " << currentPosition << endl;

    if (currentPosition == notchChar) {
      rotateNext = true;
    }

    if (currentPosition < 'Z')
    {
      currentPosition++;
    }
    else
    {
      currentPosition = 'A';
    }
      

    if (debug)
      cout << "Position after rotate: " << currentPosition << endl;

    return rotateNext;
  }

  /*******************************************************************************
  encodeChar
  - Handles the first half of the encoding (before reflector)
*******************************************************************************/
  char encodeChar(char input, bool debug = true) {
    int position = 0;
    char output = ' ';
    int rotorOffset = 0;

    rotorOffset = currentPosition - 'A';
    position = input - 'A' + rotorOffset;
    output = rotorWiring.at(position) - rotorOffset;

    if(output < 'A')
      {
        output += 26;
      }

    if (debug)
      cout << "Character after encode: " << output << endl;

    return output;
  }

  /*******************************************************************************
    encodeChar
    - Handles the first half of the encoding (before reflector)
  *******************************************************************************/
  char decodeChar(char input, bool debug = false) {
    int position = 0;
    char output = ' ';
    int rotorOffset = 0;
    char offsetChar = ' ';
    
    rotorOffset = currentPosition - 'A';
    offsetChar = input + rotorOffset;
    
    if(offsetChar > 'Z')
    {
      offsetChar -= 26;
    }
    
    position = rotorWiring.find(offsetChar);
    output = position + 'A' - rotorOffset;

    if(output < 'A')
    {
      output += 26;
    }

    if (debug)
      cout << "Character after decode: " << output << endl;

    return output;
  }
};
#endif
