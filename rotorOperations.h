#ifndef rotorOperations_H
#define rotorOperations_H

#include "rotorClass.h"
#include <fstream>
#include <iostream>

using namespace std;

/**************************************************************************
importRotorDetails
- Receives user selection of the rotors/reflector
- Opens txt file and import the corresponding rotor detials
**************************************************************************/
rotor importRotorDetails(string rotorSelection) {
  ifstream rotorDetails;
  rotorDetails.open("rotorDetails.txt");

  rotor designatedRotor;
  string rotorIndex;
  string rotorWiring;
  char rotorNotchChar;
  string disregardLine;

  while (!rotorDetails.eof()) {
    rotorDetails >> rotorIndex;
    if (rotorIndex == rotorSelection) {
      rotorDetails >> rotorWiring >> rotorNotchChar;
      designatedRotor.setWiring(rotorWiring);
      designatedRotor.setNotch(rotorNotchChar);
    } else {
      getline(rotorDetails, disregardLine);
    }
  }

  rotorDetails.close();

  return designatedRotor;
}

/**************************************************************************
selectRotors
- Update the rotor details into the rotor based on user selection
**************************************************************************/
void selectRotors(rotor rotor[], string selection[]) {

  for (int i = 0; i <= 3; i++) {
    rotor[i] = importRotorDetails(selection[i]);
  }
}

/**************************************************************************
configRingSetting
- Update the ringSettings on rotors based on userInput
**************************************************************************/
void configRingSetting(rotor rotor[], char setting[]) {
  for (int i = 1; i <= 3; i++) {
    rotor[i].setRing(setting[i]);
  }
}

/**************************************************************************
initialPosition
- Update the ringSettings on rotors based on userInput
**************************************************************************/
void initialPosition(rotor rotor[], char position[]) {
  for (int i = 1; i <= 3; i++) {
    rotor[i].setPosition(position[i]);
  }
}

/**************************************************************************
initialPosition
- Update the ringSettings on rotors based on userInput
**************************************************************************/
void initializeRotors(rotor rotor[], string selection[], char setting[],
                      char position[]) {

  selectRotors(rotor, selection);
  configRingSetting(rotor, setting);
  initialPosition(rotor, position);
}

/**************************************************************************
rotorOperations
- Perform the rotor operations
- Rotor 1 to 3 -> reflector -> rotor 3 -> 1
- Incredment the rotors after each operation
**************************************************************************/
char rotorOperations(rotor rotor[], char input, bool debug = false) {
  if (rotor[2].advanceNext()) {
    rotor[1].shift();
    rotor[2].shift();
    rotor[3].shift();
  } else if (rotor[3].advanceNext()) {
    rotor[2].shift();
    rotor[3].shift();
  } else {
    rotor[3].shift();
  }

  input = rotor[3].encodeChar(input);
  input = rotor[2].encodeChar(input);
  input = rotor[1].encodeChar(input);
  input = rotor[0].encodeChar(input);
  input = rotor[1].decodeChar(input);
  input = rotor[2].decodeChar(input);
  input = rotor[3].decodeChar(input);

  return input;
}

#endif
